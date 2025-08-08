/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/**********************************************************************************************************************
 * File Name    : application_config.h
 * Description  : This file defines the macro of the application configuration.
 **********************************************************************************************************************/
#ifndef APPLICATION_CONFIG_H__
#define APPLICATION_CONFIG_H__

// ###################### MEMORY ALLOCATION ######################
/* Defines for memory allocation options */
#define ALLOCATE_TO_ONCHIP_ROM              1
#define ALLOCATE_TO_ONCHIP_RAM              2
#define ALLOCATE_TO_SDRAM                   3 // Buffer will be located in SDRAM section
#define ALLOCATE_TO_SDRAM_INITIAL_IN_OSPI   4 // Buffer will be located in SDRAM-InitialInOSPI section
#define ALLOCATE_TO_OSPI                    5 // Buffer will be located in OSPI

/* Selection of target memory space for application buffer */
#define CAMERA_CAPTURE_BUFFER_ALLOCATION    /* Defined by r_vin configuration property. */
#define CAMERA_IMAGE_ALLOCATION             ALLOCATE_TO_ONCHIP_RAM  /* Option: OnchipRAM or SDRAM */

#define DISPLAY_BUFFER_ALLICATION           /* Defined by r_glcdc configuration property. */

#ifndef _MEM_USAGE
#error "define _MEM_USAGE in -D section"
#endif

#if (_MEM_USAGE == 0)
#define AI_INPUT_IMAGE_ALLOCATION           ALLOCATE_TO_ONCHIP_RAM  /* Option: OnchipRAM or SDRAM */
#define AI_MODEL_ALLOCATION                 ALLOCATE_TO_ONCHIP_ROM  /* Option: OnchipROM, OnchipRAM, SDRAM(IntialOSPI) or OSPI */
#define TENSOR_ARENA_ALLOCATION             ALLOCATE_TO_ONCHIP_RAM  /* Option: OnchipRAM or SDRAM */
#elif (_MEM_USAGE==1)
#define AI_INPUT_IMAGE_ALLOCATION           ALLOCATE_TO_ONCHIP_RAM  /* Option: OnchipRAM or SDRAM */
#define AI_MODEL_ALLOCATION                 ALLOCATE_TO_ONCHIP_ROM  /* Option: OnchipROM, OnchipRAM, SDRAM(IntialOSPI) or OSPI */
#define TENSOR_ARENA_ALLOCATION             ALLOCATE_TO_SDRAM       /* Option: OnchipRAM or SDRAM */
#endif
// ################## FUNCTION ENABLEMENT SETTING ################
#define ENABLE_CAMERA_INPUT                          (1) // 0: Disabled, 1: Enabled
#define ENABLE_LCD_DISPLAY_OUTPUT                    (1) // 0: Disabled, 1: Enabled

#define ENABLE_INFERENCE_RUNNING_LED                 (1) // 0: Disabled, 1: Enabled
#define ENABLE_CAMERA_CAPTURE_RUNNING_LED            (0) // 0: Disabled, 1: Enabled

#define ENABLE_CONSOLE_OUTPUT_SCREEN_CLEAR           (1) // 0: Disabled, 1: Enabled. If you'd like to keep a log data, set 0 (disabled).
#define ENABLE_AI_INFERENCE_RESULT_CONSOLE_OUTPUT    (1) // 0: Disabled, 1: Enabled
#define ENABLE_PROCESSING_TIME_RESULT_CONSOLE_OUTPUT (1) // 0: Disabled, 1: Enabled

// ------------------ Internal auto config ------------------
#if ((AI_MODEL_ALLOCATION) == (ALLOCATE_TO_OSPI))
#define REQUIRE_OSPI_OPEN
#elif ((AI_MODEL_ALLOCATION) == (ALLOCATE_TO_SDRAM_INITIAL_IN_OSPI))
#define REQUIRE_OSPI_OPEN
#define REQUIRE_OSPI_MEMORY_COPY_TO_SDRAM
#endif

// #######################  CONSOLE ###########################
#define CONSOLE_SELECTION (1)  // (1) = console (0) = printf
#endif /* APPLICATION_CONFIG_H__ */
