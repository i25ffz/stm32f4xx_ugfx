# Possible Targets:	all clean Debug cleanDebug Release cleanRelease

##############################################################################################
# Settings
#

# General settings
	# See $(GFXLIB)/tools/gmake_scripts/readme.txt for the list of variables
	OPT_OS					= freertos
	OPT_THUMB				= yes
	OPT_LINK_OPTIMIZE		= no
	OPT_CPU					= stm32m4
	# OPT_VERBOSE_COMPILE		= yes

# uGFX settings
	# See $(GFXLIB)/tools/gmake_scripts/library_ugfx.mk for the list of variables
	GFXLIB					= ugfx
	GFXBOARD				= STM32F429i-Discovery
	# GFXDEMO				= modules/gdisp/basics / tools/touch_calibration_grabber / 3rdparty/bubbles
	GFXDEMO					= 3rdparty/bubbles
	GFXSINGLEMAKE			= no

# ChibiOS settings
ifeq ($(OPT_OS),chibios)
	# See $(GFXLIB)/tools/gmake_scripts/os_chibios_x.mk for the list of variables
	CHIBIOS					= chibios
	CHIBIOS_VERSION			= 3
	CHIBIOS_BOARD			= ST_STM32F429I_DISCOVERY
	CHIBIOS_CPUCLASS		= ARMCMx
	CHIBIOS_PLATFORM		= STM32
	CHIBIOS_DEVICE_FAMILY	= STM32F4xx
	CHIBIOS_STARTUP			= startup_stm32f4xx
	CHIBIOS_PORT			= v7m
	CHIBIOS_LDSCRIPT		= STM32F429xI.ld
endif

# FreeRTOS settings
ifeq ($(OPT_OS),freertos)
	# See $(GFXLIB)/tools/gmake_scripts/os_freertos.mk for the list of variables
	# CORTEX_M4F_STM32F429I-DISCO_GCC
	FREERTOS				= freertos/FreeRTOS
	FREERTOS_BOARD			= STM32F429I-DISCO
	FREERTOS_CPUCLASS		= ARM_CM4F
	FREERTOS_CPUTYPE		= CORTEX_M4F
endif

##############################################################################################
# Set these for your project
#

ARCH     = arm-none-eabi-
SRCFLAGS = -ggdb -O1
CFLAGS   =
CXXFLAGS = -fno-rtti
ASFLAGS  =
LDFLAGS  = 
# -specs=nano.specs -specs=nosys.specs

ifeq ($(GFXDEMO),)
SRC      = main.c
else
SRC      = 
endif
OBJS     =
DEFS     =
LIBS     =
INCPATH  = 
LIBPATH  =
LDSCRIPT = 

BUILDDIR = out

##############################################################################################
# These should be at the end
#

include $(GFXLIB)/tools/gmake_scripts/library_ugfx.mk
include $(GFXLIB)/tools/gmake_scripts/os_$(OPT_OS).mk
include $(GFXLIB)/tools/gmake_scripts/compiler_gcc.mk
include $(GFXLIB)/tools/gmake_scripts/cpu_stm32m4.mk
# *** EOF ***
