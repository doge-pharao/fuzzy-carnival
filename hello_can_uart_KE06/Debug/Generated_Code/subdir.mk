################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AS1.c \
../Generated_Code/CAN1.c \
../Generated_Code/CAN_RxBuff.c \
../Generated_Code/CS1.c \
../Generated_Code/CS2.c \
../Generated_Code/Cpu.c \
../Generated_Code/GREENLED.c \
../Generated_Code/KSDK1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/REDLED.c \
../Generated_Code/TU1.c \
../Generated_Code/UART_RxBuff.c 

OBJS += \
./Generated_Code/AS1.o \
./Generated_Code/CAN1.o \
./Generated_Code/CAN_RxBuff.o \
./Generated_Code/CS1.o \
./Generated_Code/CS2.o \
./Generated_Code/Cpu.o \
./Generated_Code/GREENLED.o \
./Generated_Code/KSDK1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/REDLED.o \
./Generated_Code/TU1.o \
./Generated_Code/UART_RxBuff.o 

C_DEPS += \
./Generated_Code/AS1.d \
./Generated_Code/CAN1.d \
./Generated_Code/CAN_RxBuff.d \
./Generated_Code/CS1.d \
./Generated_Code/CS2.d \
./Generated_Code/Cpu.d \
./Generated_Code/GREENLED.d \
./Generated_Code/KSDK1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/REDLED.d \
./Generated_Code/TU1.d \
./Generated_Code/UART_RxBuff.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Static_Code/System" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Static_Code/PDD" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Sources" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


