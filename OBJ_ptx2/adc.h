/*
 * adc.c
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#ifndef ADC_H_
#define ADC_H_

// How many samples to capture
#define ADC_NUM_SAMPLES     32

typedef struct{
  IADC_PosInput_t         pos;
  __IOM uint32_t*         bus;
  uint32_t                alloc;
}ADC_ENTRY_t;

typedef struct{
  IADC_TypeDef*           iadc;
  CMU_Clock_TypeDef       clock;
  int                     ldma_ch;
  LDMA_PeripheralSignal_t ldma_signal;
  int                     num;
  ADC_ENTRY_t*            entries;
  uint32_t*               buffer;
}ADC_t;

void adc_init(const ADC_t* pwm_obj);
void adc_start_scan(const ADC_t* adc_obj);

#endif /* ADC_H_ */
