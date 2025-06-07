PROJECT := lox

# ---------------------------------------------------------
#  Compiler
# ---------------------------------------------------------
CC := clang
CFLAGS := -std=c17 -Wall -Werror -Wextra -pedantic

# ---------------------------------------------------------
# Directories and files
# ---------------------------------------------------------
SRC_DIR := ./src
OBJ_DIR := ./obj
BIN_DIR := ./bin
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))
EXEC := $(BIN_DIR)/$(PROJECT)

# ---------------------------------------------------------
# Targets
# ---------------------------------------------------------
.PHONY: debug release all setup cleanup

debug: CFLAGS += -g -Og -DDEBUG
debug: all

release: CFLAGS += -O2
release: all

test:
	echo "test build not yet implemented"

all: setup $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

setup:
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

