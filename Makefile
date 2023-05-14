# Makefile for OS Project

# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -std=c++20 #-Wall 

# Linker flags
LDFLAGS = #-lncurses

# Executable name

extra.out:	extra.cpp
	$(CC) $^ -o $@ $(LDFLAGS) $(CFLAGS) 

clean:
	rm -f *.o *.out