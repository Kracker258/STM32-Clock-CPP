################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Lib/ssd1306/ssd1306.cpp 

C_SRCS += \
../Lib/ssd1306/ssd1306_fonts.c 

C_DEPS += \
./Lib/ssd1306/ssd1306_fonts.d 

OBJS += \
./Lib/ssd1306/ssd1306.o \
./Lib/ssd1306/ssd1306_fonts.o 

CPP_DEPS += \
./Lib/ssd1306/ssd1306.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/ssd1306/%.o Lib/ssd1306/%.su Lib/ssd1306/%.cyclo: ../Lib/ssd1306/%.cpp Lib/ssd1306/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0plus -std=gnu++20 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/Lib/ssd1306" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Key" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/App" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Time" -I"/home/khai/Documents/STM32_Projects/Stm32g030_clock_cpp/System/Sensor" -O2 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Lib/ssd1306/%.o Lib/ssd1306/%.su Lib/ssd1306/%.cyclo: ../Lib/ssd1306/%.c Lib/ssd1306/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G030xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Lib-2f-ssd1306

clean-Lib-2f-ssd1306:
	-$(RM) ./Lib/ssd1306/ssd1306.cyclo ./Lib/ssd1306/ssd1306.d ./Lib/ssd1306/ssd1306.o ./Lib/ssd1306/ssd1306.su ./Lib/ssd1306/ssd1306_fonts.cyclo ./Lib/ssd1306/ssd1306_fonts.d ./Lib/ssd1306/ssd1306_fonts.o ./Lib/ssd1306/ssd1306_fonts.su

.PHONY: clean-Lib-2f-ssd1306

