#include "header/drawing.hpp"

void drawPixel(int x,int y, sf::Color color, sf::RenderWindow &window)
{
    sf::RectangleShape rectangle(sf::Vector2f(CELLSIZE-2, CELLSIZE-2));
    rectangle.setFillColor(color);
    rectangle.setPosition(CELLSIZE * x, CELLSIZE * y);
    window.draw(rectangle);
};


void drawGrid(sf::RenderWindow& window){

    //Drawing vertical line

    for (int i=0;i<COLUMN;i++){
        sf::VertexArray line(sf::Lines,2);
        line[0].position = sf::Vector2f(CELLSIZE*i,0);
        line[0].color = sf::Color(49,49,49);

        line[1].position = sf::Vector2f(CELLSIZE*i, CELLSIZE*ROW);
        line[1].color = sf::Color(49,49,49);
        window.draw(line);
    }
    //Drawing horizontal line

    for (int j=0;j<ROW;j++){
        sf::VertexArray line(sf::Lines,2);
        line[0].position = sf::Vector2f(0,CELLSIZE*j);
        line[0].color = sf::Color(49,49,49);

        line[1].position = sf::Vector2f(CELLSIZE*COLUMN,CELLSIZE*j);
        line[1].color = sf::Color(49,49,49);
        window.draw(line);
    }
 
}