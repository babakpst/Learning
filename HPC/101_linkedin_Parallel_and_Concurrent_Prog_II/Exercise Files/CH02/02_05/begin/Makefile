# Latch Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = latch_demo
SRC		 = latch_demo.cpp
LDLIBS	 = -lboost_thread -lboost_system

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)