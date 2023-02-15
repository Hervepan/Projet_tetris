#include "header/drawing.hpp"
#include <unistd.h>
#include <sstream>

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

void drawLocked(Board& board,sf::RenderWindow& window){    
    for (int x=0;x<COLUMN;x++)
        for (int y=3;y<ROW+3;y++)
                if (board.getValue(x,y)) drawPixel(x,y,colorarray[board.getColor(x,y)],window);
};

void drawEnd(Board& board,sf::RenderWindow& window){
    for (int y=3;y<ROW+3;y++)
        for (int x=0;x<COLUMN;x++)
                if (board.getValue(x,y)) drawPixel(x,y,sf::Color(125,125,125),window);        
}

void drawScoreBoard(sf::RenderWindow& window,int lineCleared, int score){

    sf::Font font;
    if(!font.loadFromFile("font/Tetrisfont.ttf"))
        throw("Couldn't load the font");
    
    sf::Text scoreText, lineClearedText;
    stringstream scoreString, lineClearedString;

    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);

    lineClearedText.setFont(font);
    lineClearedText.setCharacterSize(40);
    lineClearedText.setFillColor(sf::Color::White);

    scoreString << "SCORE : " << score;
    lineClearedString << "LINE : " << lineCleared;

    scoreText.setString(scoreString.str());
    lineClearedText.setString(lineClearedString.str());

    scoreText.setPosition(CELLSIZE*COLUMN*1.15,CELLSIZE*0.8);
    lineClearedText.setPosition(CELLSIZE*COLUMN*1.15,CELLSIZE*2);

    window.draw(scoreText);
    window.draw(lineClearedText);


}