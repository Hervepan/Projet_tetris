
#pragma once 

#include "tetromino.hpp"

void drawPixel(int x, int y, sf::Color color, sf::RenderWindow &window);
void drawGrid(sf::RenderWindow& window);
void drawLocked(Board& board,sf::RenderWindow& window);
void drawScoreBoard(sf::RenderWindow& window,int lineCounter,int score);
void drawEnd(Board& board, sf::RenderWindow& window);