cxx = g++

rootflags  := $(shell root-config --cflags)
rootlibs    := $(shell root-config --libs)

cxxflags = -std=c++17 -Wall -Wextra -Wshadow -pedantic -march=native $(rootflags)
ldflags  = $(rootlibs)

targets = gen_data plot_data

srcs = gen_data.cpp plot_data.cpp

objs = $(srcs:.cpp=.o)

all: $(targets)

gen_data: gen_data.o
	$(cxx) -o $@ $^ $(ldflags)

plot_data: plot_data.o
	$(cxx) -o $@ $^ $(ldflags)

%.o: %.cpp
	$(cxx) $(cxxflags) -c $< -o $@

run_gen: gen_data
	./gen_data

run_plot: plot_data
	./plot_data

clean:
	rm -f $(targets) $(objs) data.root histogram.png