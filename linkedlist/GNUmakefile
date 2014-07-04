TARGETS += sllMain
OBJECTS += singlelinkedlist.o sllMain.o

CC = gcc
CFLAGS = -ggdb -Wall -std=gnu99

all: $(TARGETS)

sllMain: $(OBJECTS)

$(OBJECTS): singlelinkedlist.h


.PHONY: clean
clean:
	rm $(OBJECTS) $(TARGETS)

