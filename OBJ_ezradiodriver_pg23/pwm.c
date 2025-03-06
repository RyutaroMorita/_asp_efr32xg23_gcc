/*
 * pwm.c
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#include "em_cmu.h"
#include "em_ldma.h"
#include "em_timer.h"

#include "pwm.h"


/*
 * This table holds the time calculated for each given duty cycle value
 * expressed as a percent.  Note that BUFFER_SIZE must match the number
 * of values in dutyCyclePercentages[BUFFER_SIZE].
 */
#define BUFFER_SIZE 1
static uint32_t source[LDMA_CH_NUM];

// Globally declared link descriptor
static LDMA_Descriptor_t descLink[LDMA_CH_NUM];


/**************************************************************************//**
 * @brief
 *    TIMER initialization
 *****************************************************************************/
static void initTIMER
(TIMER_TypeDef *timer, CMU_Clock_TypeDef clock, GPIO_Port_TypeDef port, unsigned int pin)
{
  uint32_t timerFreq, topValue;
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
  unsigned int index;

  // Don't start counter on initialization
  timerInit.enable = false;

  // PWM mode sets/clears the output on compare/overflow events
  timerCCInit.mode = timerCCModePWM;

  TIMER_Init(timer, &timerInit);

  if (timer == TIMER0)
    index = 0;
  else
  if (timer == TIMER1)
    index = 1;
  else
  if (timer == TIMER2)
    index = 2;
  else
  if (timer == TIMER3)
    index = 3;
  else
    index = 4;

  GPIO->TIMERROUTE[index].ROUTEEN  = GPIO_TIMER_ROUTEEN_CC0PEN;
  GPIO->TIMERROUTE[index].CC0ROUTE = (port << _GPIO_TIMER_CC0ROUTE_PORT_SHIFT)
                    | (pin << _GPIO_TIMER_CC0ROUTE_PIN_SHIFT);

  TIMER_InitCC(timer, 0, &timerCCInit);

  // Set top value to overflow at the desired PWM_FREQ frequency
  timerFreq = CMU_ClockFreqGet(clock) / (timerInit.prescale + 1);
  topValue = (timerFreq / PWM_FREQ);
  TIMER_TopSet(timer, topValue);

  // Now start the TIMER
  TIMER_Enable(timer, true);
}


/**************************************************************************//**
 * @brief
 *    Populate buffer with calculated duty cycle time values
 *****************************************************************************/
static uint32_t populateBuffer(TIMER_TypeDef *timer, uint32_t duty)
{
  return (TIMER_TopGet(timer) * duty) / 100;
}


/**************************************************************************//**
* @brief
*    Initialize the LDMA module
*
* @details
*    Configure the channel descriptor to use the default peripheral to
*    memory transfer descriptor. Modify it to not generate an interrupt
*    upon transfer completion (we don't need it). Additionally, the transfer
*    configuration selects the TIMER0_CC0 signal as the trigger for the LDMA
*    transaction to occur.
*
* @note
*    The descriptor object needs to at least have static scope persistence so
*    that the reference to the object is valid beyond its first use in
*    initialization
*****************************************************************************/
static void initLDMA(int ch, LDMA_PeripheralSignal_t signal, TIMER_TypeDef *timer)
{
  // Default LDMA initialization
  LDMA_Init_t init = LDMA_INIT_DEFAULT;
  LDMA_Init(&init);

  // Request transfers on CC0 peripheral requests
  LDMA_TransferCfg_t periTransferTx =
          LDMA_TRANSFER_CFG_PERIPHERAL(signal);

  // Transfer from the RAM buffer to CC0 output register in a continuous loop
  LDMA_Descriptor_t xfer =
    LDMA_DESCRIPTOR_LINKREL_M2P_BYTE(&source[ch],         // Memory source address
                                     &timer->CC[0].OCB,   // Output compare buffer register
                                     BUFFER_SIZE,         // Number of transfers to make
                                     0);                  // Link to same descriptor

  // Store descriptor globally
  descLink[ch] = xfer;

  // Transfer one word per request
  descLink[ch].xfer.size = ldmaCtrlSizeWord;

  // Do not ignore single requests.  Transfer data on every request.
  descLink[ch].xfer.ignoreSrec = 0;

  // Do not request an interrupt on completion of all transfers
  descLink[ch].xfer.doneIfs  = 0;

  // Start transfer, LDMA will trigger after first compare event
  LDMA_StartTransfer(ch, (void*)&periTransferTx, (void*)&descLink[ch]);
}


void pwm_init(const PWM_t* pwm_obj)
{
  CMU_ClockEnable(pwm_obj->clock4vacp, true);

  GPIO_PinModeSet(pwm_obj->port4vacp, pwm_obj->pin4vacp, gpioModePushPull, 0);

  initTIMER(
      pwm_obj->timer4vacp,
      pwm_obj->clock4vacp,
      pwm_obj->port4vacp,
      pwm_obj->pin4vacp
  );
}


void pwm_set_duty(const PWM_t* pwm_obj, uint32_t duty)
{
  // Initialize DMA only after buffer is populated
  source[pwm_obj->ldma_ch4vacp] = populateBuffer(pwm_obj->timer4vacp, duty);
  initLDMA(
      pwm_obj->ldma_ch4vacp,
      pwm_obj->ldma_signal4vacp,
      pwm_obj->timer4vacp
  );
}
