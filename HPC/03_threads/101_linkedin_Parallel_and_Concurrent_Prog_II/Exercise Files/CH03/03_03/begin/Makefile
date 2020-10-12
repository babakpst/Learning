# Thread Pool Demo Makefile
CXX		 = g++
CXXFLAGS = -Wall
TARGET	 = thread_pool_demo
SRC		 = thread_pool_demo.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)