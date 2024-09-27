CC = gcc
CFLAGS = -Isrc -Wall
LDFLAGS =
LIBS =
SRC_DIR = src
TESTS_DIR = tests
BUILD_DIR = build

# Automatically find source files and create a list of object files in the build directory
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Automatically find all test suite source files within the tests directory
TEST_SUITES_SRCS = $(shell find $(TESTS_DIR) -name '*.c')

# Test suite entry point
TEST_SUITE = $(BUILD_DIR)/test_suite

.PHONY: all clean test debug

all: test

test: $(TEST_SUITE)
	@./$(TEST_SUITE).o

debug: clean
debug: CFLAGS += -g
debug: test

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Consolidated rule to compile the main test suite executable
$(TEST_SUITE): $(TESTS_DIR)/test_suite.c $(TEST_SUITES_SRCS) $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(TESTS_DIR)/test_suite.c $(OBJS) -o $@.o $(LIBS)

clean:
	rm -rf $(BUILD_DIR)
