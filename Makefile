main: main.o HugeInt.o
	g++ -o main main.o HugeInt.o

main.o: main.cpp
	g++ -c main.cpp

HugeInt.o: HugeInt.h HugeInt.cpp
	g++ -c HugeInt.cpp
