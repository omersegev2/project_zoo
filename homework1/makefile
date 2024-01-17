CC = g++
CFLAGS = -std=c++11 -Wall

# List of source files
SRCS = main.cpp Zoo.cpp ZooKeeper.cpp Enclosure.cpp Animal.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Name of the executable
TARGET = main.exe

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp Zoo.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Zoo.o: Zoo.cpp Zoo.hpp Enclosure.hpp Animal.hpp
	$(CC) $(CFLAGS) -c $< -o $@

ZooKeeper.o: ZooKeeper.cpp ZooKeeper.hpp Enclosure.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Enclosure.o: Enclosure.cpp Enclosure.hpp Animal.hpp ZooKeeper.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Animal.o: Animal.cpp Animal.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
