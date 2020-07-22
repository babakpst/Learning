# Deadlock Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = deadlock_demo
SRC		 = deadlock_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)