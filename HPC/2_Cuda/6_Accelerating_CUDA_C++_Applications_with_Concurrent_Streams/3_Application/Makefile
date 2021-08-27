CUDACXX=nvcc
#CUDACXXFLAGS=-arch=sm_70 -O3
CUDACXXFLAGS=-O3
#CXXFLAGS=-march=native -fopenmp

all: baseline

baseline: baseline.cu
#	$(CUDACXX) $(CUDACXXFLAGS) -Xcompiler="$(CXXFLAGS)" baseline.cu -o baseline
	$(CUDACXX) $(CUDACXXFLAGS) baseline.cu -o baseline

clean:
	rm -f baseline

