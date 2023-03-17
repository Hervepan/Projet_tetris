CC=g++
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

SRC_DIR=.
OBJ_DIR=./linker

SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

EXECUTABLE=$(SRC_DIR)/main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)