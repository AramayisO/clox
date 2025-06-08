PROJECT := clox

# ---------------------------------------------------------
#  Compiler
# ---------------------------------------------------------
CC     := clang
CFLAGS := -std=c17 -Wall -Werror -Wextra -pedantic

# ---------------------------------------------------------
# Directories and files
# ---------------------------------------------------------
SRC_DIR     := ./src
INCLUDE_DIR := ./include
BUILD_DIR   := ./obj
BIN_DIR     := ./bin
SRCS        := $(wildcard $(SRC_DIR)/*.c)
OBJS        := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
EXEC        := $(BIN_DIR)/$(PROJECT)

# ---------------------------------------------------------
# Targets
# ---------------------------------------------------------
.PHONY: debug release all run cleanup

debug: CFLAGS += -g -Og -DDEBUG
debug: all

release: CFLAGS += -O2
release: all

all: $(EXEC)

run: $(EXEC)
	$(EXEC)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

