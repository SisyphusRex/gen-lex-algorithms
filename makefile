#########################################
#		Compile Program Executable      #
#########################################

# Define source and header directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
TARGET := myprogram.exe

# Compiler and flags
COMPILE := gcc -c # compile but do not link: outputs .o
LINK := gcc
CFLAGS := -Wall -I$(INC_DIR)

#Source Files: recursive depth
SOURCES := $(shell find $(SRC_DIR) -name "*.c")

#Create List of objects to be created from source files
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))


# Compile object files.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# First, each object directory is created in the structure of the src directory
	@mkdir -p $(dir $@)
	$(COMPILE) $(CFLAGS) $< -o $@
# -o puts

# Link object files
$(TARGET): $(OBJECTS)
	$(LINK) $(OBJECTS) -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
	rm $(TARGET)


#########################################
#		Compile Test Suite  			#
#########################################

# Define directories
TEST_DIR := test
RESULTS_DIR := $(BUILD_DIR)/results
UNITY_DIR := unity
TEST_TARGET := test.exe
BUILD_PATHS :=

# Compiler and Flags
TEST_CFLAGS := -I$(UNITY_DIR) -I$(INC_DIR) -D TEST -Wall


# find all test files
TEST_SOURCES := $(shell find $(TEST_DIR) -name "*.c")

# Results
RESULTS := $(patsubst $(TESTDIR)test_%.c, $(RESULTSDIR)test_%.txt, $(TESTSOURCES))

PASSED := `grep -s PASS $(RESULTSDIR)*.txt`
FAIL := `grep -s FAIL $(RESULTSDIR)*.txt`
IGNORE := `grep -s IGNORE $(RESULTSDIR)*.txt`

test: $