# Define source and header directories
SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGET := myprogram

# Compiler and flags
CC := gcc
CFLAGS :=

myprog.exe : main.o program.o
	gcc main.o program.o -o myprog.exe

main.o : main.c program.h
	gcc -Wall -I -c main.c

program.o : program.c program.h
	gcc -Wall -I -c program.c

clean :
	rm *.o myprog.exe