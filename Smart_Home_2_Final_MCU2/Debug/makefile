################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Seven_Segment/subdir.mk
-include HAL/KeyPad/subdir.mk
-include HAL/BUTTON/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Smart_Home_2_Final.lss \

FLASH_IMAGE += \
Smart_Home_2_Final.hex \

EEPROM_IMAGE += \
Smart_Home_2_Final.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Smart_Home_2_Final.elf secondary-outputs

# Tool invocations
Smart_Home_2_Final.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Smart_Home_2_Final.map -mmcu=atmega16 -o "Smart_Home_2_Final.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Smart_Home_2_Final.lss: Smart_Home_2_Final.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Smart_Home_2_Final.elf  >"Smart_Home_2_Final.lss"
	@echo 'Finished building: $@'
	@echo ' '

Smart_Home_2_Final.hex: Smart_Home_2_Final.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Smart_Home_2_Final.elf  "Smart_Home_2_Final.hex"
	@echo 'Finished building: $@'
	@echo ' '

Smart_Home_2_Final.eep: Smart_Home_2_Final.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Smart_Home_2_Final.elf  "Smart_Home_2_Final.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Smart_Home_2_Final.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Smart_Home_2_Final.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Smart_Home_2_Final.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
