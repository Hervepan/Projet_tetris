#include "header/tetromino.hpp"
#include "header/drawing.hpp"

using namespace std;
//Board element

//Color used for the different tetrominos
sf::Color colorarray[7] = {
    sf::Color(253, 63, 89 ,200), //salmon
    sf::Color(255, 200, 46 ,200), //orange
    sf::Color(254, 251, 52 ,200), //yellow
    sf::Color(83, 218, 63 ,200), //green
    sf::Color(1, 237, 250 ,200), //cyan
    sf::Color(221, 10, 178 ,200), //purple
    sf::Color(234, 20, 28 ,200), //red
};

//Different tetromino pieces
tetromino Z(Z_tetromino,{0,-1,-1,-1,1,0},colorarray[Z_tetromino]);
tetromino L(L_tetromino,{-1,0,1,0,1,-1,},colorarray[L_tetromino]);
tetromino O(O_tetromino,{-1,0,-1,-1,0,-1},colorarray[O_tetromino]);
tetromino S(S_tetromino,{-1,0,0,-1,1,-1},colorarray[S_tetromino]);
tetromino I(I_tetromino,{-2,0,-1,0,1,0},colorarray[I_tetromino]);
tetromino J(J_tetromino,{-1,0,-1,-1,1,0},colorarray[J_tetromino]);
tetromino T(T_tetromino,{-1,0,0,-1,1,0},colorarray[T_tetromino]);

//Defintion of the array where we get our tetrominos
array<tetromino,7> tetromino_array({Z,L,O,S,I,J,T});

//Definition of the wallkick array 

wallkick zeroone({-1,0,-1,-1,0,2,-1,2});
wallkick onetwo({1,0,1,1,0,-2,1,-2});
wallkick twothree({1,0,1,-1,0,2,1,2});
wallkick threezero({-1,0,-1,1,0,-2,-1,-2});
wallkick zeroone_I({-2,0,1,0,-2,1,1,-2});
wallkick onetwo_I({-1,0,2,0,-1,-2,2,1});
wallkick twothree_I({2,0,1,0,2,-1,-1,2});
wallkick threezero_I({1,0,-2,0,1,2,-2,-1});


void tetromino::setCoord(int x,int y){
    this->x=x;
    this->y=y;
};

arrayeight tetromino::getCoords(){
    arrayeight ret;
    for (int j=0;j<3;j++){
        ret.at(j).at(0)=x+offset.at(j).at(0);
        ret.at(j).at(1)=y+offset.at(j).at(1);
    }
    ret.at(3).at(0)=x;
    ret.at(3).at(1)=y;
    return ret;
};

void tetromino::draw(sf::RenderWindow& window){
    for(auto coords:this->getCoords()){
        drawPixel(coords[0],coords[1],color,window);
    }

};

void tetromino::updateRight(Board& board){
    bool toupdate=true;
    int buffer;
    for (auto coords: this->getCoords()){
        buffer=coords[0]+1;
        if(buffer==COLUMN||board.getValue(buffer,coords[1])){
            toupdate=false;
            break;
        }
    }
    if (toupdate) x++;
};

void tetromino::updateLeft(Board& board){
    bool toupdate=true;
    int buffer;
    for (auto coords: this->getCoords()){
        buffer=coords[0]-1;
        if(buffer==-1||board.getValue(buffer,coords[1])){
            toupdate=false;
            break;
        }
    }
    if (toupdate) x--;
};

void tetromino::lock(Board& board){
    for(auto coords:this->getCoords()){
        board.setCell(coords[0],coords[1],value);
    }
};

void tetromino::updateDown(Board& board,bool& newpiece,bool ghost){
    bool toupdate=true;
    int buffer=0;
    for (auto coords: this->getCoords()){
        buffer=coords[1]+1;
        if(buffer==ROW+3||board.getValue(coords[0],buffer)){
            if(!ghost) this->lock(board);
            toupdate=false;
            newpiece=true;
            break;
        }
    }
    if(toupdate) y++;
}

void tetromino::harddrop(Board& board,bool& newpiece){
    while(!newpiece) this->updateDown(board,newpiece);
};

void tetromino::drawGhost(Board& board,sf::RenderWindow& window){
    bool boolbuffer=false;
    tetromino ghost(*this);
    while(!boolbuffer) ghost.updateDown(board,boolbuffer,true);
    ghost.color.a = 128;
    ghost.draw(window);
};

void tetromino::rotateClockwise(){
    int buffer;
    for(int i=0;i<3;i++){
            buffer=this->offset.at(i).at(0);
            this->offset.at(i).at(0)=this->offset.at(i).at(1);
            this->offset.at(i).at(1)=-buffer;
    }
    rotateState=(rotateState-1)%4;

};

void tetromino::rotateCounterClockwise(){
    int buffer;
    for(int i=0;i<3;i++){
            buffer=this->offset.at(i).at(0);
            this->offset.at(i).at(0)=-this->offset.at(i).at(1);
            this->offset.at(i).at(1)=buffer;
    }
    rotateState=(rotateState+1)%4;
}

void tetromino::updateRotate(Board& board,bool clockwise){
    bool toupdate=true;
    tetromino tetrobuffer(*this);
    if(clockwise) tetrobuffer.rotateClockwise();
    else tetrobuffer.rotateCounterClockwise();
    for (auto coords: tetrobuffer.getCoords()){
        if(!board.inBound(coords[0],coords[1])||board.getValue(coords[0],coords[1])){
            toupdate=false;
            break;
        }
    }
    if(toupdate){
        if(clockwise) this->rotateClockwise();
        else this->rotateCounterClockwise();
    } 
};


