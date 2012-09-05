#!/usr/bin/make -f

DESTDIR =
CC = gcc
CFLAGS = -Wall -ggdb -larchive -lsqlite3

all : messages.o tools.o list.o main.o
	$(CC) -static messages.o tools.o list.o main.o -o vpm

clean :
	rm -f *.o vpm

install :
	install -m 0755 vpm $(DESTDIR)/usr/bin/vpm
