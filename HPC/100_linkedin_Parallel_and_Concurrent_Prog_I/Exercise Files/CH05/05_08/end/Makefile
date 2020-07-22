# Livelock Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = livelock_demo
SRC		 = livelock_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)