## Generic makefile by Heedong Goh <wellposed@gmail.com> ########
## Name of the executable
NAME = main

## Complier
CXX = g++

## Source extension
SEXT = cpp

## Source path
SDIR = .

## Output path
ODIR = .

## Library path
LIBS = -L/usr/local/lib

## Include path
INC = -I./

## General compile option
CXXFLAGS = -Wall -Wextra -pedantic-errors -std=c++17

## Release option
RFLAGS = -O3

## DO NOT CHANGE ################################################
.PHONY: all clean dep test help

TARGET = $(ODIR)/$(NAME)
SRCS = $(wildcard $(SDIR)/*.$(SEXT))
OBJS = $(SRCS:.$(SEXT)=.o)

all : $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(LIBS) $(OBJS) -o $(TARGET) 
	rm $(OBJS)
$(OBJS): $(SRCS)
	mkdir -p $(ODIR)
	$(CXX) $(CXXFLAGS) $(RFLAGS) $(INC) -c $(SRCS)


debug: CXXFLAGS += -DDEBUG -g -O0
debug: all

filesystem: CXXFLAGS += -lboost_system -lboost_filesystem
filesystem: all

release: CXXFLAGS += -RFLAGS
release: all


cln:
	rm $(TARGET)
test:
	@echo "Sources are: " $(SRCS)
	@echo "Objects are: " $(OBJS)
help:
	@echo "usage:"
	@echo "      make -> build"
	@echo "      make dep -> generates dependencies using gccmakedep"
	@echo "      make clean -> removes objects, executable"
	@echo "      make test -> lists source files"
dep :
	gccmakedep $(INC) $(SRCS)
#################################################################
