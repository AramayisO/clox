PROJECT := clox

# ---------------------------------------------------------
# Directories and files
# ---------------------------------------------------------
SRC_DIR     := ./src
INCLUDE_DIR := ./include
BUILD_DIR   := ./build
BIN_DIR     := ./bin
TEST_DIR    := ./test
SRCS        := $(wildcard $(SRC_DIR)/*.c)
OBJS        := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
EXEC        := $(BIN_DIR)/$(PROJECT)
TEST_SRCS   := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS   := $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))
TEST_EXEC   := $(BIN_DIR)/test

# ---------------------------------------------------------
#  Compiler
# ---------------------------------------------------------
CC      := clang
CFLAGS  := -std=c17 -Wall -Werror -Wextra -pedantic -I$(INCLUDE_DIR)
LDFLAGS :=

# ---------------------------------------------------------
# Targets
# ---------------------------------------------------------
.PHONY: debug release test all run clean

debug: CFLAGS += -g -Og -DDEBUG
debug: all

release: CFLAGS += -O2
release: all

test: CFLAGS += -g -Og -DDEBUG -I./lib/Unity/src
test: LDFLAGS += -L./lib/Unity/build -lunity
test: $(TEST_EXEC)

all: $(EXEC)

run: all
	$(EXEC)

run_test: test
	$(TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

$(EXEC): $(OBJS)
	@echo $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $? -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXEC): $(TEST_OBJS) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
