
#pragma once 

#include "tetromino.hpp"

void drawPixel(int x, int y, sf::Color color, sf::RenderWindow &window);
void drawGrid(sf::RenderWindow& window);
void drawLocked(Board& board,sf::RenderWindow& window);
void drawEnd(Board& board,sf::RenderWindow& window);