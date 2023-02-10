#pragma once 

#include "board.hpp"

using namespace std;

class tetromino{
    int value;
    int x;
    int y;
    int rotateState;
    arraysix offset;
    sf::Color color;

    public: 
        //constructor
        tetromino(){};
        tetromino(int value,arraysix offset,sf::Color color):
            value{value},rotateState{0},offset(offset),color(color){};
            
        //method associated to the tetromino
        void setCoord(int x,int y);
        arrayeight getCoords();
        void draw(sf::RenderWindow& window);
        void updateRight(Board& board);
        void updateLeft(Board& board);
        void lock(Board& board);
        void updateDown(Board& board,bool& newpiece,bool ghost=false);
        void harddrop(Board& board,bool& newpiece);
        void drawGhost(Board& board,sf::RenderWindow& window);
        void rotateClockwise();
        void rotateCounterClockwise();
        void updateRotate(Board& board,bool clockwise=true);


};


extern tetromino I;
extern tetromino O;
extern tetromino S;
extern tetromino Z;
extern tetromino J;
extern tetromino L;
extern tetromino T;

extern sf::Color colorarray[7]; 

extern array<tetromino,7> tetromino_array;

extern wallkick zeroone;
extern wallkick onetwo;
extern wallkick twothree;
extern wallkick threezero;
extern wallkick zeroone_I;
extern wallkick onetwo_I;
extern wallkick twothree_I;
extern wallkick threezero_I;
//Color we use in different 
