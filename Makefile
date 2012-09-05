#!/usr/bin/make -f

DESTDIR =
CC = gcc
CFLAGS = -Wall -ggdb
LDFLAGS = -larchive -lsqlite3

all : messages.o tools.o common.o libarchive.o list.o main.o
	$(CC) $(LDFLAGS) messages.o tools.o common.o libarchive.o list.o main.o -o vpm

clean :
	rm -f *.o vpm

install :
	install -m 0755 vpm $(DESTDIR)/usr/bin/vpm
