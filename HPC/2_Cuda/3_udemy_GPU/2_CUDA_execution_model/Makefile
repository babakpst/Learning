CC=g++
CXXFLAGS= -fopenmp -O3 -Wextra -std=c++17
CUDAFLAGS= -std=c++17 -arch=sm_20
LIBS= -lopenblas -lpthread -lcudart -lcublas
LIBDIRS=-L/usr/local/cuda-7.5/lib64
INCDIRS=-I/usr/local/cuda-7.5/include
PROGRAM= test
%.o: %.cu
     nvcc -dc $(CUDAFLAGS) $< -o $@
all: matrix_cuda.o
        $(CC) -o $(PROGRAM) matrix_blas.cpp alg.cpp test.cpp matrix_cuda.o $(LIBDIRS) $(INCDIRS) $(LIBS) $(CXXFLAGS)
.PHONY: clean
clean:
    rm -rf $(PROGRAM) *.o