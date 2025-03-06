/*
 * pwm_driver.h
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#ifndef PWM_H_
#define PWM_H_

//  Desired frequency in Hz
#define PWM_FREQ 1000000

typedef struct{
  TIMER_TypeDef*          timer4vacp;
  CMU_Clock_TypeDef       clock4vacp;
  int                     ldma_ch4vacp;
  LDMA_PeripheralSignal_t ldma_signal4vacp;
  GPIO_Port_TypeDef       port4vacp;
  unsigned int            pin4vacp;
}PWM_t;

void pwm_init(const PWM_t* pwm_obj);
void pwm_set_duty(const PWM_t* pwm_obj, uint32_t duty);

#endif /* PWM_H_ */
