# Race Condition Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = race_condition_demo
SRC		 = race_condition_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)