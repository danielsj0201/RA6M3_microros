################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c \
../src/microros_allocators.c \
../src/microros_time.c \
../src/new_thread0_entry.c \
../src/udp_transport_freeRTOS.c 

OBJS += \
./src/hal_entry.o \
./src/microros_allocators.o \
./src/microros_time.o \
./src/new_thread0_entry.o \
./src/udp_transport_freeRTOS.o 

C_DEPS += \
./src/hal_entry.d \
./src/microros_allocators.d \
./src/microros_time.d \
./src/new_thread0_entry.d \
./src/udp_transport_freeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\microros_core\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\src" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc\api" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc\instances" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\src\rm_freertos_port" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\aws\amazon-freertos\freertos_kernel\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_gen" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\fsp_cfg\bsp" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\fsp_cfg" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\aws" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\aws\amazon-freertos\libraries\freertos_plus\standard\freertos_plus_tcp\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\src\rm_freertos_plus_tcp" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


