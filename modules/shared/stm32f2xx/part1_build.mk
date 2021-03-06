
ifeq (,$(SYSTEM_PART1_MODULE_DEPENDENCY))
SYSTEM_PART1_MODULE_DEPENDENCY=0,0,0
endif

ifeq (,$(SYSTEM_PART1_MODULE_DEPENDENCY2))
SYSTEM_PART1_MODULE_DEPENDENCY2=0,0,0
endif

GLOBAL_DEFINES += MODULE_VERSION=$(SYSTEM_PART1_MODULE_VERSION)
GLOBAL_DEFINES += MODULE_FUNCTION=$(MODULE_FUNCTION_SYSTEM_PART)
GLOBAL_DEFINES += MODULE_INDEX=1
GLOBAL_DEFINES += MODULE_DEPENDENCY=$(SYSTEM_PART1_MODULE_DEPENDENCY)
GLOBAL_DEFINES += MODULE_DEPENDENCY2=$(SYSTEM_PART1_MODULE_DEPENDENCY2)

LINKER_FILE=$(SYSTEM_PART1_MODULE_PATH)/linker.ld
LINKER_DEPS += $(LINKER_FILE)

ifneq (,$(MODULE_HAS_SYSTEM_PART3))
LINKER_DEPS += $(SYSTEM_PART3_MODULE_PATH)/module_system_part3_export.ld
endif
LINKER_DEPS += $(SYSTEM_PART2_MODULE_PATH)/module_system_part2_export.ld
LINKER_DEPS += $(SYSTEM_PART1_MODULE_PATH)/module_system_part1_export.ld
LINKER_DEPS += $(SYSTEM_PART1_MODULE_PATH)/../../shared/stm32f2xx/part1.ld
LINKER_DEPS += $(SYSTEM_PART1_MODULE_PATH)/../../shared/stm32f2xx/part1_vtor_module.ld


LDFLAGS += --specs=nano.specs -lnosys
LDFLAGS += $(WIFI_MODULE_WICED_LIB_FILES)
LDFLAGS += -T$(LINKER_FILE)
LDFLAGS += -L$(SYSTEM_PART2_MODULE_PATH)
ifneq (,$(MODULE_HAS_SYSTEM_PART3))
LDFLAGS += -L$(SYSTEM_PART3_MODULE_PATH)
endif
LDFLAGS += -Wl,--defsym,PLATFORM_DFU=$(PLATFORM_DFU)
LDFLAGS += -Wl,-Map,$(TARGET_BASE).map

SYSTEM_PART1_MODULE_SRC_PATH = $(SYSTEM_PART1_MODULE_PATH)/src

CPPSRC += $(call target_files,$(SYSTEM_PART1_MODULE_SRC_PATH),*.cpp)
CSRC += $(call target_files,$(SYSTEM_PART1_MODULE_SRC_PATH),*.c)

BUILTINS_EXCLUDE = malloc free realloc
CFLAGS += $(addprefix -fno-builtin-,$(BUILTINS_EXCLUDE))

ifeq ($(PLATFORM_ID),6)
USE_PRINTF_FLOAT ?= y
endif

ifeq ($(PLATFORM_ID),8)
USE_PRINTF_FLOAT ?= y
endif

# Export _printf_float from system-part1 on Photon and P1
ifeq ("$(USE_PRINTF_FLOAT)","y")
LDFLAGS += -u _printf_float
endif
