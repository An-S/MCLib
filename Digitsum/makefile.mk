CC = gcc
LD = gcc
CC65 = cl65
LD65 = cl65
cflags = -O -c --std=c11 -g -Wall
cc65flags = -O -g -c
ldflags =
objects = digitsum.o
main = digitsum

%.o:  %.c
	$(CC) $(cflags) $< -o $@
	$(LD) $@ -o $(main).exe
	$(CC65) $(cc65flags) $< -o $@
	$(LD65)  $@ -o $(main).prg
  
all: $(objects)
	.\$(main).exe
	exit
	
clean: 
	-rm *.o 
	-rm *.exe
	
		