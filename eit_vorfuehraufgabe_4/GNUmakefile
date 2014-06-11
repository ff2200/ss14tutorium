TARGETS += studentver 
OBJECTS += linkedlist.o readline.o student.o studentver.o
CC = gcc
CFLAGS = -g -Wall -std=gnu99

studentver: $(OBJECTS)

linkedlist.o: linkedlist.c linkedlist.h student.o

student.o: student.c student.h

readline.o: readline.c readline.h

.PHONY: clean
clean:
	rm $(OBJECTS) $(TARGETS) 

