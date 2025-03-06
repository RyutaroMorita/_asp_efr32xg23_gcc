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
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 *
 */

#include <string.h>
#include <errno.h>

#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "em_cmu.h"
#include "em_device.h"
#include "em_timer.h"
#include "em_vdac.h"
#include "ezradio_cmd.h"
#include "ezradio_api_lib.h"
#include "ezradio_plugin_manager.h"
//#include "sl_simple_button_instances.h"
#include "sl_simple_led_instances.h"
//#include "ezradio_prop.h"

#include "app_config.h"

#include "pwm.h"
#include "dac.h"
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

#ifndef CONFIG_MODE_DAC

static PWM_t pwm_obj1 = {
    TIMER0,
    cmuClock_TIMER0,
    3,
    ldmaPeripheralSignal_TIMER0_CC0,
    gpioPortC,
    0,
};

static PWM_t pwm_obj2 = {
    TIMER1,
    cmuClock_TIMER1,
    4,
    ldmaPeripheralSignal_TIMER1_CC0,
    gpioPortC,
    1
};

#else // !CONFIG_MODE_DAC

#define NUM_CHANNELS 2

static DAC_t dac_obj = {
    VDAC0,
    cmuClock_VDAC0,
    NUM_CHANNELS,
    NULL,
};

static DAC_CANNEL_t dac_cannels[] = {
    {0, vdacChPortC, gpioPortC, 0, &GPIO->CDBUSALLOC, GPIO_CDBUSALLOC_CDEVEN0_VDAC0CH0},
    {1, vdacChPortC, gpioPortC, 1, &GPIO->CDBUSALLOC, GPIO_CDBUSALLOC_CDODD1_VDAC0CH1}
};

#endif  // !CONFIG_MODE_DAC

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
#if 0
void sl_button_on_change(const sl_button_t *handle)
{
    if (handle == &sl_button_btn0)
    {
        if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED)
        {
            txStart = true;
        }
        /*
         *  MAIN �^�X�N�̑���ʒm�҂�����
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
         *  MAIN �^�X�N�̑���ʒm�҂�����
         */
        iwup_tsk(MAIN_TASK);
    }
}
#endif

/**************************************************************************//**
 * @brief  Radio nIRQ GPIO interrupt.
 *****************************************************************************/
void GPIO_EZRadio_INT_IRQHandler(uint8_t pin)
{
  (void)pin;

  /* Sign radio interrupt received */
  ezradioIrqReceived = true;

  /*
   *  MAIN �^�X�N�� Si4463 ����̃X�e�[�^�X�ύX�ʒm�҂�����
   */
  iwup_tsk(MAIN_TASK);
}

/*
 *  �T�u�^�X�N
 */
void sub_task(intptr_t exinf)
{
  char  c;

  while (1) {
      serial_rea_dat(TASK_PORTID, &c, 1);
      if (c == '0') {
          wai_sem(SEM_MSG);
          syslog(LOG_NOTICE, " button pushed!");
          sig_sem(SEM_MSG);
          txStart = true;
          /*
           *  MAIN �^�X�N�̑���ʒm�҂�����
           */
          wup_tsk(MAIN_TASK);
      } else
      if (c == '1') {
          wai_sem(SEM_MSG);
          syslog(LOG_NOTICE, " button pushed!");
          sig_sem(SEM_MSG);
          if(unmodCarrierStarted)
          {
              unmodCarrierStop = true;
              unmodCarrierStarted = false;
          }
          else
          {
              unmodCarrierStart = true;
          }
          /*
           *  MAIN �^�X�N�̑���ʒm�҂�����
           */
          wup_tsk(MAIN_TASK);
      } else {
          syslog(LOG_NOTICE, " button not supported!");
      }
  }
}

/*
 *  ���C���^�X�N
 */
void main_task(intptr_t exinf)
{
#ifndef CONFIG_MODE_DAC
  pwm_init(&pwm_obj1);
  pwm_init(&pwm_obj2);

  pwm_set_duty(&pwm_obj1, CONFIG_DUTY4VACP1);
  pwm_set_duty(&pwm_obj2, CONFIG_DUTY4VACP2);
#else // !CONFIG_MODE_DAC
  dac_obj.channels = (DAC_CANNEL_t*)&dac_cannels;
  dac_init(&dac_obj);

  // Write the output value to VDAC DATA register
  VDAC_ChannelOutputSet(dac_obj.vdac, 0, DAC_VAL(CONFIG_VACP1, 3.3));
  VDAC_ChannelOutputSet(dac_obj.vdac, 1, DAC_VAL(CONFIG_VACP2, 3.3));
#endif  // !CONFIG_MODE_DAC

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

  act_tsk(SUB_TASK);

  while (1) {
      /***************************************************************************//**
       * App ticking function.
       ******************************************************************************/
      //void app_process_action(void)

      /*
       *  Si4463 ����̃X�e�[�^�X�ύX�ʒm�҂�
       */
      if (tslp_tsk(1000) == E_TMOUT) {
          wai_sem(SEM_MSG);
          syslog(LOG_NOTICE, "main_task is running...");
          sig_sem(SEM_MSG);
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
          sl_led_toggle(&sl_led_led_green);
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

  sl_led_toggle(&sl_led_led_green);
}

static void appPacketReceivedCallback(EZRADIODRV_Handle_t handle, Ecode_t status)
{
  (void)handle;
  (void)status;

  sl_led_toggle(&sl_led_led_red);
}
