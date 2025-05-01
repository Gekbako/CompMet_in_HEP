CXX = g++
CXXFLAGS = -O2 -Wall

PYTHIA8 = $(shell pythia8-config --cxxflags --libs)
ROOT = $(shell root-config --cflags --libs)

all: simulate

simulate: simulate.cpp
	$(CXX) $(CXXFLAGS) simulate.cpp -o simulate $(PYTHIA8) $(ROOT)

clean:
	rm -f simulate *.root
