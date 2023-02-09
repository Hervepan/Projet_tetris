#include "header/board.hpp"

void Board::setcell(int x,int y, int colorindex){
    cell.at(y).at(x)=1;
    color.at(y).at(x)=colorindex;
};
int Board::getcolor(int x,int y){
    return color.at(y).at(x);
};
int Board::getvalue(int x,int y){
    return cell.at(y).at(x);
};