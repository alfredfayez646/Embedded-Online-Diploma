#@copyright : Alfred Fayez

CC = arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 -g
INCS  =-I .
LIBS  =
SRC   =$(wildcard *.c)
OBJ   =$(SRC:.c=.o)
AS    =$(wildcard *.s)
ASOBJ =$(AS:.s=.o)
Project_Name=HighPessureDetection

all: $(Project_Name).bin
	@echo "==========Build is Done=========="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_Name).elf: $(ASOBJ) $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $(Project_Name).elf -Map=Map_file.map
	cp $(Project_Name).elf $(Project_Name).axf
	
$(Project_Name).bin: $(Project_Name).elf 	
	$(CC)objcopy.exe -O binary $(Project_Name).elf $(Project_Name).bin

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin