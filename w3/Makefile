# run : 
# make
# make run / ./met_test


cxx = g++
cxxflags = -std=c++17 -Wall -Wextra -Wshadow -pedantic -march=native

lib_name = libmet.so

src = met.cpp
obj = met.o
main = main.cpp
target = met_test


all: $(lib_name) $(target)


$(lib_name): $(obj)
	$(cxx) -shared -o $(lib_name) $(obj)


$(obj): $(src) met.h
	$(cxx) $(cxxflags) -c $(src) -o $(obj)


$(target): $(main) met.h
	$(cxx) $(cxxflags) $(main) -L. -lmet -o $(target) -Wl,-rpath,.


run: $(target)
	LD_LIBRARY_PATH=. ./$(target)


clean:
	rm -f $(obj) $(lib_name) $(target)