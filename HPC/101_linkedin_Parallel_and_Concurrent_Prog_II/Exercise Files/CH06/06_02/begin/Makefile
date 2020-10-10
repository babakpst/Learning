# Matrix Multiply Challenge Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = matrix_multiply_challenge
SRC		 = matrix_multiply_challenge.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)