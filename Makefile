thing.o: thing.cpp thing.h
	g++ -c thing.cpp

func.o: func.cpp func.h
	g++ -c func.cpp

compience: main.cpp thing.o func.o
	g++ -o compience main.cpp thing.o func.o
