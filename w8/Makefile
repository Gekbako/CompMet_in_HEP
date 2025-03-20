CXX = g++
CXXFLAGS = `pythia8-config --cxxflags`
LDFLAGS = `pythia8-config --ldflags --libs`

TARGET = p1
SRC = p1.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
