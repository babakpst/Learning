# Condition Variable Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = condition_variable_demo
SRC		 = condition_variable_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)