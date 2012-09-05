#!/usr/bin/make -f

CC = gcc
CFLAGS = -Wall -ggdb -larchive -lsqlite3

all : messages.o list.o main.o
	$(CC) messages.o list.o main.o -o vpm

clean :
	rm -f *.o vpm