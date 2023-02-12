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

void Board::lineClear(int& lineCounter){
    int sum{0};
    for (int y=ROW+2;y>=3;y--){
        for (int x=0;x<COLUMN;x++){
            sum+=this->getValue(x,y);
        }
        if (sum==COLUMN){
            lineCounter++;
            for(int i=y;i>=3;i--){
                cell.at(i)=cell.at(i-1);
                color.at(i)=color.at(i-1);
            }
        }
        sum=0;
    }
};
