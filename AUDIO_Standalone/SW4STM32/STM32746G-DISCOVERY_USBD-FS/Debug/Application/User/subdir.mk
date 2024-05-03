################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/main.c \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/stm32f7xx_it.c \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/usbd_audio_if.c \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/usbd_conf.c \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/usbd_desc.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f7xx_it.o \
./Application/User/usbd_audio_if.o \
./Application/User/usbd_conf.o \
./Application/User/usbd_desc.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f7xx_it.d \
./Application/User/usbd_audio_if.d \
./Application/User/usbd_conf.d \
./Application/User/usbd_desc.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32f7xx_it.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/stm32f7xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/usbd_audio_if.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/usbd_audio_if.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/usbd_conf.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/usbd_conf.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/usbd_desc.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/Src/usbd_desc.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F746xx -DUSE_STM32746G_DISCO -DUSE_USB_FS -DUSE_IOEXPANDER -c -I../../../Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Device_Library/Class/AUDIO/Inc -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/main.cyclo ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/stm32f7xx_it.cyclo ./Application/User/stm32f7xx_it.d ./Application/User/stm32f7xx_it.o ./Application/User/stm32f7xx_it.su ./Application/User/usbd_audio_if.cyclo ./Application/User/usbd_audio_if.d ./Application/User/usbd_audio_if.o ./Application/User/usbd_audio_if.su ./Application/User/usbd_conf.cyclo ./Application/User/usbd_conf.d ./Application/User/usbd_conf.o ./Application/User/usbd_conf.su ./Application/User/usbd_desc.cyclo ./Application/User/usbd_desc.d ./Application/User/usbd_desc.o ./Application/User/usbd_desc.su

.PHONY: clean-Application-2f-User

