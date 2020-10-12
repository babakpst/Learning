# Measure Speedup Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = measure_speedup_demo
SRC		 = measure_speedup_demo.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)