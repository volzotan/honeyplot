# location of the arduino install folder
ARDUINO_DIR = /Applications/Sanguino.app/Contents/Resources/Java

# name of this project (used for the output files)
TARGET_NAME = honeyplot

# a list of the local project folders containing source
# files relative to this makefile
PROJECT_DIRS =	.				\
				mylib

# libraries to include in this project,
# remove any you're not using
LIBRARIES = SPI					\
			Ethernet			\
			Ethernet/utility	\
			EEPROM				\
			Wire				\
			Wire/utility

# location of any other header files to include
USER_INCLUDES =	

# target folder location
OUTPUT_DIR = obj

MCU = atmega644p

# compiler flags for c and cpp files
CFLAGS = -c -g -Os -Wall -ffunction-sections -fdata-sections -mmcu=$(MCU) -DF_CPU=16000000L -DARDUINO_ARCH_AVR -DARDUINO=100
CPPFLAGS = -fno-exceptions $(CFLAGS)

# linker flags
LINK_FLAGS = -Os -Wl,--gc-sections -mmcu=$(MCU) -L$(OUTPUT_DIR) -lm

##### most projects shouldn't need to touch anything below this line #####

# location of various tools
BIN = $(ARDUINO_DIR)/hardware/tools/avr/bin
CORE_DIR = $(ARDUINO_DIR)/hardware/sanguino/cores/arduino
VAR_DIR = $(ARDUINO_DIR)/hardware/sanguino/variants/standard
LIBS_DIR = libs
GCC = $(BIN)/avr-gcc
AR = $(BIN)/avr-ar
COPY = $(BIN)/avr-objcopy

# avrdude
PORT = /dev/tty.usbserial-*
UPLOAD_RATE = 57600
AVRDUDE_PROGRAMMER = stk500v1

AVRDUDE_PATH = /usr/local/CrossPack-AVR/bin
AVRDUDE_CONF_PATH = /usr/local/CrossPack-AVR/etc

AVRDUDE = $(AVRDUDE_PATH)/avrdude

AVRDUDE_PORT = $(PORT)
AVRDUDE_WRITE_FLASH = -U flash:w:$(OUTPUT_DIR)/$(TARGET_NAME).hex

AVRDUDE_FLAGS = -V -F -C $(AVRDUDE_CONF_PATH)/avrdude.conf \
-p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) \
-b $(UPLOAD_RATE) -D



# set up all the include folders
INCLUDES =	-I$(CORE_DIR) -I$(VAR_DIR)										\
			$(foreach lib,$(LIBRARIES), -I$(LIBS_DIR)/$(lib))				\
			$(foreach inc,$(PROJECT_DIRS), -I$(inc)/)						\
			$(foreach inc,$(USER_INCLUDES),-I$(inc))

# create a list of all the obj files to create for the core library
CORE_OBJS = $(addprefix $(OUTPUT_DIR)/, $(addsuffix .o, $(notdir $(wildcard $(CORE_DIR)/*.cpp) $(wildcard $(CORE_DIR)/*.c) )))
CORE_LIB = $(OUTPUT_DIR)/core.a

# create a list of all the obj files to create for the library folders
LIB_OBJS = $(foreach lib, $(LIBRARIES), $(addprefix $(OUTPUT_DIR)/$(lib)/, $(addsuffix .o, $(notdir $(wildcard $(LIBS_DIR)/$(lib)/*.cpp) $(wildcard $(LIBS_DIR)/$(lib)/*.c)))))

# create a list of all the obj files to create for the project folders
PROJECT_OBJS = $(foreach folder, $(PROJECT_DIRS), $(addprefix $(OUTPUT_DIR)/$(folder)/, $(addsuffix .o, $(notdir $(wildcard $(folder)/*.cpp) $(wildcard $(folder)/*.c)))))

# create a list of dependency files (one for each project obj file)
DEPENDENCIES = $(PROJECT_OBJS:.o=.d)

# main build target
.PHONY: all
all: $(OUTPUT_DIR)/$(TARGET_NAME).hex
	@echo Finished building $<
	@echo
	
# rule to build the hex file
$(OUTPUT_DIR)/$(TARGET_NAME).hex: $(OUTPUT_DIR)/$(TARGET_NAME).elf
	@mkdir -p $(dir $@)
	@echo "Copying $@"
	@$(COPY) -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 $(OUTPUT_DIR)/$(TARGET_NAME).elf $(OUTPUT_DIR)/$(TARGET_NAME).eep 
	@$(COPY) -O ihex -R .eeprom $(OUTPUT_DIR)/$(TARGET_NAME).elf $(OUTPUT_DIR)/$(TARGET_NAME).hex 

# rule to build the elf file
$(OUTPUT_DIR)/$(TARGET_NAME).elf: $(CORE_LIB) $(LIB_OBJS) $(PROJECT_OBJS)
	@echo "Linking $@"
	@$(GCC) $(LINK_FLAGS) -o $(OUTPUT_DIR)/$(TARGET_NAME).elf $(LIB_OBJS) $(PROJECT_OBJS) $(CORE_LIB)

# rule to build the core.a library file	
$(CORE_LIB): $(CORE_OBJS)
	@for core_file in $(CORE_OBJS) ; do 		\
		echo Storing $$core_file ;				\
		$(AR) rcs $(CORE_LIB) $$core_file ;		\
	done
	
#include the dependencies, if they exist	
-include $(DEPENDENCIES)

# rule to build the project .cpp files
$(OUTPUT_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(GCC) $(CPPFLAGS) -I$(CORE_DIR) -I$(VAR_DIR) $(INCLUDES) -MMD $< -o $@
	
# rule to build the project .c files
$(OUTPUT_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(GCC) $(CFLAGS) -I$(CORE_DIR) -I$(VAR_DIR) $(INCLUDES) -MMD $< -o $@

# rule to build the core .cpp files
$(OUTPUT_DIR)/%.cpp.o: $(CORE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(GCC) $(CPPFLAGS) -I$(CORE_DIR) -I$(VAR_DIR) $(INCLUDES) $< -o $@
	
# rule to build the core .c files
$(OUTPUT_DIR)/%.c.o: $(CORE_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(GCC) $(CFLAGS) -I$(CORE_DIR) -I$(VAR_DIR) $(INCLUDES) $< -o $@
	
# rule to build the library source files
.SECONDEXPANSION:
LIB_SRC = $(LIBS_DIR)/$(basename $(subst $(OUTPUT_DIR)/,,$@))
$(LIB_OBJS): $$(LIB_SRC)
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(GCC) $(CPPFLAGS) -I$(CORE_DIR) -I$(VAR_DIR) $(INCLUDES) $< -o $@

size: $(OUTPUT_DIR)/$(TARGET_NAME).hex 
	@avr-size -C --mcu=atmega644p $(OUTPUT_DIR)/$(TARGET_NAME).elf

upload: $(OUTPUT_DIR)/$(TARGET_NAME).hex
	@echo "\n\n START UPLOAD \n\n"
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)

clean:
	@echo Cleaning...
	@-rm -f $(OUTPUT_DIR)/$(TARGET_NAME).eep
	@-rm -f $(OUTPUT_DIR)/$(TARGET_NAME).hex
	@-rm -f $(OUTPUT_DIR)/$(TARGET_NAME).elf
	@-rm -f $(CORE_LIB) $(CORE_OBJS) $(LIB_OBJS) $(PROJECT_OBJS) $(DEPENDENCIES)
	

rebuild: clean all
