//Defining global values that we use throughout there project and include the necessary libary
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>   
#include <array>

using namespace std;

using arraysix=array<array<int,2>,3>;
using arrayeight=array<array<int,2>,4>;

class wallkick{
    arrayeight container;

    public:
        wallkick(arrayeight container):container{container}{};
        void flipsigned();
};

static const int COLUMN = 10;
static const int ROW = 20;
static const int CELLSIZE = 30;

static const int Z_tetromino = 0;
static const int L_tetromino = 1;
static const int O_tetromino = 2;
static const int S_tetromino = 3;
static const int I_tetromino = 4;
static const int J_tetromino = 5;
static const int T_tetromino = 6;