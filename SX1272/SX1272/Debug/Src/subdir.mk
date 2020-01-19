################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/radio.c \
../Src/stm32l1xx_hal_msp.c \
../Src/stm32l1xx_it.c \
../Src/sx1272-Fsk.c \
../Src/sx1272-FskMisc.c \
../Src/sx1272-Hal.c \
../Src/sx1272-LoRa.c \
../Src/sx1272-LoRaMisc.c \
../Src/sx1272.c \
../Src/syscalls.c \
../Src/system_stm32l1xx.c 

OBJS += \
./Src/main.o \
./Src/radio.o \
./Src/stm32l1xx_hal_msp.o \
./Src/stm32l1xx_it.o \
./Src/sx1272-Fsk.o \
./Src/sx1272-FskMisc.o \
./Src/sx1272-Hal.o \
./Src/sx1272-LoRa.o \
./Src/sx1272-LoRaMisc.o \
./Src/sx1272.o \
./Src/syscalls.o \
./Src/system_stm32l1xx.o 

C_DEPS += \
./Src/main.d \
./Src/radio.d \
./Src/stm32l1xx_hal_msp.d \
./Src/stm32l1xx_it.d \
./Src/sx1272-Fsk.d \
./Src/sx1272-FskMisc.d \
./Src/sx1272-Hal.d \
./Src/sx1272-LoRa.d \
./Src/sx1272-LoRaMisc.d \
./Src/sx1272.d \
./Src/syscalls.d \
./Src/system_stm32l1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32L152xE -I"/Users/alexmacbook/Documents/myprog/sx1272/SX1272/SX1272/Inc" -I"/Users/alexmacbook/Documents/myprog/sx1272/SX1272/SX1272/Drivers/STM32L1xx_HAL_Driver/Inc" -I"/Users/alexmacbook/Documents/myprog/sx1272/SX1272/SX1272/Drivers/STM32L1xx_HAL_Driver/Inc/Legacy" -I"/Users/alexmacbook/Documents/myprog/sx1272/SX1272/SX1272/Drivers/CMSIS/Device/ST/STM32L1xx/Include" -I"/Users/alexmacbook/Documents/myprog/sx1272/SX1272/SX1272/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


