BIN	:= main
#flags
CUDA_INSTALL_PATH	:= /usr/local/cuda-11.2
INCLUDES		+= -I. -I$(CUDA_INSTALL_PATH)/include
LIBS			:= -L$(CUDA_INSTALL_PATH)/lib64
CFLAGS			:= -O3
LDFLAGS			:= -lrt -lm -lcudart -lcurand

#compilers
NVCC	:= nvcc
CC	:= g++
LINKER	:= nvcc

#files
C_SOURCES	:= $(wildcard *.c)
CU_SOURCES	:= $(wildcard *.cu)
HEADERS		:= $(wildcard *.h)
C_OBJS		:= $(patsubst %.c, %.o, $(C_SOURCES))
CU_OBJS		:= $(patsubst %.cu, %.o, $(CU_SOURCES))

$(BIN): clean $(C_OBJS) $(CU_OBJS) $(HEADERS)
	$(LINKER) -o $(BIN) $(CU_OBJS) $(C_OBJS) $(LDFLAGS) $(INCLUDES) $(LIBS)

$(C_OBJS): $(C_SOURCES) $(HEADERS)
	$(CC) -c $(C_SOURCES) $(CFLAGS) $(INCLUDES)

$(CU_OBJS): $(CU_SOURCES) $(HEADERS)
	$(NVCC) -c $(CU_SOURCES) $(INCLUDES)

run: $(BIN)
	LD_LIBRARY_PATH=$(CUDA_INSTALL_PATH)/lib ./$(BIN)

clean:
	rm -f $(BIN) *.o
