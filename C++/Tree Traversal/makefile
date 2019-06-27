## Generic makefile by Heedong Goh <wellposed@gmail.com> ########
## Name of the executable
NAME = main
## Complier
CC = g++
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
CFLAGS = -Wall -Wextra -pedantic -std=c++14
## Release option
RFLAGS = -O3
## DO NOT CHANGE ################################################
.PHONY: all clean dep test help

TARGET = $(ODIR)/$(NAME)
SRCS = $(wildcard $(SDIR)/*.$(SEXT))
OBJS = $(SRCS:.$(SEXT)=.o)

all : $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LIBS) $(OBJS) -o $(TARGET) 
	rm $(OBJS)
$(OBJS): $(SRCS)
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(RFLAGS) $(INC) -c $(SRCS)
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
