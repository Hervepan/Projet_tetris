CC=g++
CFLAGS=-c
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
SOURCES=tetromino.cpp main.cpp drawing.cpp board.cpp
OBJECTS=$(addprefix linker/,$(SOURCES:.cpp=.o))
EXECUTABLE=linker/main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

linker/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)