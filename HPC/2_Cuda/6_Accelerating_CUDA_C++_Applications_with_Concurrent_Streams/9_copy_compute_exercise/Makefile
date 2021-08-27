CUDACXX=nvcc
#CUDACXXFLAGS=-arch=sm_70 -O3
CUDACXXFLAGS=-O3
#CXXFLAGS=-march=native -fopenmp
NSYS=nsys profile
NSYSFLAGS=--stats=true --force-overwrite=true

all: streams

streams: streams.cu
	#$(CUDACXX) $(CUDACXXFLAGS) -Xcompiler="$(CXXFLAGS)" streams.cu -o streams
	$(CUDACXX) $(CUDACXXFLAGS) streams.cu -o streams

streams_solution: streams_solution.cu
	#$(CUDACXX) $(CUDACXXFLAGS) -Xcompiler="$(CXXFLAGS)" streams_solution.cu -o streams_solution
	$(CUDACXX) $(CUDACXXFLAGS) streams_solution.cu -o streams_solution

profile: streams
	$(NSYS) $(NSYSFLAGS) -o streams-report ./streams

profile_solution: streams_solution
	$(NSYS) $(NSYSFLAGS) -o streams-solution-report ./streams_solution

clean:
	rm -f streams streams_solution *.qdrep *.sqlite

