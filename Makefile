CXX_FLAG = --std=c++11 -g

all: tests main

tests: tests.o movies.o
	g++ $(CXX_FLAG) -o tests tests.o movies.o

main: main.o movies.o utility.o
	g++ $(CXX_FLAG) -o runMovies main.o movies.o utility.o

tests.o: tests.cpp
	g++ -c $(CXX_FLAG) tests.cpp

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

movies.o: movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

clean:
	rm -f tests runMovies utility *.o