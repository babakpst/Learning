# Merge Sort Challenge Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = merge_sort_challenge
SRC		 = merge_sort_challenge.cpp
LDLIBS	 = 

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)