################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Sexto_sem/MCU_avanzados/TouchGFX/Core/Src/system_stm32f7xx.c 

C_DEPS += \
./Drivers/CMSIS/system_stm32f7xx.d 

OBJS += \
./Drivers/CMSIS/system_stm32f7xx.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f7xx.o: E:/Sexto_sem/MCU_avanzados/TouchGFX/Core/Src/system_stm32f7xx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DST -DSTM32F746xx -DUSE_BPP=16 -DUSE_FLOATING_POINT -c -I../../../Gui/gui/include -I../../../Gui/generated/fonts/include -I../../../Gui/generated/images/include -I../../../Gui/generated/texts/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32746G-Discovery -I../../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../../Gui/target -I../../../Core/Inc -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -Wno-strict-aliasing -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32f7xx.cyclo ./Drivers/CMSIS/system_stm32f7xx.d ./Drivers/CMSIS/system_stm32f7xx.o ./Drivers/CMSIS/system_stm32f7xx.su

.PHONY: clean-Drivers-2f-CMSIS

