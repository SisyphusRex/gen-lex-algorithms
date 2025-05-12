# Define source and header directories
SRCDIR := src
SRCSUBDIRS := $(shell find $(SRCDIR)/ -type d)
VPATH := $(SRCSUBDIRS)
INCDIR := include
BUILDDIR := build
TARGET := myprogram.exe

# Compiler and flags
CC := gcc
CFLAGS := -Wall -g -I$(INCDIR)

#Source Files
SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES)) $(patsubst $(SRCDIR)/*/%c, $(BUILDDIR)/*/%.o, $(SOURCES))

# Default target
all: $(TARGET)

print_files:
	$(info $(SRCSUBDIRS))

# Compile object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@




# Link object files
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

