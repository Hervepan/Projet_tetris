#pragma once 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>   
#include <array>

#define COLUMN 10
#define ROW 20
#define CELLSIZE 30

#define Z_tetromino 0
#define L_tetromino 1
#define O_tetromino 2
#define S_tetromino 3
#define I_tetromino 4
#define J_tetromino 5
#define T_tetromino 6

using namespace std;

class Board{

    array<array<int,COLUMN>,ROW> cell;
    array<array<int,COLUMN>,ROW> color;
    public:

        Board(){
            cell.fill({0,0,0,0,0,0,0,0,0,0});
            color.fill({-1,-1,-1,-1,-1,-1,-1,-1,-1,-1});
        }
        void setcell(int x,int, int colorindex);
        int getcolor(int x,int y);
        int getvalue(int x,int y);
};
