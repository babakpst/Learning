# Download Images Challenge Makefile
CXX		 = g++
CXXFLAGS = -Wall
TARGET	 = download_images_challenge
SRC		 = download_images_challenge.cpp
LDLIBS	 = -lcurl

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)