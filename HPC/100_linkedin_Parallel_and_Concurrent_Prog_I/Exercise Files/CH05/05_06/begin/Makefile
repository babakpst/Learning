# Starvation Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = starvation_demo
SRC		 = starvation_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)