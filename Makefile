
CC = gcc
CXX = g++
CFLAGS = -Wall -g -O2
CXXFLAGS = -Wall -g -O2
LDFLAGS = -lm
PROGS = a.out

all: $(PROGS)

a.out: grafo.o lista.o heap.o catch_amalgamated.o testes.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

testes.o: testes.cpp grafo.h lista.h heap.h catch_amalgamated.hpp
catch_amalgamated.o: catch_amalgamated.cpp catch_amalgamated.hpp
grafo.o: grafo.c grafo.h lista.h
lista.o: lista.c lista.h
heap.o: heap.c grafo.h heap.h

clean:
	rm -f *.o a.out
