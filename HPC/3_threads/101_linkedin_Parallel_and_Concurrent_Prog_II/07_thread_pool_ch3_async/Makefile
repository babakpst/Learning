# Livelock Demo Makefile
CXX	 = g++
CXXFLAGS = -Wall 
TARGET	 = main
SRC	 = main.cpp
LDLIBS   = -lboost_system

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
