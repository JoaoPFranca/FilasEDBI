main: main.o
		g++ -o main main.o

main.o: main.cpp filas.h
		g++ -O3 -g -std=c++17 -Wall -pedantic -c main.cpp