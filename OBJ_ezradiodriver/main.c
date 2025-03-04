/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2012 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 *
 */

#include <string.h>
#include <errno.h>

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "kernel_cfg.h"
#include "em_device.h"
#include "ezradio_cmd.h"
#include "ezradio_api_lib.h"
#include "ezradio_plugin_manager.h"
//#include "ezradio_prop.h"
#include "main.h"

//#define TEST_LDMA

//#ifdef TEST_LDMA
#include "em_cmu.h"
#include "em_emu.h"
#include "em_eusart.h"
//#endif  // TEST_LDMA

//Radio initialization data
EZRADIODRV_HandleData_t appRadioInitData = EZRADIODRV_INIT_DEFAULT;
//Radio handle
EZRADIODRV_Handle_t appRadioHandle = &appRadioInitData;
//Variable to store SPI command reply
ezradio_cmd_reply_t ezradioReply;
//RX packet data
static uint8_t radioRxPkt[EZRADIO_FIFO_SIZE];
//TX packet data
static uint8_t radioTxPkt[EZRADIO_FIFO_SIZE] = RADIO_CONFIGURATION_DATA_CUSTOM_PAYLOAD;
volatile bool txStart = false;
volatile bool unmodCarrierStart = false;
volatile bool unmodCarrierStarted = false;
volatile bool unmodCarrierStop = false;

#define EUS1MOSI_PORT   gpioPortC
#define EUS1MOSI_PIN    1
#define EUS1MISO_PORT   gpioPortC
#define EUS1MISO_PIN    2
#define EUS1SCLK_PORT   gpioPortC
#define EUS1SCLK_PIN    3
#define EUS1CS_PORT     gpioPortC
#define EUS1CS_PIN      0

// LDMA channels for receive and transmit servicing
#define RX_LDMA_CHANNEL 0
#define TX_LDMA_CHANNEL 1

// LDMA descriptor and transfer configuration structures for TX channel
LDMA_Descriptor_t ldmaTXDescriptor;
LDMA_TransferCfg_t ldmaTXConfig;

// LDMA descriptor and transfer configuration structures for RX channel
LDMA_Descriptor_t ldmaRXDescriptor;
LDMA_TransferCfg_t ldmaRXConfig;

// Size of the data buffers
#define BUFLEN  10

// Outgoing data
uint8_t outbuf[BUFLEN];

// Incoming data
uint8_t inbuf[BUFLEN];

// Data reception complete
bool rx_done;


static void appPacketTransmittedCallback(EZRADIODRV_Handle_t handle, Ecode_t status)
{
  (void)handle;
  (void)status;
}

static void appPacketReceivedCallback(EZRADIODRV_Handle_t handle, Ecode_t status)
{
  (void)handle;
  (void)status;
}

/**************************************************************************//**
 * @brief
 *    GPIO initialization
 *****************************************************************************/
void initGPIO(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Configure MOSI (TX) pin as an output
  GPIO_PinModeSet(EUS1MOSI_PORT, EUS1MOSI_PIN, gpioModePushPull, 0);

  // Configure MISO (RX) pin as an input
  GPIO_PinModeSet(EUS1MISO_PORT, EUS1MISO_PIN, gpioModeInput, 0);

  // Configure SCLK pin as an output low (CPOL = 0)
  GPIO_PinModeSet(EUS1SCLK_PORT, EUS1SCLK_PIN, gpioModePushPull, 0);

  // Configure CS pin as an output initially high
  GPIO_PinModeSet(EUS1CS_PORT, EUS1CS_PIN, gpioModePushPull, 1);

  // Configure button 0 pin as an input
  //GPIO_PinModeSet(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, gpioModeInputPull, 1);

  // Interrupt on button 0 rising edge to start transfers
  //GPIO_ExtIntConfig(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, BSP_GPIO_PB0_PIN, true, false, true);

  // Enable NVIC GPIO interrupt
  //NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  //NVIC_EnableIRQ(GPIO_EVEN_IRQn);
}

/**************************************************************************//**
 * @brief
 *    EUSART2 initialization
 *****************************************************************************/
void initEUSART2(void)
{
  CMU_ClockEnable(cmuClock_EUSART2, true);

  // SPI advanced configuration (part of the initializer)
  EUSART_SpiAdvancedInit_TypeDef adv = EUSART_SPI_ADVANCED_INIT_DEFAULT;

  adv.msbFirst = true;        // SPI standard MSB first
  adv.autoInterFrameTime = 7; // 7 bit times of delay between frames
                              // to accommodate non-DMA secondaries

  // Default asynchronous initializer (main/master mode and 8-bit data)
  EUSART_SpiInit_TypeDef init = EUSART_SPI_MASTER_INIT_DEFAULT_HF;

  init.bitRate = 1000000;         // 1 MHz shift clock
  init.advancedSettings = &adv;   // Advanced settings structure

  /*
   * Route EUSART2 MOSI, MISO, and SCLK to the specified pins.  CS is
   * not controlled by EUSART2 so there is no write to the corresponding
   * EUSARTROUTE register to do this.
   */
  GPIO->EUSARTROUTE[2].TXROUTE = (EUS1MOSI_PORT << _GPIO_EUSART_TXROUTE_PORT_SHIFT)
      | (EUS1MOSI_PIN << _GPIO_EUSART_TXROUTE_PIN_SHIFT);
  GPIO->EUSARTROUTE[2].RXROUTE = (EUS1MISO_PORT << _GPIO_EUSART_RXROUTE_PORT_SHIFT)
      | (EUS1MISO_PIN << _GPIO_EUSART_RXROUTE_PIN_SHIFT);
  GPIO->EUSARTROUTE[2].SCLKROUTE = (EUS1SCLK_PORT << _GPIO_EUSART_SCLKROUTE_PORT_SHIFT)
      | (EUS1SCLK_PIN << _GPIO_EUSART_SCLKROUTE_PIN_SHIFT);

  // Enable EUSART interface pins
  GPIO->EUSARTROUTE[2].ROUTEEN = GPIO_EUSART_ROUTEEN_RXPEN |    // MISO
                                 GPIO_EUSART_ROUTEEN_TXPEN |    // MOSI
                                 GPIO_EUSART_ROUTEEN_SCLKPEN;

  // Configure and enable EUSART2
  EUSART_SpiInit(EUSART2, &init);
}

/**************************************************************************//**
 * @brief
 *    LDMA initialization
 *****************************************************************************/
void initLDMA(void)
{
  // First, initialize the LDMA unit itself
  LDMA_Init_t ldmaInit = LDMA_INIT_DEFAULT;
  LDMA_Init(&ldmaInit);

  // Source is outbuf, destination is EUSART2_TXDATA, and length if BUFLEN
  //ldmaTXDescriptor = (LDMA_Descriptor_t)LDMA_DESCRIPTOR_SINGLE_M2P_BYTE(outbuf, &(EUSART2->TXDATA), BUFLEN);
  ldmaTXDescriptor = (LDMA_Descriptor_t)LDMA_DESCRIPTOR_SINGLE_M2P_BYTE(outbuf, &(USART0->TXDATA), BUFLEN);

  // Transfer a byte on free space in the EUSART FIFO
  //ldmaTXConfig = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(ldmaPeripheralSignal_EUSART2_TXFL);
  //ldmaTXConfig = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(dmadrvPeripheralSignal_EUSART2_TXBL);
  ldmaTXConfig = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(dmadrvPeripheralSignal_USART0_TXBL);

  // Source is EUSART2_RXDATA, destination is inbuf, and length if BUFLEN
  //ldmaRXDescriptor = (LDMA_Descriptor_t)LDMA_DESCRIPTOR_SINGLE_P2M_BYTE(&(EUSART2->RXDATA), inbuf, BUFLEN);
  ldmaRXDescriptor = (LDMA_Descriptor_t)LDMA_DESCRIPTOR_SINGLE_P2M_BYTE(&(USART0->RXDATA), inbuf, BUFLEN);

  // Transfer a byte on receive FIFO level event
  //ldmaRXConfig = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(ldmaPeripheralSignal_EUSART2_RXFL);
  //ldmaRXConfig = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(dmadrvPeripheralSignal_EUSART2_RXDATAV);
  ldmaRXConfig = (LDMA_TransferCfg_t)LDMA_TRANSFER_CFG_PERIPHERAL(dmadrvPeripheralSignal_USART0_RXDATAV);
}

#ifdef TEST_LDMA
/**************************************************************************//**
 * @brief LDMA IRQHandler
 *****************************************************************************/
//void LDMA_IRQHandler()
void ldma_handler(void)
{
  uint32_t flags = LDMA_IntGet();

  // Clear the transmit channel's done flag if set
  if (flags & (1 << TX_LDMA_CHANNEL))
    LDMA_IntClear(1 << TX_LDMA_CHANNEL);

  /*
   * Clear the receive channel's done flag if set and change receive
   * state to done.
   */
  if (flags & (1 << RX_LDMA_CHANNEL))
  {
    LDMA_IntClear(1 << RX_LDMA_CHANNEL);
    rx_done = true;
  }

  // Stop in case there was an error
  if (flags & LDMA_IF_ERROR)
    __BKPT(0);
}
#endif  // TEST_LDMA

void timer0_handler(void)
{
  TIMER0_IRQHandler();
}

void gpio_odd_handler(void)
{
  GPIO_ODD_IRQHandler();
}

void gpio_even_handler(void)
{
  GPIO_EVEN_IRQHandler();
}

#ifdef TEST_LDMA
  //
#else // TEST_LDMA
void ldma_handler(void)
{
  LDMA_IRQHandler();
}
#endif  // TEST_LDMA

void rtc_handler(void)
{
  //i_begin_int(INTNO_RTC);
  //i_end_int(INTNO_RTC);
}

/*
 *  ���C���^�X�N
 */
void main_task(intptr_t exinf)
{
  int i;

  ena_int(INTNO_GPIO_EVEN);
  ena_int(INTNO_LDMA);
  //ena_int(INTNO_RTC);
  ena_int(INTNO_TIMER0);

#ifdef TEST_LDMA
  initGPIO();
  //initEUSART2();
  initLDMA();
#endif  // TEST_LDMA

  appRadioInitData.packetTx.userCallback = &appPacketTransmittedCallback;
  appRadioInitData.packetRx.userCallback = &appPacketReceivedCallback;
  appRadioInitData.packetRx.pktBuf = radioRxPkt;

#ifdef TEST_LDMA
  //
#else // TEST_LDMA
  //Initializing Si4x6x
  ezradioInit(appRadioHandle);

  ezradio_part_info(&ezradioReply);

  ezradioResetTRxFifo();

  EZRADIODRV_PacketLengthConfig_t pktLengthConf = { ezradiodrvTransmitLenghtDefault, 16, {16,0,0,0,0} };
  ezradioLengthConfig(appRadioHandle, pktLengthConf);

  //Start RX
  ezradioStartRx(appRadioHandle);
#endif  // TEST_LDMA

  while (1) {
      syslog(LOG_NOTICE, "main_task is running.");

#ifdef TEST_LDMA
    // Set the receive state to not done
    rx_done = false;

    // Zero incoming buffer and populate outgoing data array
    for (i = 0; i < BUFLEN; i++)
    {
      inbuf[i] = 0;
      outbuf[i] = (uint8_t)i;
    }

    GPIO_PinOutClear(EUS1CS_PORT, EUS1CS_PIN);

    //dly_tsk(1);

    /*
    for (i = 0; i < BUFLEN; i++)
      inbuf[i] = EUSART_Spi_TxRx(EUSART2, outbuf[i]);
    */

    // Start both channels
    LDMA_StartTransfer(RX_LDMA_CHANNEL, &ldmaRXConfig, &ldmaRXDescriptor);
    LDMA_StartTransfer(TX_LDMA_CHANNEL, &ldmaTXConfig, &ldmaTXDescriptor);
    // Wait in EM1 until all data is received
    while (!rx_done) {
        dly_tsk(1);
//      EMU_EnterEM1();
    }

    // De-assert chip select upon final byte reception (drive high)
    //dly_tsk(1);

    GPIO_PinOutSet(EUS1CS_PORT, EUS1CS_PIN);

    dly_tsk(1000);
#else // TEST_LDMA

    ezradioStartUnmodulatedCarrier(appRadioHandle);
    dly_tsk(4000 - 2000);
    ezradioStopUnmodulatedCarrier();
    dly_tsk(2000);

#endif  // TEST_LDMA
  }
}
