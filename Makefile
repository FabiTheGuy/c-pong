SRC_DIR = ./src
INC_DIR = ./include
BIN_DIR = ./bin

COMPILER = clang
C_FLAGS = -I$(INC_DIR) -std=c99 -Wall -Wpedantic -Werror $(shell pkgconf --cflags raylib)
LD_FLAGS = -lm $(shell pkgconf --libs raylib)
COMPILE = $(COMPILER) $(C_FLAGS) $(LD_FLAGS)

SRCS = $(wildcard $(SRC_DIR)/*.c)
TARGET = main


all: build run clean

run:
	./$(BIN_DIR)/$(TARGET)

build: bin
	$(COMPILE) -o $(BIN_DIR)/$(TARGET) $(SRCS)

clean:
	rm -r $(BIN_DIR)

bin:
	@mkdir -p $(BIN_DIR)

