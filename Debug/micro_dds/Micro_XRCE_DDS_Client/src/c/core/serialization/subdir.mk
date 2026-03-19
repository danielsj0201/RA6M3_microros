################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_header.c \
../micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_subheader.c \
../micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_types.c 

OBJS += \
./micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_header.o \
./micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_subheader.o \
./micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_types.o 

C_DEPS += \
./micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_header.d \
./micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_subheader.d \
./micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/xrce_types.d 


# Each subdirectory must supply rules for building sources it contributes
micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/%.o: ../micro_dds/Micro_XRCE_DDS_Client/src/c/core/serialization/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_RA_ -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\src" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\micro_dds\Micro_XRCE_DDS_Client\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\micro_dds\Micro_CDR\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc\api" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\inc\instances" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\src\rm_freertos_port" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\aws\amazon-freertos\freertos_kernel\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_gen" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\fsp_cfg\bsp" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\fsp_cfg" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra_cfg\aws" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\aws\amazon-freertos\libraries\freertos_plus\standard\freertos_plus_tcp\include" -I"C:\Users\sh970\e2_studio\workspace\RA6_microdds_test\ra\fsp\src\rm_freertos_plus_tcp" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


