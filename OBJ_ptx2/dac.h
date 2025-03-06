/*
 * dac.h
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#ifndef DAC_H_
#define DAC_H_

// Set the VDAC to max frequency of 1 MHz
#define VDAC_FREQ         1000000

typedef struct{
  unsigned int            ch;
  VDAC_ChPortSel_t        sel;
  GPIO_Port_TypeDef       port;
  unsigned int            pin;
  __IOM uint32_t*         bus;
  uint32_t                alloc;
}DAC_CANNEL_t;

typedef struct{
  VDAC_TypeDef*           vdac;
  CMU_Clock_TypeDef       clock;
  int                     num;
  DAC_CANNEL_t*           channels;
}DAC_t;

#define DAC_VAL(o, r)     (uint32_t)((o * 4095) / r)

void dac_init(const DAC_t* dac_obj);

#endif /* DAC_H_ */
