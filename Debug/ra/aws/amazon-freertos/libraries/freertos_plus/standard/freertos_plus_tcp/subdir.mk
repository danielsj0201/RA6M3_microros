################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_ARP.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_DHCP.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_DNS.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_IP.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_Sockets.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_Stream_Buffer.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_TCP_IP.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_TCP_WIN.c \
../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_UDP_IP.c 

OBJS += \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_ARP.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_DHCP.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_DNS.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_IP.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_Sockets.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_Stream_Buffer.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_TCP_IP.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_TCP_WIN.o \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_UDP_IP.o 

C_DEPS += \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_ARP.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_DHCP.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_DNS.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_IP.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_Sockets.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_Stream_Buffer.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_TCP_IP.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_TCP_WIN.d \
./ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/FreeRTOS_UDP_IP.d 


# Each subdirectory must supply rules for building sources it contributes
ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/%.o: ../ra/aws/amazon-freertos/libraries/freertos_plus/standard/freertos_plus_tcp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\microros_core\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\src" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc\api" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc\instances" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\src\rm_freertos_port" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\aws\amazon-freertos\freertos_kernel\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_gen" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\fsp_cfg\bsp" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\fsp_cfg" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\aws" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\aws\amazon-freertos\libraries\freertos_plus\standard\freertos_plus_tcp\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\src\rm_freertos_plus_tcp" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


