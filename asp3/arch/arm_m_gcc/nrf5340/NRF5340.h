/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2007,2011,2015 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 */

#ifndef TOPPERS_NRF5340_H
#define TOPPERS_NRF5340_H

#define NRF5340_FICR_BASE 0x00FF0000

#define NRF5340_FICR_XOSC32MTRIM (uint32_t *)(NRF5340_FICR_BASE + 0xC20)

#define NRF5340_FICR_XOSC32MTRIM_SLOPE_MASK  0x3E0
#define NRF5340_FICR_XOSC32MTRIM_SLOPE_POS   5
#define NRF5340_FICR_XOSC32MTRIM_OFFSET_MASK 0x1F
#define NRF5340_FICR_XOSC32MTRIM_OFFSET_POS  0

#define NRF5340_UICR_BASE            0x00FF8000
#define NRF5340_UICR_APPROTECT       (uint32_t *)(NRF5340_UICR_BASE + 0x000)
#define NRF5340_UICR_SECUREAPPROTECT (uint32_t *)(NRF5340_UICR_BASE + 0x01C)

#define NRF5340_CACHE_BASE 0x50001000

#define NRF5340_CACHE_ENABLE (uint32_t *)(NRF5340_CACHE_BASE + 0x500)
#define NRF5340_CACHE_MODE   (uint32_t *)(NRF5340_CACHE_BASE + 0x514)

#define NRF5340_CACHE_MODE_CACHE 0

#define NRF5340_REGULATORS_BASE 0x50004000

#define NRF5340_REGULATORS_VREGMAIN_DCDCEN (uint32_t *)((NRF5340_REGULATORS_BASE) + 0x704)
#define NRF5340_REGULATORS_VREGH_DCDCEN    (uint32_t *)((NRF5340_REGULATORS_BASE) + 0xB00)

#define NRF5340_CLOCK_BASE 0x50005000

#define NRF5340_CLOCK_TASKS_HFCLKSTART (uint32_t *)(NRF5340_CLOCK_BASE + 0x000)
#define NRF5340_CLOCK_HFCLKSRC         (uint32_t *)(NRF5340_CLOCK_BASE + 0x45C)
#define NRF5340_CLOCK_HFCLKCTRL        (uint32_t *)(NRF5340_CLOCK_BASE + 0x558)

#define NRF5340_CLOCK_HFCLKSRC_HFXO   (1 << 0)
#define NRF5340_CLOCK_HFCLKCTRL_DIV_1 0

#define NRF5340_OSCILLATORS_BASE 0x50004000

#define NRF5340_OSCILLATORS_XOSC32MCAPS (uint32_t *)(NRF5340_OSCILLATORS_BASE + 0x5C4)

#define NRF5340_OSCILLATORS_XOSC32MCAPS_CAPVALUE(v) ((v) << 0)
#define NRF5340_OSCILLATORS_XOSC32MCAPS_ENABLE      (1 << 8)

#define NRF5340_SPU_BASE 0x50003000
#define NRF5340_SPU_EXTDOMAIN_PERM      (uint32_t *)(NRF5340_SPU_BASE + 0x440)
#define NRF5340_SPU_DPPI_PERM           (uint32_t *)(NRF5340_SPU_BASE + 0x480)
#define NRF5340_SPU_GPIOPORT(n)         (uint32_t *)(NRF5340_SPU_BASE + 0x4C0 + (n) * 0x8)
#define NRF5340_SPU_FLASHNSC_REGION(n)  (uint32_t *)(NRF5340_SPU_BASE + 0x500 + (n) * 0x8)
#define NRF5340_SPU_FLASHNSC_SIZE(n)    (uint32_t *)(NRF5340_SPU_BASE + 0x504 + (n) * 0x8)
#define NRF5340_SPU_FLASHREGION_PERM(n) (uint32_t *)(NRF5340_SPU_BASE + 0x600 + (n) * 0x4)
#define NRF5340_SPU_RAMREGION_PERM(n)   (uint32_t *)(NRF5340_SPU_BASE + 0x700 + (n) * 0x4)
#define NRF5340_SPU_PERIPHID_PERM(n)    (uint32_t *)(NRF5340_SPU_BASE + 0x800 + (n) * 0x4)

#define NRF5340_SPU_FLASHREGION_PERM_EXECUTE     (1 << 0)
#define NRF5340_SPU_FLASHREGION_PERM_WRITE       (1 << 1)
#define NRF5340_SPU_FLASHREGION_PERM_READ        (1 << 2)
#define NRF5340_SPU_FLASHREGION_PERM_SECURE      (1 << 4)
#define NRF5340_SPU_RAMREGION_PERM_EXECUTE       (1 << 0)
#define NRF5340_SPU_RAMREGION_PERM_WRITE         (1 << 1)
#define NRF5340_SPU_RAMREGION_PERM_READ          (1 << 2)
#define NRF5340_SPU_RAMREGION_PERM_SECURE        (1 << 4)
#define NRF5340_SPU_PERIPHID_PERM_SECATTR_Secure (1 << 4)
#define NRF5340_SPU_PERIPHID_PERM_DMASEC_Secure  (1 << 5)

#define NRF5340_GPIO0_BASE 0x50842500
#define NRF5340_GPIO0_PIN_CNF(n) (uint32_t *)(NRF5340_GPIO0_BASE + 0x200 + (n) * 4)

#define NRF5340_GPIO1_BASE 0x50842800
#define NRF5340_GPIO1_PIN_CNF(n) (uint32_t *)(NRF5340_GPIO1_BASE + 0x200 + (n) * 4)

#define NRF5340_GPIO_PIN_CNF_MCUSEL_MASK       (0b111 << 28)
#define NRF5340_GPIO_PIN_CNF_MCUSEL_NETWORKMCU (0x1 << 28)
#define NRF5340_GPIO_PIN_CNF_MCUSEL_PERIPHERAL (0x3 << 28)

#define NRF5340_UARTE0_BASE 0x50008000
#define NRF5340_UARTE1_BASE 0x50009000
#define NRF5340_UARTE2_BASE 0x5000B000
#define NRF5340_UARTE3_BASE 0x5000C000

#define NRF5340_UARTE_TASKS_STARTRX(base) (uint32_t *)((base) + 0x000)
#define NRF5340_UARTE_TASKS_STARTTX(base) (uint32_t *)((base) + 0x008)
#define NRF5340_UARTE_EVENTS_ENDRX(base)  (uint32_t *)((base) + 0x110)
#define NRF5340_UARTE_EVENTS_ENDTX(base)  (uint32_t *)((base) + 0x120)
#define NRF5340_UARTE_INTENSET(base)      (uint32_t *)((base) + 0x304)
#define NRF5340_UARTE_INTENCLR(base)      (uint32_t *)((base) + 0x308)
#define NRF5340_UARTE_ENABLE(base)        (uint32_t *)((base) + 0x500)
#define NRF5340_UARTE_PSEL_TXD(base)      (uint32_t *)((base) + 0x50C)
#define NRF5340_UARTE_PSEL_RXD(base)      (uint32_t *)((base) + 0x514)
#define NRF5340_UARTE_BAUDRATE(base)      (uint32_t *)((base) + 0x524)
#define NRF5340_UARTE_RXD_PTR(base)       (uint32_t *)((base) + 0x534)
#define NRF5340_UARTE_RXD_MAXCNT(base)    (uint32_t *)((base) + 0x538)
#define NRF5340_UARTE_TXD_PTR(base)       (uint32_t *)((base) + 0x544)
#define NRF5340_UARTE_TXD_MAXCNT(base)    (uint32_t *)((base) + 0x548)

#define NRF5340_UARTE_INTEN_ENDRX         (1 << 4)
#define NRF5340_UARTE_INTEN_ENDTX         (1 << 8)
#define NRF5340_UARTE_PSEL_PIN(n)         ((n) << 0)
#define NRF5340_UARTE_PSEL_PORT(n)        ((n) << 5)
#define NRF5340_UARTE_BAUDRATE_Baud115200 0x01D60000

#define NRF5340_TIMER0_BASE 0x5000F000
#define NRF5340_TIMER1_BASE 0x50010000
#define NRF5340_TIMER2_BASE 0x50011000

#define NRF5340_TIMER_TASKS_START(base)       (uint32_t *)((base) + 0x000)
#define NRF5340_TIMER_TASKS_STOP(base)        (uint32_t *)((base) + 0x004)
#define NRF5340_TIEMR_TASKS_CAPTURE(base, n)  (uint32_t *)((base) + 0x040 + (n) * 0x4)
#define NRF5340_TIMER_EVENTS_COMPARE(base, n) (uint32_t *)((base) + 0x140 + (n) * 0x4)
#define NRF5340_TIMER_INTENSET(base)          (uint32_t *)((base) + 0x304)
#define NRF5340_TIMER_MODE(base)              (uint32_t *)((base) + 0x504)
#define NRF5340_TIMER_BITMODE(base)           (uint32_t *)((base) + 0x508)
#define NRF5340_TIMER_PRESCALER(base)         (uint32_t *)((base) + 0x510)
#define NRF5340_TIMER_CC(base, n)             (uint32_t *)((base) + 0x540 + (n) * 0x4)
#define NRF5340_TIMER_ONESHOTEN(base, n)      (uint32_t *)((base) + 0x580 + (n) * 0x4)

#define NRF5340_TIMER_INTENSET_COMPARE(n) (1 << ((n) + 16))
#define NRF5340_TIMER_MODE_TIMER          0
#define NRF5340_TIMER_BITMODE_32BIT       3

#define NRF5340_DEBUG_BASE 0x50006000

#define NRF5340_DEBUG_APPROTECT_DISABLE       (uint32_t *)(NRF5340_DEBUG_BASE + 0x544)
#define NRF5340_DEBUG_SECUREAPPROTECT_DISABLE (uint32_t *)(NRF5340_DEBUG_BASE + 0x54C)

#define NRF5340_UARTE0_IRQn 8
#define NRF5340_UARTE1_IRQn 9
#define NRF5340_UARTE2_IRQn 11
#define NRF5340_UARTE3_IRQn 12
#define NRF5340_TIMER0_IRQn 15
#define NRF5340_TIMER1_IRQn 16
#define NRF5340_TIMER2_IRQn 17

#endif /* TOPPERS_NRF5340 */
