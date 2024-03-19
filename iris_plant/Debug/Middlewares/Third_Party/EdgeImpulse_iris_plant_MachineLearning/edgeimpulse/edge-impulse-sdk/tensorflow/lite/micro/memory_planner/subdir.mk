################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cpp \
../Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.cpp \
../Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.cpp 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.o \
./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.o \
./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.o 

CPP_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.d \
./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.d \
./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/%.o Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/%.su Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/%.cyclo: ../Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/%.cpp Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/ -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_iris_plant_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-tensorflow-2f-lite-2f-micro-2f-memory_planner

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_iris_plant_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-tensorflow-2f-lite-2f-micro-2f-memory_planner:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cyclo ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.d ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.o ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/greedy_memory_planner.su ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.cyclo ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.d ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.o ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/linear_memory_planner.su ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.cyclo ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.d ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.o ./Middlewares/Third_Party/EdgeImpulse_iris_plant_MachineLearning/edgeimpulse/edge-impulse-sdk/tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_iris_plant_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-tensorflow-2f-lite-2f-micro-2f-memory_planner
