################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Application.c \
../Sources/Events.c \
../Sources/main.c 

OBJS += \
./Sources/Application.o \
./Sources/Events.o \
./Sources/main.o 

C_DEPS += \
./Sources/Application.d \
./Sources/Events.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Static_Code/System" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Static_Code/PDD" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Sources" -I"/home/alejandro/workspace.kds/hello_can_uart_KE06/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


