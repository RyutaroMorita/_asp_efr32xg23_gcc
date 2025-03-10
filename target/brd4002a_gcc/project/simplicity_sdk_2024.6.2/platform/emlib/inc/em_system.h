/***************************************************************************//**
 * @file
 * @brief System API
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

#ifndef EM_SYSTEM_H
#define EM_SYSTEM_H

#include "em_device.h"
#include "em_system_generic.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup system SYSTEM - System Utils
 * @brief System API
 * @details
 *  This module contains functions to read information such as RAM and Flash size,
 *  device unique ID, chip revision, family, and part number from DEVINFO and
 *  SCB blocks. Functions to configure and read status from FPU are available for
 *  compatible devices.
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/** Family identifiers. */
typedef enum {
/* New style family #defines */
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32G)
  systemPartFamilyEfm32Gecko   = _DEVINFO_PART_DEVICE_FAMILY_EFM32G,      /**< EFM32 Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32GG)
  systemPartFamilyEfm32Giant   = _DEVINFO_PART_DEVICE_FAMILY_EFM32GG,     /**< EFM32 Giant Gecko Series 0 Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32GG11B)
  systemPartFamilyEfm32Giant11B = _DEVINFO_PART_DEVICE_FAMILY_EFM32GG11B, /**< EFM32 Giant Gecko Series 1 Configuration 1 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32GG12B)
  systemPartFamilyEfm32Giant12B = _DEVINFO_PART_DEVICE_FAMILY_EFM32GG12B, /**< EFM32 Giant Gecko Series 1 Configuration 2 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32TG)
  systemPartFamilyEfm32Tiny    = _DEVINFO_PART_DEVICE_FAMILY_EFM32TG,     /**< EFM32 Tiny Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32TG11B)
  systemPartFamilyEfm32Tiny11B = _DEVINFO_PART_DEVICE_FAMILY_EFM32TG11B,  /**< EFM32 Tiny Gecko 11 Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32LG)
  systemPartFamilyEfm32Leopard = _DEVINFO_PART_DEVICE_FAMILY_EFM32LG,     /**< EFM32 Leopard Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32WG)
  systemPartFamilyEfm32Wonder  = _DEVINFO_PART_DEVICE_FAMILY_EFM32WG,     /**< EFM32 Wonder Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32ZG)
  systemPartFamilyEfm32Zero    = _DEVINFO_PART_DEVICE_FAMILY_EFM32ZG,     /**< EFM32 Zero Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32HG)
  systemPartFamilyEfm32Happy   = _DEVINFO_PART_DEVICE_FAMILY_EFM32HG,     /**< EFM32 Happy Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32PG1B)
  systemPartFamilyEfm32Pearl1B = _DEVINFO_PART_DEVICE_FAMILY_EFM32PG1B,   /**< EFM32 Pearl Gecko Series 1 Configuration 1 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32JG1B)
  systemPartFamilyEfm32Jade1B  = _DEVINFO_PART_DEVICE_FAMILY_EFM32JG1B,   /**< EFM32 Jade Gecko Series 1 Configuration 1 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32PG12B)
  systemPartFamilyEfm32Pearl12B = _DEVINFO_PART_DEVICE_FAMILY_EFM32PG12B, /**< EFM32 Pearl Gecko Series 1 Configuration 2 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFM32JG12B)
  systemPartFamilyEfm32Jade12B  = _DEVINFO_PART_DEVICE_FAMILY_EFM32JG12B, /**< EFM32 Jade Gecko Series 1 Configuration 2 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EZR32WG)
  systemPartFamilyEzr32Wonder  = _DEVINFO_PART_DEVICE_FAMILY_EZR32WG,     /**< EZR32 Wonder Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EZR32LG)
  systemPartFamilyEzr32Leopard = _DEVINFO_PART_DEVICE_FAMILY_EZR32LG,     /**< EZR32 Leopard Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EZR32HG)
  systemPartFamilyEzr32Happy   = _DEVINFO_PART_DEVICE_FAMILY_EZR32HG,     /**< EZR32 Happy Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG1P)
  systemPartFamilyMighty1P = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG1P,       /**< EFR32 Mighty Gecko Series 1 Configuration 1 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG1B)
  systemPartFamilyMighty1B = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG1B,       /**< EFR32 Mighty Gecko Series 1 Configuration 1 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG1V)
  systemPartFamilyMighty1V = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG1V,       /**< EFR32 Mighty Gecko Series 1 Configuration 1 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG1P)
  systemPartFamilyBlue1P   = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG1P,       /**< EFR32 Blue Gecko Series 1 Configuration 1 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG1B)
  systemPartFamilyBlue1B   = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG1B,       /**< EFR32 Blue Gecko Series 1 Configuration 1 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG1V)
  systemPartFamilyBlue1V   = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG1V,       /**< EFR32 Blue Gecko Series 1 Configuration 1 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG1P)
  systemPartFamilyFlex1P   = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG1P,       /**< EFR32 Flex Gecko Series 1 Configuration 1 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG1B)
  systemPartFamilyFlex1B   = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG1B,       /**< EFR32 Flex Gecko Series 1 Configuration 1 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG1V)
  systemPartFamilyFlex1V   = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG1V,       /**< EFR32 Flex Gecko Series 1 Configuration 1 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG12P)
  systemPartFamilyMighty12P = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG12P,     /**< EFR32 Mighty Gecko Series 1 Configuration 2 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG12B)
  systemPartFamilyMighty12B = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG12B,     /**< EFR32 Mighty Gecko Series 1 Configuration 2 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG12V)
  systemPartFamilyMighty12V = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG12V,     /**< EFR32 Mighty Gecko Series 1 Configuration 2 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG12P)
  systemPartFamilyBlue12P   = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG12P,     /**< EFR32 Blue Gecko Series 1 Configuration 2 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG12B)
  systemPartFamilyBlue12B   = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG12B,     /**< EFR32 Blue Gecko Series 1 Configuration 2 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG12V)
  systemPartFamilyBlue12V   = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG12V,     /**< EFR32 Blue Gecko Series 1 Configuration 2 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG12P)
  systemPartFamilyFlex12P   = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG12P,     /**< EFR32 Flex Gecko Series 1 Configuration 2 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG12B)
  systemPartFamilyFlex12B   = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG12B,     /**< EFR32 Flex Gecko Series 1 Configuration 2 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG12V)
  systemPartFamilyFlex12V   = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG12V,     /**< EFR32 Flex Gecko Series 1 Configuration 2 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG13P)
  systemPartFamilyMighty13P = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG13P,     /**< EFR32 Mighty Gecko Series 1 Configuration 3 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG13B)
  systemPartFamilyMighty13B = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG13B,     /**< EFR32 Mighty Gecko Series 1 Configuration 3 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG13V)
  systemPartFamilyMighty13V = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG13V,     /**< EFR32 Mighty Gecko Series 1 Configuration 3 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG13P)
  systemPartFamilyBlue13P = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG13P,       /**< EFR32 Blue Gecko Series 1 Configuration 3 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG13B)
  systemPartFamilyBlue13B = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG13B,       /**< EFR32 Blue Gecko Series 1 Configuration 3 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32BG13V)
  systemPartFamilyBlue13V = _DEVINFO_PART_DEVICE_FAMILY_EFR32BG13V,       /**< EFR32 Blue Gecko Series 1 Configuration 3 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG13P)
  systemPartFamilyFlex13P = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG13P,       /**< EFR32 Flex Gecko Series 1 Configuration 3 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG13B)
  systemPartFamilyFlex13B = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG13B,       /**< EFR32 Flex Gecko Series 1 Configuration 3 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG13V)
  systemPartFamilyFlex13V = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG13V,       /**< EFR32 Flex Gecko Series 1 Configuration 3 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32ZG13P)
  systemPartFamilyZen13P = _DEVINFO_PART_DEVICE_FAMILY_EFR32ZG13P,        /**< EFR32 Zen Gecko Series 1 Configuration 3 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32ZG13L)
  systemPartFamilyZen13L = _DEVINFO_PART_DEVICE_FAMILY_EFR32ZG13L,        /**< EFR32 Zen Gecko Series 1 Configuration 3 Led Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32ZG13S)
  systemPartFamilyZen13S = _DEVINFO_PART_DEVICE_FAMILY_EFR32ZG13S,        /**< EFR32 Zen Gecko Series 1 Configuration 3 Sensor Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG14P)
  systemPartFamilyMighty14P = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG14P,     /**< EFR32 Mighty Gecko Series 1 Configuration 4 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG14B)
  systemPartFamilyMighty14B = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG14B,     /**< EFR32 Mighty Gecko Series 1 Configuration 4 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32MG14V)
  systemPartFamilyMighty14V = _DEVINFO_PART_DEVICE_FAMILY_EFR32MG14V,     /**< EFR32 Mighty Gecko Series 1 Configuration 4 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG14P)
  systemPartFamilyFlex14P = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG14P,       /**< EFR32 Flex Gecko Series 1 Configuration 4 Premium Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG14B)
  systemPartFamilyFlex14B = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG14B,       /**< EFR32 Flex Gecko Series 1 Configuration 4 Basic Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32FG14V)
  systemPartFamilyFlex14V = _DEVINFO_PART_DEVICE_FAMILY_EFR32FG14V,       /**< EFR32 Flex Gecko Series 1 Configuration 4 Value Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_EFR32ZG14P)
  systemPartFamilyZen14P = _DEVINFO_PART_DEVICE_FAMILY_EFR32ZG14P,        /**< EFR32 Zen Gecko Series 1 Configuration 4 Premium Device Family. */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_1)
  systemPartFamilyMighty21 = DEVINFO_PART_FAMILY_MG | (21 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty Gecko Series 2 Config 1 Value Device Family */
  systemPartFamilyFlex21 = DEVINFO_PART_FAMILY_FG | (21 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Flex Gecko Series 2 Config 1 Value Device Family */
  systemPartFamilyBlue21 = DEVINFO_PART_FAMILY_BG | (21 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Blue Gecko Series 2 Config 1 Value Device Family */
  systemPartFamilyMightyRcp21 = DEVINFO_PART_FAMILY_MR | (21 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty RCP Series 2 Config 1 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_2)
  systemPartFamilyMighty22 = DEVINFO_PART_FAMILY_MG | (22 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty Gecko Series 2 Config 2 Value Device Family */
  systemPartFamilyFlex22 = DEVINFO_PART_FAMILY_FG | (22 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Flex Gecko Series 2 Config 2 Value Device Family */
  systemPartFamilyBlue22 = DEVINFO_PART_FAMILY_BG | (22 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Blue Gecko Series 2 Config 2 Value Device Family */
  systemPartFamilyEfm32Pearl22 = DEVINFO_PART_FAMILY_PG | (22 << _DEVINFO_PART_FAMILYNUM_SHIFT),     /**< EFM32 Pearl Gecko Series 2 Config 2 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_3)
  systemPartFamilyFlex23 = DEVINFO_PART_FAMILY_FG | (23 << _DEVINFO_PART_FAMILYNUM_SHIFT),       /**< EFR32 Flex Gecko Series 2 Config 3 Value Device Family */
  systemPartFamilyZen23 = DEVINFO_PART_FAMILY_ZG | (23 << _DEVINFO_PART_FAMILYNUM_SHIFT),        /**< EFR32 Zen Gecko Series 2 Config 3 Value Device Family */
  systemPartFamilyEfm32Pearl23 = DEVINFO_PART_FAMILY_PG | (23 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFM32 Pearl Gecko Series 2 Config 3 Value Device Family */
  systemPartFamilySideWalk23 = DEVINFO_PART_FAMILY_SG | (23 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Side Walk Gecko Series 2 Config 3 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_4)
  systemPartFamilyMighty24 = DEVINFO_PART_FAMILY_MG | (24 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty Gecko Series 2 Config 4 Value Device Family */
  systemPartFamilyFlex24 = DEVINFO_PART_FAMILY_FG | (24 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Flex Gecko Series 2 Config 4 Value Device Family */
  systemPartFamilyBlue24 = DEVINFO_PART_FAMILY_BG | (24 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Blue Gecko Series 2 Config 4 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_5)
  systemPartFamilyFlex25 = DEVINFO_PART_FAMILY_FG | (25 << _DEVINFO_PART_FAMILYNUM_SHIFT),       /**< EFR32 Flex Gecko Series 2 Config 5 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_6)
  systemPartFamilyMighty26 = DEVINFO_PART_FAMILY_MG | (26 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty Gecko Series 2 Config 6 Value Device Family */
  systemPartFamilyBlue26 = DEVINFO_PART_FAMILY_BG | (26 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Blue Gecko Series 2 Config 6 Value Device Family */
  systemPartFamilyEfm32Pearl26 = DEVINFO_PART_FAMILY_PG | (26 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFM32 Pearl Gecko Series 2 Config 6 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_7)
  systemPartFamilyMighty27 = DEVINFO_PART_FAMILY_MG | (27 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty Gecko Series 2 Config 7 Value Device Family */
  systemPartFamilyBlue27 = DEVINFO_PART_FAMILY_BG | (27 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Blue Gecko Series 2 Config 7 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_8)
  systemPartFamilyFlex28 = DEVINFO_PART_FAMILY_FG | (28 << _DEVINFO_PART_FAMILYNUM_SHIFT),  /**< EFR32 Flex Gecko Series 2 Config 8 Value Device Family */
  systemPartFamilyZen28 = DEVINFO_PART_FAMILY_ZG | (28 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Zen Gecko Series 2 Config 8 Value Device Family */
  systemPartFamilySideWalk28 = DEVINFO_PART_FAMILY_SG | (28 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Side Walk Gecko Series 2 Config 8 Value Device Family */
  systemPartFamilyEfm32Pearl28 = DEVINFO_PART_FAMILY_PG | (28 << _DEVINFO_PART_FAMILYNUM_SHIFT),  /**< EFM32 Pearl Gecko Series 2 Config 8 Value Device Family */
#endif
#if defined(_SILICON_LABS_32B_SERIES_2_CONFIG_9)
  systemPartFamilyMighty29 = DEVINFO_PART_FAMILY_MG | (29 << _DEVINFO_PART_FAMILYNUM_SHIFT), /**< EFR32 Mighty Gecko Series 2 Config 9 Value Device Family */
  systemPartFamilyBlue29 = DEVINFO_PART_FAMILY_BG | (29 << _DEVINFO_PART_FAMILYNUM_SHIFT),   /**< EFR32 Blue Gecko Series 2 Config 9 Value Device Family */
#endif
/* Deprecated family #defines */
#if defined(_DEVINFO_PART_DEVICE_FAMILY_G)
  systemPartFamilyGecko   = _DEVINFO_PART_DEVICE_FAMILY_G,   /**< Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_GG)
  systemPartFamilyGiant   = _DEVINFO_PART_DEVICE_FAMILY_GG,  /**< Giant Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_TG)
  systemPartFamilyTiny    = _DEVINFO_PART_DEVICE_FAMILY_TG,  /**< Tiny Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_LG)
  systemPartFamilyLeopard = _DEVINFO_PART_DEVICE_FAMILY_LG,  /**< Leopard Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_WG)
  systemPartFamilyWonder  = _DEVINFO_PART_DEVICE_FAMILY_WG,  /**< Wonder Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_ZG)
  systemPartFamilyZero    = _DEVINFO_PART_DEVICE_FAMILY_ZG,  /**< Zero Gecko Device Family. */
#endif
#if defined(_DEVINFO_PART_DEVICE_FAMILY_HG)
  systemPartFamilyHappy   = _DEVINFO_PART_DEVICE_FAMILY_HG,  /**< Happy Gecko Device Family. */
#endif
  systemPartFamilyUnknown = 0xFF                             /**< Unknown Device Family.
                                                                  Family ID is missing
                                                                  on unprogrammed parts. */
} SYSTEM_PartFamily_TypeDef;

/*******************************************************************************
 *******************************   STRUCTS   ***********************************
 ******************************************************************************/

/** Chip revision details. */
typedef struct {
  uint8_t minor;       /**< Minor revision number. */
  uint8_t major;       /**< Major revision number. */
#if defined(_SYSCFG_CHIPREV_PARTNUMBER_MASK)
  uint16_t partNumber; /**< Device part number.    */
#else
  uint8_t family;      /**< Device family number.  */
#endif
} SYSTEM_ChipRevision_TypeDef;

#if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1)
/** Floating point co-processor access modes. */
typedef enum {
  fpuAccessDenied         = (0x0 << 20),  /**< Access denied, any attempted access generates a NOCP UsageFault. */
  fpuAccessPrivilegedOnly = (0x5 << 20),  /**< Privileged access only, an unprivileged access generates a NOCP UsageFault. */
  fpuAccessReserved       = (0xA << 20),  /**< Reserved. */
  fpuAccessFull           = (0xF << 20)   /**< Full access. */
} SYSTEM_FpuAccess_TypeDef;
#endif

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

void                      SYSTEM_ChipRevisionGet(SYSTEM_ChipRevision_TypeDef *rev);
SYSTEM_PartFamily_TypeDef SYSTEM_GetFamily(void);

#if defined(_DEVINFO_DEVINFOREV_DEVINFOREV_MASK) || defined(_DEVINFO_INFO_DEVINFOREV_MASK)
/***************************************************************************//**
 * @brief
 *   Get DEVINFO revision.
 *
 * @return
 *   Revision of the DEVINFO contents.
 ******************************************************************************/
__STATIC_INLINE uint8_t SYSTEM_GetDevinfoRev(void)
{
#if defined(_DEVINFO_DEVINFOREV_DEVINFOREV_MASK)
  return (uint8_t)((DEVINFO->DEVINFOREV & _DEVINFO_DEVINFOREV_DEVINFOREV_MASK)
                   >> _DEVINFO_DEVINFOREV_DEVINFOREV_SHIFT);
#elif defined(_DEVINFO_INFO_DEVINFOREV_MASK)
  return (uint8_t)((DEVINFO->INFO & _DEVINFO_INFO_DEVINFOREV_MASK)
                   >> _DEVINFO_INFO_DEVINFOREV_SHIFT);
#endif
}
#endif

#if defined(__FPU_PRESENT) && (__FPU_PRESENT == 1)
/***************************************************************************//**
 * @brief
 *   Set floating point co-processor (FPU) access mode.
 *
 * @param[in] accessMode
 *   Floating point co-processor access mode. See @ref SYSTEM_FpuAccess_TypeDef
 *   for details.
 ******************************************************************************/
__STATIC_INLINE void SYSTEM_FpuAccessModeSet(SYSTEM_FpuAccess_TypeDef accessMode)
{
  SCB->CPACR = (SCB->CPACR & ~(0xFUL << 20)) | (uint32_t)accessMode;
}
#endif

/** @} (end addtogroup system) */

#ifdef __cplusplus
}
#endif
#endif /* EM_SYSTEM_H */
