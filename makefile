OUT = main

BIN_FILE = bin
SRC_FILE = src

SRC = $(wildcard $(SRC_FILE)/*.c) $(wildcard $(SRC_FILE)/**/*.c) $(wildcard $(SRC_FILE)/**/**/*.c) $(wildcard $(SRC_FILE)/**/**/**/*.c)

CFLAGS = -Wall -g3 -O0 -std=c17
LIBS = -lm -lraylib

CC = gcc

.PHONY: buildAll run clean rebuild

buildAll: $(SRC)
	@echo "Building all files..."
	@mkdir -p $(BIN_FILE)
	@$(CC) $(SRC) -o $(BIN_FILE)/$(OUT) $(CFLAGS) $(LIBS)
	@echo "Done!"

run: $(BIN_FILE)/$(OUT)
	@echo "Running..."
	@./$(BIN_FILE)/$(OUT)

clean:
	@echo "Cleaning..."
	@rm -rf $(BIN_FILE)
	@echo "Done!"

rebuild: clean buildAll
	@echo "Rebuilding..."
	@echo "Done!"