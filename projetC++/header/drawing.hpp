
#pragma once 
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tetromino.hpp"

#define COLUMN 10
#define ROW 20
#define CELLSIZE 30

void drawPixel(int x, int y, sf::Color color, sf::RenderWindow &window);
void drawGrid(sf::RenderWindow& window);
void drawLocked(Board& board,sf::RenderWindow& window);
