#include "header/board.hpp"

void Board::setCell(int x,int y, int colorindex){
    cell.at(y).at(x)=1;
    color.at(y).at(x)=colorindex;
};
int Board::getColor(int x,int y){
    return color.at(y).at(x);
};
int Board::getValue(int x,int y){
    return cell.at(y).at(x);
};

bool Board::inBound(int x,int y){
    if(x<=-1||x>=COLUMN) return false;
    else if (y>=ROW+3) return false;
    return true;
};

bool Board::inHiddenLayer(){
    for (int i = 0; i < COLUMN; i++)
        for (int j=0;j<3;j++)
                if(this->getValue(i,j)) return true;
    return false;
    
}