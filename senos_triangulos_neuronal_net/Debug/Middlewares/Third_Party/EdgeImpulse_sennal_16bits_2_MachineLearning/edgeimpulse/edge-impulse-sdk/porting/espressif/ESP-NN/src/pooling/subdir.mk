################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.c \
../Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.c 

C_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.d \
./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.d 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.o \
./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/%.o Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/%.su Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/%.cyclo: ../Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/%.c Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_sennal_16bits_2_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-porting-2f-espressif-2f-ESP-2d-NN-2f-src-2f-pooling

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_sennal_16bits_2_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-porting-2f-espressif-2f-ESP-2d-NN-2f-src-2f-pooling:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.cyclo ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.d ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.o ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_avg_pool_ansi.su ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.cyclo ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.d ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.o ./Middlewares/Third_Party/EdgeImpulse_sennal_16bits_2_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/pooling/esp_nn_max_pool_ansi.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_sennal_16bits_2_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-porting-2f-espressif-2f-ESP-2d-NN-2f-src-2f-pooling

