/*
 * adc.c
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#include "em_cmu.h"
#include "em_gpio.h"
#include "em_iadc.h"
#include "em_ldma.h"

#include "adc.h"


// Set CLK_ADC to 10 MHz
#define CLK_SRC_ADC_FREQ    20000000  // CLK_SRC_ADC
#define CLK_ADC_FREQ        10000000  // CLK_ADC - 10 MHz max in normal mode

/*
 * Specify the IADC input using the IADC_PosInput_t typedef.  This
 * must be paired with a corresponding macro definition that allocates
 * the corresponding ABUS to the IADC.  These are...
 *
 * GPIO->ABUSALLOC |= GPIO_ABUSALLOC_AEVEN0_ADC0
 * GPIO->ABUSALLOC |= GPIO_ABUSALLOC_AODD0_ADC0
 * GPIO->BBUSALLOC |= GPIO_BBUSALLOC_BEVEN0_ADC0
 * GPIO->BBUSALLOC |= GPIO_BBUSALLOC_BODD0_ADC0
 * GPIO->CDBUSALLOC |= GPIO_CDBUSALLOC_CDEVEN0_ADC0
 * GPIO->CDBUSALLOC |= GPIO_CDBUSALLOC_CDODD0_ADC0
 *
 * ...for port A, port B, and port C/D pins, even and odd, respectively.
 */

/*
 * This example enters EM2 in the main while() loop. Setting this
 * #define to 1 enables debug connectivity in EM2, which increases
 * current consumption by about 0.5 uA.
 */
#define EM2DEBUG                  1


/*******************************************************************************
 ***************************   GLOBAL VARIABLES   *******************************
 ******************************************************************************/

/// Globally declared LDMA link descriptor
LDMA_Descriptor_t descriptor[LDMA_CH_NUM];


/**************************************************************************//**
 * @brief  IADC initialization
 *****************************************************************************/
static void initIADC(IADC_TypeDef* iadc, CMU_Clock_TypeDef clock, int num, ADC_ENTRY_t* entries)
{
  // Declare initialization structures
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitScan_t initScan = IADC_INITSCAN_DEFAULT;
  int i;
  ADC_ENTRY_t* p_entries = entries;

  // Scan table structure
  IADC_ScanTable_t scanTable = IADC_SCANTABLE_DEFAULT;

  CMU_ClockEnable(clock, true);

  // Use the FSRC0 as the IADC clock so it can run in EM2
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);

  // Shutdown between conversions to reduce current
  init.warmup = iadcWarmupNormal;

  // Set the HFSCLK prescale value here
  init.srcClkPrescale = IADC_calcSrcClkPrescale(iadc, CLK_SRC_ADC_FREQ, 0);

  /*
   * Configuration 0 is used by both scan and single conversions by
   * default.  Use internal bandgap as the reference and specify the
   * reference voltage in mV.
   *
   * Resolution is not configurable directly but is based on the
   * selected oversampling ratio (osrHighSpeed), which defaults to
   * 2x and generates 12-bit results.
   */
  //initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2;
  //initAllConfigs.configs[0].vRef = 1210;
  initAllConfigs.configs[0].reference = iadcCfgReferenceVddx;
  initAllConfigs.configs[0].vRef = 3300;
  initAllConfigs.configs[0].osrHighSpeed = iadcCfgOsrHighSpeed2x;
  //initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain0P5x;
  initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain1x;

  /*
   * CLK_SRC_ADC must be prescaled by some value greater than 1 to
   * derive the intended CLK_ADC frequency.
   *
   * Based on the default 2x oversampling rate (OSRHS)...
   *
   * conversion time = ((4 * OSRHS) + 2) / fCLK_ADC
   *
   * ...which results in a maximum sampling rate of 833 ksps with the
   * 2-clock input multiplexer switching time is included.
   */
  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(iadc,
                                                                     CLK_ADC_FREQ,
                                                                     0,
                                                                     iadcCfgModeNormal,
                                                                     init.srcClkPrescale);

  /*
   * Trigger continuously once scan is started.  Note that
   * initScan.start = false by default, so conversions must be started
   * manually with IADC_command(IADC0, iadcCmdStartScan).
   *
   * Set the SCANFIFODVL flag when scan FIFO holds 2 entries.  In this
   * example, the interrupt associated with the SCANFIFODVL flag in
   * the IADC_IF register is not used.
   *
   * Enable DMA wake-up to save the results when the specified FIFO
   * level is hit.
   */
  initScan.triggerAction = iadcTriggerActionContinuous;
  initScan.dataValidLevel = iadcFifoCfgDvl2;
  initScan.fifoDmaWakeup = true;

  /*
   * Configure entries in the scan table.  CH0 is single-ended from
   * input 0; CH1 is single-ended from input 1.
   */
  for (i = 0; i < num; i++) {
    scanTable.entries[i].posInput = p_entries->pos;
    scanTable.entries[i].negInput = iadcNegInputGnd;
    scanTable.entries[i].includeInScan = true;
    p_entries++;
  }

  // Initialize IADC
  IADC_init(iadc, &init, &initAllConfigs);

  // Initialize scan
  IADC_initScan(iadc, &initScan, &scanTable);

  // Allocate the analog bus for ADC0 inputs
  p_entries = entries;
  for (i = 0; i < num; i++) {
    *(__IOM uint32_t*)p_entries->bus |= p_entries->alloc;
    p_entries++;
  }
}


/**************************************************************************//**
 * @brief
 *   LDMA initialization
 *
 * @param[in] buffer
 *   pointer to the array where ADC results will be stored.
 * @param[in] size
 *   size of the array
 *****************************************************************************/
static void initLDMA
(int ch, LDMA_PeripheralSignal_t signal, IADC_TypeDef* iadc, uint32_t *buffer,
 uint32_t size)
{
  // Declare LDMA init structs
  LDMA_Init_t init = LDMA_INIT_DEFAULT;

  // Initialize LDMA with default configuration
  LDMA_Init(&init);

  // Trigger LDMA transfer on IADC scan completion
  LDMA_TransferCfg_t transferCfg =
    LDMA_TRANSFER_CFG_PERIPHERAL(signal);

  /*
   * Set up a linked descriptor to save scan results to the
   * user-specified buffer.  By linking the descriptor to itself
   * (the last argument is the relative jump in terms of the number of
   * descriptors), transfers will run continuously until firmware
   * otherwise stops them.
   */
  descriptor[ch] =
    (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_P2M_WORD(&(iadc->SCANFIFODATA), buffer, size, 0);

  /*
   * Start the transfer.  The LDMA request and interrupt after saving
   * the specified number of IADC conversion results.
   */
  LDMA_StartTransfer(ch, (void*)&transferCfg, (void*)&descriptor[ch]);
}


void adc_init(const ADC_t* adc_obj)
{
  initIADC(adc_obj->iadc, adc_obj->clock, adc_obj->num, adc_obj->entries);

#ifdef EM2DEBUG
#if (EM2DEBUG == 1)
  // Enable debug connectivity in EM2
  EMU->CTRL_SET = EMU_CTRL_EM2DBGEN;
#endif
#endif

  initLDMA(
      adc_obj->ldma_ch,
      adc_obj->ldma_signal,
      adc_obj->iadc,
      adc_obj->buffer,
      (uint32_t)(adc_obj->num * ADC_NUM_SAMPLES)
  );
}


void adc_start_scan(const ADC_t* adc_obj)
{
  IADC_command(adc_obj->iadc, iadcCmdStartScan);
}
