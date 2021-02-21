# Download Images Solution Makefile
CXX		 = g++
CXXFLAGS = -Wall
TARGET	 = download_images_solution
SRC		 = download_images_solution.cpp
LDLIBS	 = -lcurl

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)