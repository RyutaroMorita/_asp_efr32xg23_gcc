/***************************************************************************//**
 * @file
 * @brief EZRADIODRV configuration file.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#include "sl_spidrv_exp_config.h"

// <<< Use Configuration Wizard in Context Menu >>>

#ifndef __SILICON_LABS_EZRADIODRV_CONFIG_H__
#define __SILICON_LABS_EZRADIODRV_CONFIG_H__

#define RADIO_CHIP_FAMILY_EZRADIO    1
#define RADIO_CHIP_FAMILY_EZRADIOPRO 2

// <o RADIO_CONFIGURATION_DATA_RADIO_CHIP_FAMILY> Radio chip family
//   <RADIO_CHIP_FAMILY_EZRADIOPRO=> EZRadioPro
//   <RADIO_CHIP_FAMILY_EZRADIO=> EZRadio
// <i> Selection of the Radio chip family
#define RADIO_CONFIGURATION_DATA_RADIO_CHIP_FAMILY  RADIO_CHIP_FAMILY_EZRADIOPRO

// <q EZRADIO_PLUGIN_TRANSMIT> Enable Transmit Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_TRANSMIT  1

// <q EZRADIO_PLUGIN_RECEIVE> Enable Receive Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_RECEIVE  1

// <q EZRADIO_PLUGIN_CRC_ERROR> Enable CRC Error Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_CRC_ERROR  0

// <q EZRADIO_PLUGIN_UNMOD_CARRIER> Enable Unmodulated Carrier Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_UNMOD_CARRIER  1

// <q EZRADIO_PLUGIN_PN9> Enable PN9 Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_PN9  0

// <q EZRADIO_PLUGIN_DIRECT_TRANSMIT> Enable Direct Transmit Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_DIRECT_TRANSMIT  0

// <q EZRADIO_PLUGIN_DIRECT_RECEIVE> Enable Direct Receive Plugin
// <i> Default: 0
#define EZRADIO_PLUGIN_DIRECT_RECEIVE  0

// <o RADIO_CONFIG_DATA_RADIO_DELAY_AFTER_RESET_US> Delay after reset in microseconds
// <i> Default: 10000
#define RADIO_CONFIG_DATA_RADIO_DELAY_AFTER_RESET_US (10000)

// <o EZRADIODRV_COMM_CTS_RETRY> Number of wait-for-CTS retries
// <i> Default: 10000
#define EZRADIODRV_COMM_CTS_RETRY 10000

// <q EZRADIODRV_COMM_USE_GPIO1_FOR_CTS> Enable poll GPIO1 for CTS
// <i> Default: 0
#define EZRADIODRV_COMM_USE_GPIO1_FOR_CTS  0

// <q EZRADIODRV_SPI_4WIRE_MODE> Enable 4-wire SPI communication with the radio
// <i> Note: 4-wire mode cannot be used in EZR32 devices.
// <i> Default: 0
#define EZRADIODRV_SPI_4WIRE_MODE  0

// <<< end of configuration section >>>

// <<< sl:start pin_tool >>>

// <gpio> RF_INT

// <gpio> RF_SDN

// <gpio> RF_GPIO0

// <gpio> RF_GPIO1

// <<< sl:end pin_tool >>>

//RF SPI-port (USART) location number
#define RF_USARTRF_LOCATION     SL_SPIDRV_EXP_TX_LOC
//RF SPI CS GPIO port no.
#define RF_USARTRF_CS_PORT      SL_SPIDRV_EXP_CS_PORT
//RF SPI CS GPIO pin number
#define RF_USARTRF_CS_PIN       SL_SPIDRV_EXP_CS_PIN

#endif /* __SILICON_LABS_EZRADIODRV_CONFIG_H__ */
// $[GPIO_RF_SDN]
#ifndef RF_SDN_PORT                             
#define RF_SDN_PORT                              gpioPortB
#endif
#ifndef RF_SDN_PIN                              
#define RF_SDN_PIN                               5
#endif
// [GPIO_RF_SDN]$

// $[GPIO_RF_GPIO1]
#ifndef RF_GPIO1_PORT                           
#define RF_GPIO1_PORT                            gpioPortC
#endif
#ifndef RF_GPIO1_PIN                            
#define RF_GPIO1_PIN                             5
#endif
// [GPIO_RF_GPIO1]$

// $[GPIO_RF_GPIO0]
#ifndef RF_GPIO0_PORT                           
#define RF_GPIO0_PORT                            gpioPortC
#endif
#ifndef RF_GPIO0_PIN                            
#define RF_GPIO0_PIN                             4
#endif
// [GPIO_RF_GPIO0]$

// $[GPIO_RF_INT]
#ifndef RF_INT_PORT                             
#define RF_INT_PORT                              gpioPortB
#endif
#ifndef RF_INT_PIN                              
#define RF_INT_PIN                               4
#endif
// [GPIO_RF_INT]$

