/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2016 by Embedded and Real-Time Systems Laboratory
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
 *  $Id: tUsart.c 1799 2023-04-01 00:50:30Z ertl-komori $
 */

/*
 * NRF5340用 簡易SIOドライバ
 */

#include <sil.h>
#include "NRF5340.h"
#include "tUsart_tecsgen.h"
#include "kernel/kernel_impl.h"

/*
 * シリアルI/Oポートのオープン
 */
void eSIOPort_open(CELLIDX idx)
{
    CELLCB *p_cellcb = GET_CELLCB(idx);
    sil_wrw_mem(NRF5340_UARTE_BAUDRATE(ATTR_base),
                NRF5340_UARTE_BAUDRATE_Baud115200);
    sil_wrw_mem(NRF5340_UARTE_EVENTS_ENDTX(ATTR_base), 1);
    sil_wrw_mem(NRF5340_UARTE_RXD_PTR(ATTR_base), (uintptr_t)&VAR_rxBuffer);
    sil_wrw_mem(NRF5340_UARTE_RXD_MAXCNT(ATTR_base), 1);

    VAR_txBuffer = 0;
    sil_wrw_mem(NRF5340_UARTE_TXD_PTR(ATTR_base), (uintptr_t)&VAR_txBuffer);
    sil_wrw_mem(NRF5340_UARTE_TXD_MAXCNT(ATTR_base), 1);

    sil_wrw_mem(NRF5340_UARTE_ENABLE(ATTR_base), 8);
    sil_wrw_mem(NRF5340_UARTE_TASKS_STARTTX(ATTR_base), 1);
    sil_wrw_mem(NRF5340_UARTE_TASKS_STARTRX(ATTR_base), 1);
}

/*
 * シリアルI/Oポートのクローズ
 */
void eSIOPort_close(CELLIDX idx)
{
    /*
     *  UARTをディスエーブル
     */
    // CELLCB *p_cellcb = GET_CELLCB(idx);
}

/*
 * シリアルI/Oポートへの文字送信
 */
bool_t eSIOPort_putChar(CELLIDX idx, char c)
{
    CELLCB *p_cellcb = GET_CELLCB(idx);
    if (sil_rew_mem(NRF5340_UARTE_EVENTS_ENDTX(ATTR_base))) {
        sil_wrw_mem(NRF5340_UARTE_EVENTS_ENDTX(ATTR_base), 0);
        VAR_txBuffer = c;
        sil_wrw_mem(NRF5340_UARTE_TASKS_STARTTX(ATTR_base), 1);
        return true;
    }
    return false;
}

/*
 * シリアルI/Oポートからの文字受信
 */
int_t eSIOPort_getChar(CELLIDX idx)
{
    CELLCB *p_cellcb = GET_CELLCB(idx);
    if (sil_rew_mem(NRF5340_UARTE_EVENTS_ENDRX(ATTR_base))) {
        sil_wrw_mem(NRF5340_UARTE_EVENTS_ENDRX(ATTR_base), 0);
        const int_t c = VAR_rxBuffer;
        sil_wrw_mem(NRF5340_UARTE_TASKS_STARTRX(ATTR_base), 1);
        return c;
    }
    return -1;
}

/*
 * シリアルI/Oポートからのコールバックの許可
 */
void eSIOPort_enableCBR(CELLIDX idx, uint_t cbrtn)
{
    CELLCB *p_cellcb = GET_CELLCB(idx);
    switch (cbrtn) {
        case SIOSendReady:
            sil_wrw_mem(NRF5340_UARTE_INTENSET(ATTR_base),
                        NRF5340_UARTE_INTEN_ENDTX);
            break;
        case SIOReceiveReady:
            sil_wrw_mem(NRF5340_UARTE_INTENSET(ATTR_base),
                        NRF5340_UARTE_INTEN_ENDRX);
            break;
    }
}

/*
 * シリアルI/Oポートからのコールバックの禁止
 */
void eSIOPort_disableCBR(CELLIDX idx, uint_t cbrtn)
{
    CELLCB *p_cellcb = GET_CELLCB(idx);
    switch (cbrtn) {
        case SIOSendReady:
            sil_wrw_mem(NRF5340_UARTE_INTENCLR(ATTR_base),
                        NRF5340_UARTE_INTEN_ENDTX);
            break;
        case SIOReceiveReady:
            sil_wrw_mem(NRF5340_UARTE_INTENCLR(ATTR_base),
                        NRF5340_UARTE_INTEN_ENDRX);
            break;
    }
}

/*
 * シリアルI/Oポートに対する割込み処理
 */
void eiISR_main(CELLIDX idx)
{
    CELLCB *p_cellcb = GET_CELLCB(idx);

    if (sil_rew_mem(NRF5340_UARTE_EVENTS_ENDTX(ATTR_base))) {
        ciSIOCBR_readySend();
    }
    if (sil_rew_mem(NRF5340_UARTE_EVENTS_ENDRX(ATTR_base))) {
        ciSIOCBR_readyReceive();
    }
}
