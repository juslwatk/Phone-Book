# A Makefile for building the phonebook program

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
OBJ = main.o phonebook.o

all: phonebook_app

phonebook_app: $(OBJ)
	$(CXX) $(CXXFLAGS) -o phonebook_app $(OBJ)

main.o: main.cpp phonebook.h
	$(CXX) $(CXXFLAGS) -c main.cpp

phonebook.o: phonebook.cpp phonebook.h
	$(CXX) $(CXXFLAGS) -c phonebook.cpp

clean:
	rm -f *.o phonebook_app
