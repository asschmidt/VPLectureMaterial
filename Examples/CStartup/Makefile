all: bin

bin: firmware
	arm-none-eabi-objcopy -O binary firmware.elf firmware.bin

firmware: main.o startup.o
	arm-none-eabi-gcc -nostdlib -mcpu=cortex-m4 -mthumb --specs=nano.specs --specs=nosys.specs -Wl,-Map firmware.map -Wl,-T firmware.ld -Wl,--start-group -lc -lgcc -lm -lnosys -Wl,--end-group -o firmware.elf main.o startup.o

startup.o: startup.s
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -g -o startup.o startup.s

main.o: main.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -c -g3 -O0 -o main.o main.c

clean:
	rm -f firmware.elf *.bin *.o *.map