# Future Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = future_demo
SRC		 = future_demo.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)