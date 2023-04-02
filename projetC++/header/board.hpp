#pragma once 

#include "global.hpp"

using namespace std;
// The board is two arrays (one for the color and the other to know if the grid cell was set or not) BUT both arrays have more rows compared to what is shown. It's made to have an easier to check if the game is over or not 
class Board{

    array<array<int,COLUMN>,ROW+3> cell;
    array<array<int,COLUMN>,ROW+3> color;
    public:

        Board(){
            cell.fill({0,0,0,0,0,0,0,0,0,0});
            color.fill({-1,-1,-1,-1,-1,-1,-1,-1,-1,-1});
        }
        void setCell(int x,int y,int colorindex);
        int getColor(int x,int y);
        int getValue(int x,int y);
        bool inBound(int x,int y);
        bool inHiddenLayer();
        int lineClear(int& lineCounter,int& lineCleared,int& lineSend);
        void addLine(int lineSend);
};
