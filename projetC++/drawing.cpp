#include "header/drawing.hpp"
#include <unistd.h>

void drawPixel(int x,int y, sf::Color color, sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(CELLSIZE-1, CELLSIZE-1));
    rectangle.setFillColor(color);
    rectangle.setPosition(CELLSIZE*x, CELLSIZE*(y-3));
    window.draw(rectangle);
};

void drawGrid(sf::RenderWindow& window){

    for (int x=0;x<COLUMN;x++)
        for (int y=3;y<ROW+3;y++)
            drawPixel(x,y,sf::Color(49,49,49),window);
    
}

void drawLocked(Board& board,sf::RenderWindow& window)
{    
    for (int x=0;x<COLUMN;x++)
        for (int y=3;y<ROW+3;y++)
                if (board.getValue(x,y)) drawPixel(x,y,colorarray[board.getColor(x,y)],window);
};

void drawEnd(Board& board,sf::RenderWindow& window){
    for (int y=3;y<ROW+3;y++)
        for (int x=0;x<COLUMN;x++)
                if (board.getValue(x,y)) drawPixel(x,y,sf::Color(125,125,125),window);        
}