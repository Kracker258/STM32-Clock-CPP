################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../System/Time/time.cpp 

OBJS += \
./System/Time/time.o 

CPP_DEPS += \
./System/Time/time.d 


# Each subdirectory must supply rules for building sources it contributes
System/Time/%.o System/Time/%.su System/Time/%.cyclo: ../System/Time/%.cpp System/Time/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/Lib/ssd1306" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Key" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/App" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Time" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Sensor" -O2 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-System-2f-Time

clean-System-2f-Time:
	-$(RM) ./System/Time/time.cyclo ./System/Time/time.d ./System/Time/time.o ./System/Time/time.su

.PHONY: clean-System-2f-Time

