CXX = g++
CXXFLAGS = -pedantic -Wall
LDLIBS = -lm -lutil

SRCS = $(wildcard *.cpp)

main: $(SRCS) $(wildcard *.h)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDLIBS)

clean:
	rm -f main

.PHONY: clean
