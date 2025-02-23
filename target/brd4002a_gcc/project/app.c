/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "pin_config.h"
/*
 * これ以降は「autogen」ディレクトリ以下に生成されたコンポーネントのヘッダファイル
 * コンポーネント、ドライバの関数やインスタンスを使用するために必要
 */
#include "sl_simple_led_instances.h"
#include "sl_simple_button_instances.h"
#include "sl_uartdrv_instances.h"

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  /*
   * VCOM_ENABLEピンをHighにして仮想シリアルポートを有効化
   */
  GPIO_PinOutSet(VCOM_ENABLE_PORT, VCOM_ENABLE_PIN);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  sl_button_state_t s;
  static sl_button_state_t st0 = 0;
  static sl_button_state_t st1 = 0;

  /*
   * プッシュボタン0(PB0)の処理
   */
  s = sl_button_btn0.get_state(&sl_button_btn0);
  if (st0 != s) {
    // 以前の状態から変化があった場合
    st0 = s;
    if (st0) { // 押されている
        //　LED0を点灯
        sl_simple_led_turn_on(sl_led_led0.context);
        // PB0が押されたメッセージを送信
        UARTDRV_TransmitB(sl_uartdrv_usart_vcom_handle, (uint8_t*)"PB0 Pushed!\r\n", 13);
    } else { // 放されている
        //　LED0を消灯
        sl_simple_led_turn_off(sl_led_led0.context);
        // PB0が放されたメッセージを送信
        UARTDRV_TransmitB(sl_uartdrv_usart_vcom_handle, (uint8_t*)"PB0 Released!\r\n", 15);
    }
  }

  /*
   * プッシュボタン1(PB1)の処理
   */
  s = sl_button_btn1.get_state(&sl_button_btn1);
  if (st1 != s) {
    // 以前の状態から変化があった場合
    st1 = s;
    if (st1) { // 押されている
        //　LED1を点灯
        sl_simple_led_turn_on(sl_led_led1.context);
        // PB1が押されたメッセージを送信
        UARTDRV_TransmitB(sl_uartdrv_usart_vcom_handle, (uint8_t*)"PB1 Pushed!\r\n", 13);
    } else { // 放されている
        //　LED1を消灯
        sl_simple_led_turn_off(sl_led_led1.context);
        // PB1が放されたメッセージを送信
        UARTDRV_TransmitB(sl_uartdrv_usart_vcom_handle, (uint8_t*)"PB1 Released!\r\n", 15);
    }
  }
}
