################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/SW4STM32/startup_stm32f746xx.s 

OBJS += \
./Application/SW4STM32/startup_stm32f746xx.o 

S_DEPS += \
./Application/SW4STM32/startup_stm32f746xx.d 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f746xx.o: E:/Sexto_sem/MCU_avanzados/AUDIO_Standalone/SW4STM32/startup_stm32f746xx.s Application/SW4STM32/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Application-2f-SW4STM32

clean-Application-2f-SW4STM32:
	-$(RM) ./Application/SW4STM32/startup_stm32f746xx.d ./Application/SW4STM32/startup_stm32f746xx.o

.PHONY: clean-Application-2f-SW4STM32

