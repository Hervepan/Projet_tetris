#pragma once 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>   
#include <array>

#define Z_TETROMINO 0
#define L_TETROMINO 1
#define O_TETROMINO 2
#define S_TETROMINO 3
#define I_TETROMINO 4
#define J_TETROMINO 5
#define T_TETROMINO 6

#define COLUMN 10
#define ROW 20
#define CELLSIZE 30


using namespace std;
using array2x3=array<array<int,2>,3>;
using array20x10=array<array<int,COLUMN>,ROW>;


//GLOBAL VALUE DEFINITON

extern sf::Color colorarray[9]; //Color we use in different 

//Tetrominos representation
class Tetromino{
    public:
        int x;
        int y;
        array2x3 offset;
        sf::Color color;
        Tetromino(array2x3 offset,sf::Color color):
            offset(offset),color(color){};
        void setCoord(int x,int y);
        void fall(int speed=1);
        void draw(sf::RenderWindow& window);
        bool collision(array20x10 board,string direction);
        void rotate(string direction);
        void lock();
};

//Definition of all the shapes available in the game
extern Tetromino I;
extern Tetromino O;
extern Tetromino S;
extern Tetromino Z;
extern Tetromino J;
extern Tetromino L;
extern Tetromino T;

extern array<Tetromino,7> tetromino_array;

