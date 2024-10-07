# Compiler
CC=g++

# Compilation flags
CFLAGS= -std=c++17 -Wall

# Source directories
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

# Find all .cpp files in src/ and its subdirectories
SRC=$(shell find $(SRC_DIR) -name '*.cpp')

# Generate corresponding .o files in obj/
OBJ=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# The final executable
EXEC=$(BIN_DIR)/exe

# Default target
all: $(EXEC)

# Rule to link object files and create the final executable
$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $@

# Rule to compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
