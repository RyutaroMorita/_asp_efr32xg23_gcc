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
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
//#include "ezradio_prop.h"
#include "main.h"


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

bool    ezradioIrqReceived = false;
ID main_wtid = 0;


/***************************************************************************//**
 * Callback function declarations
 ******************************************************************************/
static void appPacketTransmittedCallback (EZRADIODRV_Handle_t handle, Ecode_t status);

static void appPacketReceivedCallback (EZRADIODRV_Handle_t handle, Ecode_t status);


void gpio_odd_handler(void)
{
  GPIO_ODD_IRQHandler();
}

void gpio_even_handler(void)
{
  GPIO_EVEN_IRQHandler();
}

void ldma_handler(void)
{
  LDMA_IRQHandler();
}

void rtc_handler(void)
{
  //
}

/***************************************************************************//**
 * Global functions
 ******************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{
    if (handle == &sl_button_btn0)
    {
        if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
        {
            txStart = true;
        }
        /*
         *  MAIN タスクの操作通知待ち解除
         */
        iwup_tsk(MAIN_TASK);
    }
    if (handle == &sl_button_btn1)
    {
        if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
        {
            if(unmodCarrierStarted)
            {
                unmodCarrierStop = true;
                unmodCarrierStarted = false;
            }
            else
            {
                unmodCarrierStart = true;
            }
        }
        /*
         *  MAIN タスクの操作通知待ち解除
         */
        iwup_tsk(MAIN_TASK);
    }
}

/**************************************************************************//**
 * @brief  Radio nIRQ GPIO interrupt.
 *****************************************************************************/
void GPIO_EZRadio_INT_IRQHandler(uint8_t pin)
{
  (void)pin;

  /* Sign radio interrupt received */
  ezradioIrqReceived = true;

  /*
   *  MAIN タスクの Si4463 からのステータス変更通知待ち解除
   */
  iwup_tsk(MAIN_TASK);
}

/*
 *  メインタスク
 */
void main_task(intptr_t exinf)
{
  ena_int(INTNO_GPIO_ODD);
  ena_int(INTNO_GPIO_EVEN);
  ena_int(INTNO_LDMA);
  //ena_int(INTNO_RTC);

  /***************************************************************************//**
   * Initialize application.
   ******************************************************************************/
  //void app_init(void)
  appRadioInitData.packetTx.userCallback = &appPacketTransmittedCallback;
  appRadioInitData.packetRx.userCallback = &appPacketReceivedCallback;
  appRadioInitData.packetRx.pktBuf = radioRxPkt;

  //Initializing Si4x6x
  ezradioInit(appRadioHandle);

  ezradio_part_info(&ezradioReply);

  ezradioResetTRxFifo();

  EZRADIODRV_PacketLengthConfig_t pktLengthConf = { ezradiodrvTransmitLenghtDefault, 16, {16,0,0,0,0} };
  ezradioLengthConfig(appRadioHandle, pktLengthConf);

  //Start RX
  ezradioStartRx(appRadioHandle);

  while (1) {
      /***************************************************************************//**
       * App ticking function.
       ******************************************************************************/
      //void app_process_action(void)

      /*
       *  Si4463 からのステータス変更通知待ち
       */
      if (tslp_tsk(1000) == E_TMOUT) {
          syslog(LOG_NOTICE, "main_task is running...");
          continue;
      }

      ezradioPluginManager(appRadioHandle);

      if(txStart)
      {
          ezradio_write_tx_fifo(appRadioHandle->packetTx.lenConfig.pktLen, radioTxPkt);

          ezradio_start_tx(appRadioHandle->packetTx.channel, 0x30, 0u);
          txStart = false;
      }
      if(unmodCarrierStart)
      {
          ezradioStartUnmodulatedCarrier(appRadioHandle);
          unmodCarrierStart = false;
          unmodCarrierStarted = true;
      }
      if(unmodCarrierStop)
      {
          ezradioStopUnmodulatedCarrier();
          sl_led_toggle(&sl_led_led0);
          unmodCarrierStop = false;

      }
   }
}

/***************************************************************************//**
 * Callback functions
 ******************************************************************************/
static void appPacketTransmittedCallback(EZRADIODRV_Handle_t handle, Ecode_t status)
{
  (void)handle;
  (void)status;
  // Change to RX state
  ezradioStartRx(handle);

  sl_led_toggle(&sl_led_led0);
}

static void appPacketReceivedCallback(EZRADIODRV_Handle_t handle, Ecode_t status)
{
  (void)handle;
  (void)status;

  sl_led_toggle(&sl_led_led1);
}
