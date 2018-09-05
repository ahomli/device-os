#include "ota_flash_hal.h"
#include "spark_macros.h"
#include "hal_platform.h"
#include "flash_mal.h"

#if defined(MODULAR_FIRMWARE) && MODULAR_FIRMWARE
#error "Modular firmware is not supported"
#endif

// Bootloader
const module_bounds_t module_bootloader = {
        .maximum_size = 0x0000c000, // bootloader_flash_length
        .start_address = 0x000f4000, // bootloader_flash_origin
        .end_address = 0x00100000,
        .module_function = MODULE_FUNCTION_BOOTLOADER,
        .module_index = 0,
        .store = MODULE_STORE_MAIN
#if HAL_PLATFORM_NCP
		,.mcu_identifier = HAL_PLATFORM_MCU_DEFAULT
#endif
    };

// Monolithic firmware
const module_bounds_t module_user_mono = {
        .maximum_size = 0x000c4000, // 1M - APP_CODE_BASE - bootloader_flash_length
        .start_address = 0x00030000, // APP_CODE_BASE
        .end_address = 0x000f4000, // APP_CODE_BASE + module_user_mono.maximum_size
        .module_function = MODULE_FUNCTION_MONO_FIRMWARE,
        .module_index = 0,
        .store = MODULE_STORE_MAIN
#if HAL_PLATFORM_NCP
		,.mcu_identifier = HAL_PLATFORM_MCU_DEFAULT
#endif

    };

#define EXTERNAL_FLASH_XIP_BASE (0x12000000)

// Factory firmware
const module_bounds_t module_factory_modular = {
        .maximum_size = EXTERNAL_FLASH_FAC_LENGTH, // module_user_app.maximum_size
        .start_address = EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_FAC_ADDRESS,
        .end_address = EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_FAC_ADDRESS + EXTERNAL_FLASH_FAC_LENGTH,
        .module_function = MODULE_FUNCTION_MONO_FIRMWARE,
        .module_index = 0,
        .store = MODULE_STORE_FACTORY
#if HAL_PLATFORM_NCP
		,.mcu_identifier = HAL_PLATFORM_MCU_DEFAULT
#endif
    };

// placeholder for unused space
const module_bounds_t module_xip_code = {
        .maximum_size = EXTERNAL_FLASH_RESERVED_LENGTH,
        .start_address = EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_RESERVED_ADDRESS, // module_factory_modular.end_address
        .end_address = EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_RESERVED_ADDRESS + EXTERNAL_FLASH_RESERVED_LENGTH,
        .module_function = MODULE_FUNCTION_NONE,
        .module_index = 0,
        .store = MODULE_STORE_SCRATCHPAD
#if HAL_PLATFORM_NCP
		,.mcu_identifier = HAL_PLATFORM_MCU_DEFAULT
#endif

    };


// OTA region
const module_bounds_t module_ota = {
        .maximum_size = EXTERNAL_FLASH_OTA_LENGTH,
        .start_address = EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_OTA_ADDRESS,
        .end_address = EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_OTA_ADDRESS + EXTERNAL_FLASH_OTA_LENGTH,
        .module_function = MODULE_FUNCTION_NONE,
        .module_index = 0,
        .store = MODULE_STORE_SCRATCHPAD
#if HAL_PLATFORM_NCP
		,.mcu_identifier = HAL_PLATFORM_MCU_ANY
#endif

    };

STATIC_ASSERT(Expected_OTA_region_at_end_of_external_flash, (EXTERNAL_FLASH_XIP_BASE + EXTERNAL_FLASH_OTA_ADDRESS + EXTERNAL_FLASH_OTA_LENGTH)==0x12400000);

#if HAL_PLATFORM_NCP
const module_bounds_t module_ncp_mono = {
		.maximum_size = 1500*1024,
		.start_address = 0,
		.end_address = 1500*1024,
		.module_function = MODULE_FUNCTION_MONO_FIRMWARE,
		.module_index = 0,
		.store = MODULE_STORE_MAIN
#if HAL_PLATFORM_NCP
		,.mcu_identifier = HAL_PLATFORM_MCU_ANY
#endif
};
#endif

const module_bounds_t* const module_bounds[] = { &module_bootloader, &module_user_mono, &module_factory_modular
#if HAL_PLATFORM_NCP
		,&module_ncp_mono
#endif /* HAL_PLATFORM_NCP */
};

const unsigned module_bounds_length = arraySize(module_bounds);