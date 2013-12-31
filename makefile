all: lexico

lexico: main.o apc.o 
	g++ main.o apc.o -o lexico

main.o: main.cpp 
	g++ -c main.cpp

apc.o: apc.cpp apc.h
	g++ -c apc.cpp


clean:
	rm -rf *o lexico