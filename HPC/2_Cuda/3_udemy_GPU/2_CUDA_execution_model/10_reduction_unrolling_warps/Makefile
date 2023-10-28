# Compiler
CC := g++
NVCC := nvcc

# Directories
SRC_DIR := ./
OBJ_DIR := obj
BIN_DIR := bin

# Source files
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
CU_FILES := $(wildcard $(SRC_DIR)/*.cu)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES))
OBJ_FILES += $(patsubst $(SRC_DIR)/%.cu, $(OBJ_DIR)/%.cu.o, $(CU_FILES))

# Compiler flags
CFLAGS := -std=c++17
LDFLAGS :=
NVCCFLAGS := -arch=sm_61

# Target executable
TARGET := $(BIN_DIR)/reduce

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(NVCC) $^ -o $@ $(LDFLAGS)

# Compile C++ source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile CUDA source files
$(OBJ_DIR)/%.cu.o: $(SRC_DIR)/%.cu
	@mkdir -p $(@D)
	$(NVCC) $(NVCCFLAGS) -c $< -o $@

# Clean up
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

# Dependency tracking (for header files)
-include $(OBJ_FILES:.o=.d)

# Generate dependency files
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -M $(CFLAGS) $< | sed 's,\($*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@ : ,g' > $@

# Generate dependency files for CUDA source files
$(OBJ_DIR)/%.cu.d: $(SRC_DIR)/%.cu
	@mkdir -p $(@D)
	$(NVCC) -M $(NVCCFLAGS) $< | sed 's,\($*\)\.cu.o[ :]*,$(OBJ_DIR)/\1.cu.o $@ : ,g' > $@
