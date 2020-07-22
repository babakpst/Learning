# Abandoned Lock Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = abandoned_lock_demo
SRC		 = abandoned_lock_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)