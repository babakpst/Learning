# Livelock Demo Makefile
CXX	 = g++
CXXFLAGS = -Wall -std=c++17 
TARGET	 = main
SRC	 = main.cpp
LDLIBS   = -lboost_system -lboost_filesystem

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
