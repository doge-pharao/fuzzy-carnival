################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Static_Code/Peripherals/ACMP0_Init.c 

OBJS += \
./Static_Code/Peripherals/ACMP0_Init.o 

C_DEPS += \
./Static_Code/Peripherals/ACMP0_Init.d 


# Each subdirectory must supply rules for building sources it contributes
Static_Code/Peripherals/%.o: ../Static_Code/Peripherals/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/alejandro/workspace.kds/IrDA/Static_Code/System" -I"/home/alejandro/workspace.kds/IrDA/Static_Code/PDD" -I"/home/alejandro/workspace.kds/IrDA/Static_Code/IO_Map" -I"/opt/Freescale/KDS_v3/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/alejandro/workspace.kds/IrDA/Sources" -I"/home/alejandro/workspace.kds/IrDA/Generated_Code" -I"/home/alejandro/workspace.kds/IrDA/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


