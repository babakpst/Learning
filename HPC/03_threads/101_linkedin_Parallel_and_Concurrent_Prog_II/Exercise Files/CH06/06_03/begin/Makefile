# Matrix Multiply Solution Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = matrix_multiply_solution
SRC		 = matrix_multiply_solution.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)