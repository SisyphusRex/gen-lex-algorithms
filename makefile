# Define source and header directories
SRCDIR := src
SRCSUBDIRS := $(shell find $(SRCDIR) -mindepth 1 -type d)
INCDIR := include
BUILDDIR := build
TARGET := myprogram.exe

# Compiler and flags
CC := gcc
CFLAGS := -Wall -g -I$(INCDIR)

#Source Files
SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

#
SUBDIRS := $(patsubst $(SRCDIR)/%, %, $(SRCSUBDIRS))

# Default target
all: $(TARGET)

print_files:
	$(info $(SUBDIRS))



# Compile object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)/modules
	$(CC) $(CFLAGS) -c $< -o $@




# Link object files
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

