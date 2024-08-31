# Check that given variables are set
check_defined = \
    $(strip $(foreach 1,$1, \
        $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
    $(if $(value $1),, \
      $(error Undefined $1$(if $2, ($2))))


# Main Makefile
V ?= 0 # Verbose (0: quiet, 1: print all)
Q  =
ifneq ($(V),1)
Q  = @
endif

TARGET_DIR   ?= 
TARGET_ARCH  ?= rv32imac
TARGET_PLAT  ?= esp32c6
TARGET_NAME   = $(basename $(notdir $(TARGET_DIR)))


BUILD_DIR   = build
INCLUDE_DIR = include
SRC_DIR     = arch/$(TARGET_ARCH) \
			  platform/$(TARGET_PLAT) \
			  $(TARGET_DIR) \
			  drivers


TOOLCHAIN_PATH ?= /root/.espressif/tools/riscv32-esp-elf/esp-13.2.0_20240530/riscv32-esp-elf/bin
TOOLCHAIN_NAME ?= riscv32-esp-elf

CC		= $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME)-gcc
LD		= $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME)-ld
OBJCOPY	= $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME)-objcopy
OBJDUMP	= $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME)-objdump

LDFLAGS   = -nostdlib
CFLAGS    = -Wall -ffreestanding
CFLAGS   += -march=$(TARGET_ARCH) -mabi=ilp32  -mcmodel=medlow
CFLAGS   += -I$(INCLUDE_DIR)
ASMFLAGS  = -I$(INCLUDE_DIR)
MACROS    = -DTARGET_ARCH=$(TARGET_ARCH) \
			-DTARGET_PLAT=$(TARGET_PLAT) \


LSCRIPT = arch/$(TARGET_ARCH)/lscript.ld

SRCS  = $(shell find $(SRC_DIR) -name '*.c')
ASMS  = $(shell find $(SRC_DIR) -name '*.S')
OBJS  = $(addprefix $(BUILD_DIR)/,$(SRCS:%.c=%.c.o))
OBJS += $(addprefix $(BUILD_DIR)/,$(ASMS:%.S=%.s.o))
ELF   = $(BUILD_DIR)/$(TARGET_NAME).elf
BIN   = $(BUILD_DIR)/$(TARGET_NAME).bin
DASM  = $(BUILD_DIR)/$(TARGET_NAME).dasm


all: dir $(BIN) $(DASM)

SUB_DIR = $(dir $(SRCS) $(ASMS)) 
MK_DIR  = $(addprefix $(BUILD_DIR)/,$(SUB_DIR))

dir:
	$(call check_defined, TARGET_DIR)
	@mkdir -p $(MK_DIR)

$(BIN): $(ELF)
	$(Q) $(OBJCOPY) $(ELF) -O binary $@

$(DASM): $(ELF)
	$(Q) $(OBJDUMP) -D $(ELF) > $@

$(ELF): $(LSCRIPT) $(OBJS)
	$(Q) $(LD) $(LDFLAGS) -T $(LSCRIPT) -o $(ELF) $(OBJS)

$(BUILD_DIR)/%.c.o: %.c
	$(Q) $(CC) $(CFLAGS) $(MACROS) -c $< -o $@

$(BUILD_DIR)/%.s.o: %.S
	$(Q) $(CC) $(ASMFLAGS) $(MACROS) -c $< -o $@

clean:
ifdef TARGET_DIR
	$(Q)rm -rf $(BUILD_DIR)/$(TARGET_DIR)
	$(Q)rm -rf $(ELF) $(BIN)
else
	$(Q)rm -rf $(BUILD_DIR)
endif

tags:
	@ctags -R
