/*
 * app_config.h
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <ryutaro.morita@aeterlink.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Ryutaro Morita
 */

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

/*
 * DAC有効
 * PWMに切り替える場合は以下の行の先頭に「//」を記入してコメント化する
 */
//#define CONFIG_MODE_DAC

/*
 * RFの停波を無効化
 * 停波をする場合は以下の行の先頭に「//」を記入してコメント化する
 */
#define CONFIG_RF_NEVER_OFF

/*
 * プログラム起動まで10秒待つ
 */
#define CONFIG_WAIT_10S


#ifdef CONFIG_MODE_DAC
/*
 * VACP1(PC00)の出力電圧
 */
#define CONFIG_VACP1            (2.7) // 2.0V

/*
 * VACP2(PC01)の出力電圧
 */
#define CONFIG_VACP2            (2.7) // 3.0V
#else // CONFIG_MODE_DAC
/*
 * VACP1(PC00)のPWMデューティー比
 */
#define CONFIG_DUTY4VACP1       80    // 80%

/*
 * VACP2(PC01)のPWMデューティー比
 */
#define CONFIG_DUTY4VACP2       80    // 80%
#endif  // CONFIG_MODE_DAC

/*
 * ADCのメッセージ出力インターバル
 */
#define CONFIG_INTERVAL_PRINT   500   // 500ms毎に出力

#ifndef CONFIG_RF_NEVER_OFF
/*
 * RF出力開始までの時間(出力OFFの間隔)
 */
#define CONFIG_DURATION_RF_ON   50    // 50ms
#endif  // !CONFIG_RF_NEVER_OFF

/*
 * RFRF出力停止までの時間(出力ONの間隔)
 * 実際に出力している時間は(CONFIG_DURATION_RF_OFF - CONFIG_DURATION_RF_ON)となる
 */
#define CONFIG_DURATION_RF_OFF  4000  // 4000ms(4秒)

/*
 * 出力OFFの間に設定されるPAパワーレベル
 * 出力OFF毎に CONFIG_POWER1 -> CONFIG_POWER2 -> CONFIG_POWER1...と切り替わる
 */
#define CONFIG_PA_POWER1        127   // = 0x7F
#define CONFIG_PA_POWER2        127   // = 0x7F

#endif /* APP_CONFIG_H_ */
