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
#include "gpiointerrupt.h"
#include "ezradio_cmd.h"
#include "ezradio_api_lib.h"
#include "ezradio_plugin_manager.h"
#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"

/***************************************************************************//**
 * Global variables
 ******************************************************************************/
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

/***************************************************************************//**
 * Callback function declarations
 ******************************************************************************/
static void appPacketTransmittedCallback (EZRADIODRV_Handle_t handle, Ecode_t status);

static void appPacketReceivedCallback (EZRADIODRV_Handle_t handle, Ecode_t status);

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
    }
}

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
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
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
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
