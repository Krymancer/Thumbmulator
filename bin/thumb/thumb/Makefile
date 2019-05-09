CROSS_COMPILE ?= arm-none-eabi-

all: startup.s
	$(CROSS_COMPILE)as *.s -o startup.o
	$(CROSS_COMPILE)ld -o startup -T memmap startup.o
	$(CROSS_COMPILE)objcopy startup startup.bin -O binary
	$(CROSS_COMPILE)objdump -DSx -b binary -marm startup.bin > startup.lst
	cp startup.bin /tftpboot/startup.bin

clean:
	rm *.o *.bin *.lst
