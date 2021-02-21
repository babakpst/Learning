# Merge Sort Solution Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = merge_sort_solution
SRC		 = merge_sort_solution.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)