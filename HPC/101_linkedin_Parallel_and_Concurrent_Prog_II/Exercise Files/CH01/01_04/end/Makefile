# Producer Consumer Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = producer_consumer_demo
SRC		 = producer_consumer_demo.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)