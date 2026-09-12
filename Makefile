PROJECT := $(CURDIR)
BUILD := $(PROJECT)/build
CC := gcc
LD := ld
NASM := nasm

CFLAGS := -m32 -ffreestanding -fno-pie -fno-stack-protector -fno-builtin \
          -nostdlib -nostartfiles -nodefaultlibs

all: iso

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/entry.o: boot/entry.asm | $(BUILD)
	$(NASM) -f elf32 $< -o $@

$(BUILD)/kernel.o: kernel/kernel.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/kernel.bin: $(BUILD)/entry.o $(BUILD)/kernel.o config/linker.ld
	$(LD) -m elf_i386 -T config/linker.ld \
		-o $@ $(BUILD)/entry.o $(BUILD)/kernel.o

iso: $(BUILD)/kernel.bin
	rm -rf $(BUILD)/iso
	mkdir -p $(BUILD)/iso/boot/grub
	cp $(BUILD)/kernel.bin $(BUILD)/iso/boot/kernel.bin
	cp config/grub/grub.cfg $(BUILD)/iso/boot/grub/grub.cfg
	grub-mkrescue -o $(BUILD)/jroc.iso $(BUILD)/iso >/dev/null 2>&1
	@echo
	@echo "=========================================="
	@echo "   J-ROC XCORE BUILD SUCCESSFUL"
	@echo "=========================================="
	@echo "ISO: $(BUILD)/jroc.iso"

clean:
	rm -rf $(BUILD)/*

run: iso
	qemu-system-i386 -cdrom $(BUILD)/jroc.iso

.PHONY: all iso clean run
