OBJS = main.cpp archivos.o conversion.o compara.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall $(DEBUG) --pedantic -c
LFLAGS = -Wall --pedantic $(DEBUG)
TARGET = main
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
archivos.o: archivos.hh archivos.cpp
conversion: conversion.hh conversion.cpp
compara: compara.hh compara.hh
	$(CC) $(CFLAGS) archivos.cpp conversion.cpp compara.cpp
clean:
	rm -f *.o $(TARGET)
