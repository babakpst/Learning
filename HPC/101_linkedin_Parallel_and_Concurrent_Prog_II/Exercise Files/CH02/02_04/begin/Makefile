# Barrier Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = barrier_demo
SRC		 = barrier_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)