# Divide and Conquer Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = divide_and_conquer_demo
SRC		 = divide_and_conquer_demo.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)