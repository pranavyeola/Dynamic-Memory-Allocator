# Execution command- "./all"
CC=gcc

option=-c

all:	linkedlist.o myalloc.o
	$(CC) linkedlist.o myalloc.o -o all

myalloc.o: myalloc.c myalloc.h
	  $(CC) $(option) myalloc.c

linkedlist.o: linkedlist.c myalloc.h
	  $(CC) $(option) linkedlist.c

clean:
	rm -rf *o all
