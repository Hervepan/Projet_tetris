#include "header/tetromino.hpp"
#include "header/drawing.hpp"

//GLOBAL VALUE DEFINITON

//Color used for the different tetrominos
sf::Color colorarray[9] = {
    sf::Color(253, 63, 89 ,200), //salmon
    sf::Color(255, 200, 46 ,200), //orange
    sf::Color(254, 251, 52 ,200), //yellow
    sf::Color(83, 218, 63 ,200), //green
    sf::Color(1, 237, 250 ,200), //cyan
    sf::Color(221, 10, 178 ,200), //purple
    sf::Color(234, 20, 28 ,200), //red{}
    sf::Color(254, 72, 25 ,200), //dark orange
    sf::Color(255, 145, 12, 200) //sandy brown

};
//Definition of all the shapes available in the game

Tetromino I({-1,0,-2,0,1,0},colorarray[0]);
Tetromino O({0,-1,-1,-1,-1,0},colorarray[1]);
Tetromino S({-1,0,-1,1,0,-1},colorarray[2]);
Tetromino Z({-1,0,0,1,-1,-1,},colorarray[3]);
Tetromino J({0,-1,0,1,-1,-1,},colorarray[4]);
Tetromino L({0,-1,0,1,1,-1,},colorarray[5]);
Tetromino T({0,-1,0,1,-1,0},colorarray[6]);

array<Tetromino,7> tetromino_array({Z,L,O,S,I,J,T});

void Tetromino::setCoord(int x,int y){
    this->x=x;
    this->y=y;
}

void Tetromino::draw(sf::RenderWindow& window){
    int x_buffer,y_buffer;
    drawPixel(x,y,color,window);
    for (auto j:offset){
        x_buffer=x+j[0];
        y_buffer=y+j[1];
        drawPixel(x_buffer,y_buffer,color,window);
    }
};

void Tetromino::fall(int speed){
    y+=speed;
};
void Tetromino::rotate(string direction){};
void Tetromino::lock(){};


bool Tetromino::collision(array20x10 board,string direction)
{
    if (board[x][y + 1])
        return true;
    else if (x==0 && direction=="left")
        return true;
    else if (x+1==COLUMN && direction=="right")
        return true;
    else if (y + 1 == ROW && direction=="down")
        return true;
    else
        return false;
}
