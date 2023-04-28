# Makefile for OS Project

# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -std=c++20 #-Wall 

# Linker flags
LDFLAGS = #-lncurses

# Executable name

main.out:	main.cpp
	$(CC) $^ -o $@ $(LDFLAGS) $(CFLAGS) 

clean:
	rm -f *.o *.out