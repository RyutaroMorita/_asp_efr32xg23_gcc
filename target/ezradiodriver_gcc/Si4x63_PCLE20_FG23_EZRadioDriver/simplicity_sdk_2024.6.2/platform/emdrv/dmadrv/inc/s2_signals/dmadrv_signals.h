#ifndef __SILICON_LABS_DMADRV_SIGNALS_S2_H__
#define __SILICON_LABS_DMADRV_SIGNALS_S2_H__

#include "em_device.h"
#include "ecode.h"
#include "sl_enum.h"
#include "em_ldma.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup dmadrv
 * @{
 ******************************************************************************/

#if defined(LDMAXBAR_COUNT) && (LDMAXBAR_COUNT > 0)

/// Maximum length of one DMA transfer.
#define DMADRV_MAX_XFER_COUNT ((int)((_LDMA_CH_CTRL_XFERCNT_MASK >> _LDMA_CH_CTRL_XFERCNT_SHIFT) + 1))

/// Peripherals that can trigger LDMA transfers.
SL_ENUM_GENERIC(DMADRV_PeripheralSignal_t, uint32_t) {
  dmadrvPeripheralSignal_NONE = LDMAXBAR_CH_REQSEL_SOURCESEL_NONE,                                                          ///< No peripheral selected for DMA triggering.
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0CC0
  dmadrvPeripheralSignal_TIMER0_CC0 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0CC0 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0CC1
  dmadrvPeripheralSignal_TIMER0_CC1 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0CC1 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0CC2
  dmadrvPeripheralSignal_TIMER0_CC2 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0CC2 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0UFOF
  dmadrvPeripheralSignal_TIMER0_UFOF = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER0UFOF | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1CC0
  dmadrvPeripheralSignal_TIMER1_CC0 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1CC0 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1CC1
  dmadrvPeripheralSignal_TIMER1_CC1 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1CC1 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1CC2
  dmadrvPeripheralSignal_TIMER1_CC2 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1CC2 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1UFOF
  dmadrvPeripheralSignal_TIMER1_UFOF = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER1UFOF | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART0RXDATAV
  dmadrvPeripheralSignal_USART0_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_USART0RXDATAV | LDMAXBAR_CH_REQSEL_SOURCESEL_USART0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART0RXDATAVRIGHT
  dmadrvPeripheralSignal_USART0_RXDATAVRIGHT = LDMAXBAR_CH_REQSEL_SIGSEL_USART0RXDATAVRIGHT | LDMAXBAR_CH_REQSEL_SOURCESEL_USART0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXBL
  dmadrvPeripheralSignal_USART0_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXBL | LDMAXBAR_CH_REQSEL_SOURCESEL_USART0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXBLRIGHT
  dmadrvPeripheralSignal_USART0_TXBLRIGHT = LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXBLRIGHT | LDMAXBAR_CH_REQSEL_SOURCESEL_USART0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXEMPTY
  dmadrvPeripheralSignal_USART0_TXEMPTY = LDMAXBAR_CH_REQSEL_SIGSEL_USART0TXEMPTY | LDMAXBAR_CH_REQSEL_SOURCESEL_USART0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART1RXDATAV
  dmadrvPeripheralSignal_USART1_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_USART1RXDATAV | LDMAXBAR_CH_REQSEL_SOURCESEL_USART1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART1RXDATAVRIGHT
  dmadrvPeripheralSignal_USART1_RXDATAVRIGHT = LDMAXBAR_CH_REQSEL_SIGSEL_USART1RXDATAVRIGHT | LDMAXBAR_CH_REQSEL_SOURCESEL_USART1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXBL
  dmadrvPeripheralSignal_USART1_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXBL | LDMAXBAR_CH_REQSEL_SOURCESEL_USART1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXBLRIGHT
  dmadrvPeripheralSignal_USART1_TXBLRIGHT = LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXBLRIGHT | LDMAXBAR_CH_REQSEL_SOURCESEL_USART1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXEMPTY
  dmadrvPeripheralSignal_USART1_TXEMPTY = LDMAXBAR_CH_REQSEL_SIGSEL_USART1TXEMPTY | LDMAXBAR_CH_REQSEL_SOURCESEL_USART1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART2RXDATAV
  dmadrvPeripheralSignal_USART2_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_USART2RXDATAV | LDMAXBAR_CH_REQSEL_SOURCESEL_USART2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART2RXDATAVRIGHT
  dmadrvPeripheralSignal_USART2_RXDATAVRIGHT = LDMAXBAR_CH_REQSEL_SIGSEL_USART2RXDATAVRIGHT | LDMAXBAR_CH_REQSEL_SOURCESEL_USART2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART2TXBL
  dmadrvPeripheralSignal_USART2_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_USART2TXBL | LDMAXBAR_CH_REQSEL_SOURCESEL_USART2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART2TXBLRIGHT
  dmadrvPeripheralSignal_USART2_TXBLRIGHT = LDMAXBAR_CH_REQSEL_SIGSEL_USART2TXBLRIGHT | LDMAXBAR_CH_REQSEL_SOURCESEL_USART2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_USART2TXEMPTY
  dmadrvPeripheralSignal_USART2_TXEMPTY = LDMAXBAR_CH_REQSEL_SIGSEL_USART2TXEMPTY | LDMAXBAR_CH_REQSEL_SOURCESEL_USART2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_I2C0RXDATAV
  dmadrvPeripheralSignal_I2C0_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_I2C0RXDATAV | LDMAXBAR_CH_REQSEL_SOURCESEL_I2C0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_I2C0TXBL
  dmadrvPeripheralSignal_I2C0_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_I2C0TXBL | LDMAXBAR_CH_REQSEL_SOURCESEL_I2C0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_I2C1RXDATAV
  dmadrvPeripheralSignal_I2C1_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_I2C1RXDATAV | LDMAXBAR_CH_REQSEL_SOURCESEL_I2C1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_I2C1TXBL
  dmadrvPeripheralSignal_I2C1_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_I2C1TXBL | LDMAXBAR_CH_REQSEL_SOURCESEL_I2C1,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_AGCRSSI
  dmadrvPeripheralSignal_AGC_RSSI = LDMAXBAR_CH_REQSEL_SIGSEL_AGCRSSI | LDMAXBAR_CH_REQSEL_SOURCESEL_AGC,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERBOF
  dmadrvPeripheralSignal_PROTIMER_BOF = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERBOF | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC0
  dmadrvPeripheralSignal_PROTIMER_CC0 = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC0 | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC1
  dmadrvPeripheralSignal_PROTIMER_CC1 = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC1 | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC2
  dmadrvPeripheralSignal_PROTIMER_CC2 = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC2 | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC3
  dmadrvPeripheralSignal_PROTIMER_CC3 = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC3 | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC4
  dmadrvPeripheralSignal_PROTIMER_CC4 = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERCC4 | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERPOF
  dmadrvPeripheralSignal_PROTIMER_POF = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERPOF | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERWOF
  dmadrvPeripheralSignal_PROTIMER_WOF = LDMAXBAR_CH_REQSEL_SIGSEL_PROTIMERWOF | LDMAXBAR_CH_REQSEL_SOURCESEL_PROTIMER,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_MODEMDEBUG
  dmadrvPeripheralSignal_MODEM_DEBUG = LDMAXBAR_CH_REQSEL_SIGSEL_MODEMDEBUG | LDMAXBAR_CH_REQSEL_SOURCESEL_MODEM,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_IADC0IADC_SCAN
  dmadrvPeripheralSignal_IADC0_IADC_SCAN = LDMAXBAR_CH_REQSEL_SIGSEL_IADC0IADC_SCAN | LDMAXBAR_CH_REQSEL_SOURCESEL_IADC0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_IADC0IADC_SINGLE
  dmadrvPeripheralSignal_IADC0_IADC_SINGLE = LDMAXBAR_CH_REQSEL_SIGSEL_IADC0IADC_SINGLE | LDMAXBAR_CH_REQSEL_SOURCESEL_IADC0,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_IMEMWDATA
  dmadrvPeripheralSignal_IMEM_WDATA = LDMAXBAR_CH_REQSEL_SIGSEL_IMEMWDATA | LDMAXBAR_CH_REQSEL_SOURCESEL_IMEM,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2CC0
  dmadrvPeripheralSignal_TIMER2_CC0 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2CC0 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2CC1
  dmadrvPeripheralSignal_TIMER2_CC1 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2CC1 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2CC2
  dmadrvPeripheralSignal_TIMER2_CC2 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2CC2 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2UFOF
  dmadrvPeripheralSignal_TIMER2_UFOF = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER2UFOF | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER2,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3CC0
  dmadrvPeripheralSignal_TIMER3_CC0 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3CC0 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER3,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3CC1
  dmadrvPeripheralSignal_TIMER3_CC1 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3CC1 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER3,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3CC2
  dmadrvPeripheralSignal_TIMER3_CC2 = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3CC2 | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER3,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3UFOF
  dmadrvPeripheralSignal_TIMER3_UFOF = LDMAXBAR_CH_REQSEL_SIGSEL_TIMER3UFOF | LDMAXBAR_CH_REQSEL_SOURCESEL_TIMER3,
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUART0TXFL
  dmadrvPeripheralSignal_EUART0_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_EUART0TXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUART0,             ///< Trig on EUART0_TXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUART0RXFL
  dmadrvPeripheralSignal_EUART0_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_EUART0RXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUART0,          ///< Trig on EUART0_RXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART0TXFL
  dmadrvPeripheralSignal_EUSART0_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART0TXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART0,          ///< Trig on EUART0_TXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART0RXFL
  dmadrvPeripheralSignal_EUSART0_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART0RXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART0,       ///< Trig on EUART0_RXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART1TXFL
  dmadrvPeripheralSignal_EUSART1_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART1TXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART1,          ///< Trig on EUART1_TXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART1RXFL
  dmadrvPeripheralSignal_EUSART1_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART1RXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART1,       ///< Trig on EUART1_RXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART2TXFL
  dmadrvPeripheralSignal_EUSART2_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART2TXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART2,          ///< Trig on EUART2_TXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART2RXFL
  dmadrvPeripheralSignal_EUSART2_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART2RXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART2,       ///< Trig on EUART2_RXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART3TXFL
  dmadrvPeripheralSignal_EUSART3_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART3TXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART3,          ///< Trig on EUART2_TXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART3RXFL
  dmadrvPeripheralSignal_EUSART3_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART3RXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART3,       ///< Trig on EUART3_RXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART4TXFL
  dmadrvPeripheralSignal_EUSART4_TXBL = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART4TXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART4,          ///< Trig on EUART4_TXBL.
  #endif
  #if defined LDMAXBAR_CH_REQSEL_SIGSEL_EUSART4RXFL
  dmadrvPeripheralSignal_EUSART4_RXDATAV = LDMAXBAR_CH_REQSEL_SIGSEL_EUSART4RXFL | LDMAXBAR_CH_REQSEL_SOURCESEL_EUSART4,       ///< Trig on EUART4_RXBL.
  #endif
};

/// Data size of one LDMA transfer item.
SL_ENUM(DMADRV_DataSize_t) {
  dmadrvDataSize1 = ldmaCtrlSizeByte, ///< Byte
  dmadrvDataSize2 = ldmaCtrlSizeHalf, ///< Halfword
  dmadrvDataSize4 = ldmaCtrlSizeWord  ///< Word
};

#endif /* defined( LDMAXBAR_COUNT ) && ( LDMAXBAR_COUNT == 1 ) */

/** @} (end addtogroup dmadrv) */

#ifdef __cplusplus
}
#endif

#endif /* __SILICON_LABS_DMADRV_SIGNALS_S2_H__ */
