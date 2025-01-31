CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wshadow -pedantic -march=native

SRC = hello_world_number.cpp
TARGET = e1.exe

HEADERS =

.PHONY: clean debug

main: $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -DNDEBUG -Ofast -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

debug: $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -DDEBUG -g -o $(TARGET) $(SRC)

%.hpp:
