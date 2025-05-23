#########################################
#		Compile Program Executable      #
#########################################

# Define source and header directories
SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGET := myprogram.exe

# Compiler and flags
COMPILE := gcc -c
LINK := gcc
CFLAGS := -Wall -I$(INCDIR)

#Source Files: recursive depth
SOURCES := $(shell find $(SRCDIR) -name "*.c")

#Create List of objects to be created from source files
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))


# Default target
all: $(TARGET)

# Compile object files.
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
# First, each object directory is created in the structure of the src directory
	@mkdir -p $(dir $@)
	$(COMPILE) $(CFLAGS) $< -o $@

# Link object files
$(TARGET): $(OBJECTS)
	$(LINK) $(OBJECTS) -o $@

# Clean build files
clean:
	rm -rf $(BUILDDIR)
	rm $(TARGET)


#########################################
#		Compile Test Suite  			#
#########################################

# Define directories
TESTDIR := test
RESULTSDIR := $(BUILDDIR)/results


# find all test files
TESTSOURCES := $(shell find $(TESTDIR) -name "*.c")

# Results
RESULTS := $(patsubst $(TESTDIR)test_%.c, $(RESULTSDIR), $(TESTSOURCES))

PASSED := `grep -s PASS $(RESULTSDIR)*.txt`
FAIL := `grep -s FAIL $(RESULTSDIR)*.txt`
IGNORE := `grep -s IGNORE $(RESULTSDIR)*.txt`

test: $