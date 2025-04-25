CXX = g++
CXXFLAGS = -std=c++17

all: phonebook

phonebook: main.o phonebook.o
	$(CXX) $(CXXFLAGS) -o phonebook main.o phonebook.o

main.o: main.cpp phonebook.h
	$(CXX) $(CXXFLAGS) -c main.cpp

phonebook.o: phonebook.cpp phonebook.h
	$(CXX) $(CXXFLAGS) -c phonebook.cpp

clean:
	rm -f *.o phonebook
