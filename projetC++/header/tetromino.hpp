#pragma once 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>   
#include <array>
#include "board.hpp"

using namespace std;

using arraysix=array<array<int,2>,3>;
using arrayeight=array<array<int,2>,4>;

class tetromino{
    int value;
    int x;
    int y;
    arraysix offset;
    sf::Color color;

    public: 
        //constructor
        tetromino(int value,arraysix offset,sf::Color color):
            value{value},offset(offset),color(color){};
            
        //method associated to the tetromino
        void setCoord(int x,int y);
        void draw(sf::RenderWindow& window);
        void rotate(string direction="clockwise"s);
        void update(Board& board,string direction,bool& reset);
        void lock(Board& board);
        arrayeight getCoords();

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

//Color we use in different 
