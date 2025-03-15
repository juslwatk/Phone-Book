CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = phonebook
OBJS = main.o phonebook.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp phonebook.h
	$(CXX) $(CXXFLAGS) -c main.cpp

phonebook.o: phonebook.cpp phonebook.h
	$(CXX) $(CXXFLAGS) -c phonebook.cpp

clean:
	rm -f $(TARGET) $(OBJS)
