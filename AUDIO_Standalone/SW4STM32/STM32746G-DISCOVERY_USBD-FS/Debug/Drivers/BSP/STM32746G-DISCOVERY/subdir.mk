################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c 

OBJS += \
./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.o \
./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.o 

C_DEPS += \
./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.d \
./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c Drivers/BSP/STM32746G-DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c Drivers/BSP/STM32746G-DISCOVERY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32746G-2d-DISCOVERY

clean-Drivers-2f-BSP-2f-STM32746G-2d-DISCOVERY:
	-$(RM) ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.cyclo ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.d ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.o ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery.su ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.cyclo ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.d ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.o ./Drivers/BSP/STM32746G-DISCOVERY/stm32746g_discovery_audio.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32746G-2d-DISCOVERY

