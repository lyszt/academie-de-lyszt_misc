CXX = g++
CXXFLAGS = -pedantic -Wall
LDLIBS = -lm -lutil

SRCS = main.cpp $(wildcard src/*/*.cpp)

main: $(SRCS) $(wildcard src/*/*.h)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDLIBS)

clean:
	rm -f main

.PHONY: clean
