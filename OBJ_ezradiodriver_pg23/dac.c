/*
 * dac.c
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#include "em_cmu.h"
#include "em_gpio.h"
#include "em_vdac.h"

#include "dac.h"


/**************************************************************************//**
 * @brief
 *    VDAC initialization
 *****************************************************************************/
static void initVDAC(VDAC_TypeDef* vdac, CMU_Clock_TypeDef clock, int num, DAC_CANNEL_t* channels)
{
  VDAC_Init_TypeDef        init        = VDAC_INIT_DEFAULT;
  VDAC_InitChannel_TypeDef initChannel = VDAC_INITCHANNEL_DEFAULT;
  int i;
  DAC_CANNEL_t* p_channels = channels;

  for (i = 0; i < num; i++) {
    *(__IOM uint32_t*)p_channels->bus |= p_channels->alloc;
    GPIO_PinModeSet(channels->port, channels->pin, gpioModeDisabled, 0);
    p_channels++;
  }

  // Use the HFRCOEM23 to clock the VDAC in order to operate in EM3 mode
  CMU_ClockSelectSet(clock, cmuSelect_HFRCOEM23);

  // Enable the HFRCOEM23 and VDAC clocks
  CMU_ClockEnable(cmuClock_HFRCOEM23, true);
  CMU_ClockEnable(clock, true);

  // Calculate the VDAC clock prescaler value resulting in a 1 MHz VDAC clock
  init.prescaler = VDAC_PrescaleCalc(vdac, VDAC_FREQ);

  // Clocking is requested on demand
  init.onDemandClk = false;

  // Customizing for PTX2nd
  init.reference = vdacRefAvdd;
  //init.reference = vdacRef2V5;

  // Disable High Capacitance Load mode
  //initChannel.highCapLoadEnable = false;
  initChannel.highCapLoadEnable = true;

  // Use Low Power mode
  initChannel.powerMode = vdacPowerModeLowPower;
  //initChannel.powerMode = vdacPowerModeHighPower;

  // Initialize the VDAC and VDAC channel
  VDAC_Init(vdac, &init);

  /*
   * Configure for VDACx CHx
   */
  p_channels = channels;

  for (i = 0; i < num; i++) {
      initChannel.port = p_channels->sel;
      initChannel.pin = p_channels->pin;
      initChannel.mainOutEnable = false;
      initChannel.auxOutEnable = true;
      initChannel.shortOutput = false;
      VDAC_InitChannel(vdac, &initChannel, p_channels->ch);
      // Enable the VDAC
      VDAC_Enable(vdac, p_channels->ch, true);
      p_channels++;
  }
}


void dac_init(const DAC_t* dac_obj)
{
  initVDAC(dac_obj->vdac, dac_obj->clock, dac_obj->num, dac_obj->channels);
}
