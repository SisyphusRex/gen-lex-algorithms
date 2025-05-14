# Define source and header directories
SRCDIR := src
SRCSUBDIRS := $(shell find $(SRCDIR) -mindepth 1 -type d)
INCDIR := include
BUILDDIR := build
TARGET := myprogram.exe

# Compiler and flags
CC := gcc
CFLAGS := -Wall -g -I$(INCDIR)

#Source Files: Search depth of 2
SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c)
#Source Files: recursive depth
SOURCES2 := $(shell find $(SRCDIR) -name "*.c")

#Create List of objects to be created from source files
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES2))

#Subdirectories without src prefix
SUBDIRS := $(patsubst $(SRCDIR)/%, %, $(SRCSUBDIRS))

# Default target
all: $(TARGET)

print_files:
	$(info $(SOURCES2))



# Compile object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@




# Link object files
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)

