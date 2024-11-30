################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../System/App/app.cpp 

OBJS += \
./System/App/app.o 

CPP_DEPS += \
./System/App/app.d 


# Each subdirectory must supply rules for building sources it contributes
System/App/%.o System/App/%.su System/App/%.cyclo: ../System/App/%.cpp System/App/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/Lib/ssd1306" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Key" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/App" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Time" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Sensor" -O2 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-System-2f-App

clean-System-2f-App:
	-$(RM) ./System/App/app.cyclo ./System/App/app.d ./System/App/app.o ./System/App/app.su

.PHONY: clean-System-2f-App

