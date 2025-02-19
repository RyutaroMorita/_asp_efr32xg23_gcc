/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2016 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
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
 *  $Id: target_timer.c 1799 2023-04-01 00:50:30Z ertl-komori $
 */

#include "kernel_impl.h"
#include "time_event.h"
#include "target_timer.h"
#include <sil.h>

/*
 * タイマの起動処理
 */
void target_hrt_initialize(intptr_t exinf)
{
    sil_wrw_mem(NRF5340_TIMER_INTENSET(TOPPERS_TIMER_BASE),
                NRF5340_TIMER_INTENSET_COMPARE(0));
    sil_wrw_mem(NRF5340_TIMER_MODE(TOPPERS_TIMER_BASE),
                NRF5340_TIMER_MODE_TIMER);
    sil_wrw_mem(NRF5340_TIMER_BITMODE(TOPPERS_TIMER_BASE),
                NRF5340_TIMER_BITMODE_32BIT);
    sil_wrw_mem(NRF5340_TIMER_PRESCALER(TOPPERS_TIMER_BASE), 4);
    sil_wrw_mem(NRF5340_TIMER_ONESHOTEN(TOPPERS_TIMER_BASE, 0), 1);
    sil_wrw_mem(NRF5340_TIMER_TASKS_START(TOPPERS_TIMER_BASE), 1);
}

/*
 * タイマの停止処理
 */
void target_hrt_terminate(intptr_t exinf)
{
    sil_wrw_mem(NRF5340_TIMER_TASKS_STOP(TOPPERS_TIMER_BASE), 1);
}

/*
 *  タイマ割込みハンドラ
 */
void target_hrt_handler(void)
{
    sil_wrw_mem(NRF5340_TIMER_EVENTS_COMPARE(TOPPERS_TIMER_BASE, 0), 0);
    signal_time();
}
