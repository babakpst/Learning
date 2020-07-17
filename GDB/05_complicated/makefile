CXX      := -c++
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -Wextra #-Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := main
INCLUDE  := -Iinclude/
LIBS     := -L/usr/local/lib
SRC      :=                      \
	$(wildcard src/*/*.cpp) \
	$(wildcard src/*.cpp)         \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

##==========================================
.PHONY: all build clean debug release test help dep

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

test:
	@echo "Sources are: " $(SRC)
	@echo "Objects are: " $(OBJECTS)

help:
	@echo "usage:"
	@echo "      make         -> build"
	@echo "      make debug   -> debug executable"
	@echo "      make release -> release executable"
	@echo "      make dep     -> generates dependencies using gccmakedep"
	@echo "      make clean   -> removes objects, executable"
	@echo "      make test    -> lists source files"

dep :
	gccmakedep $(INC) $(SRCS)
