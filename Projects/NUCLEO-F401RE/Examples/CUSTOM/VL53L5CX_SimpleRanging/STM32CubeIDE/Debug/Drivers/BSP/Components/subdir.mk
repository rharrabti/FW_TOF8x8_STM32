################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/porting/platform.c \
C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/vl53l5cx.c \
C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_api.c \
C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_plugin_detection_thresholds.c \
C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_plugin_motion_indicator.c \
C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_plugin_xtalk.c 

OBJS += \
./Drivers/BSP/Components/platform.o \
./Drivers/BSP/Components/vl53l5cx.o \
./Drivers/BSP/Components/vl53l5cx_api.o \
./Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.o \
./Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.o \
./Drivers/BSP/Components/vl53l5cx_plugin_xtalk.o 

C_DEPS += \
./Drivers/BSP/Components/platform.d \
./Drivers/BSP/Components/vl53l5cx.d \
./Drivers/BSP/Components/vl53l5cx_api.d \
./Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.d \
./Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.d \
./Drivers/BSP/Components/vl53l5cx_plugin_xtalk.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/platform.o: C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/porting/platform.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/Components/vl53l5cx/modules -I../../../../../../../Drivers/BSP/Components/vl53l5cx/porting -I../../../../../../../Drivers/BSP/Components/vl53l5cx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/vl53l5cx.o: C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/vl53l5cx.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/Components/vl53l5cx/modules -I../../../../../../../Drivers/BSP/Components/vl53l5cx/porting -I../../../../../../../Drivers/BSP/Components/vl53l5cx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/vl53l5cx_api.o: C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_api.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/Components/vl53l5cx/modules -I../../../../../../../Drivers/BSP/Components/vl53l5cx/porting -I../../../../../../../Drivers/BSP/Components/vl53l5cx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.o: C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_plugin_detection_thresholds.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/Components/vl53l5cx/modules -I../../../../../../../Drivers/BSP/Components/vl53l5cx/porting -I../../../../../../../Drivers/BSP/Components/vl53l5cx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.o: C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_plugin_motion_indicator.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/Components/vl53l5cx/modules -I../../../../../../../Drivers/BSP/Components/vl53l5cx/porting -I../../../../../../../Drivers/BSP/Components/vl53l5cx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/vl53l5cx_plugin_xtalk.o: C:/PROJETS/BUDDY/BUDDY_TOF/DEUX_TOF8x8/Drivers/BSP/Components/vl53l5cx/modules/vl53l5cx_plugin_xtalk.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/Components/vl53l5cx/modules -I../../../../../../../Drivers/BSP/Components/vl53l5cx/porting -I../../../../../../../Drivers/BSP/Components/vl53l5cx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/platform.cyclo ./Drivers/BSP/Components/platform.d ./Drivers/BSP/Components/platform.o ./Drivers/BSP/Components/platform.su ./Drivers/BSP/Components/vl53l5cx.cyclo ./Drivers/BSP/Components/vl53l5cx.d ./Drivers/BSP/Components/vl53l5cx.o ./Drivers/BSP/Components/vl53l5cx.su ./Drivers/BSP/Components/vl53l5cx_api.cyclo ./Drivers/BSP/Components/vl53l5cx_api.d ./Drivers/BSP/Components/vl53l5cx_api.o ./Drivers/BSP/Components/vl53l5cx_api.su ./Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.cyclo ./Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.d ./Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.o ./Drivers/BSP/Components/vl53l5cx_plugin_detection_thresholds.su ./Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.cyclo ./Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.d ./Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.o ./Drivers/BSP/Components/vl53l5cx_plugin_motion_indicator.su ./Drivers/BSP/Components/vl53l5cx_plugin_xtalk.cyclo ./Drivers/BSP/Components/vl53l5cx_plugin_xtalk.d ./Drivers/BSP/Components/vl53l5cx_plugin_xtalk.o ./Drivers/BSP/Components/vl53l5cx_plugin_xtalk.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

