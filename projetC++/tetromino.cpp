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


array<tetromino,7> tetromino_array({Z,L,O,S,I,J,T});

//Draw the tetromino
void tetromino::draw(sf::RenderWindow& window){
    int x_buffer,y_buffer;
    drawPixel(x,y,color,window);
    for(auto coords:offset){
        drawPixel(x+coords[0],y+coords[1],color,window);
    }
};


//Set the central piece of the tetromino (also use to rotate)
void tetromino::setCoord(int x,int y){
    this->x=x;
    this->y=y;
}

//Get all the coordintates of the block in the tetromino
arrayeight tetromino::getCoords(){
    arrayeight ret;
    for (int j=0;j<3;j++){
        ret[j][0]=x+offset[j][0];
        ret[j][1]=y+offset[j][1];
    }
    ret.at(3).at(0)=x;
    ret.at(3).at(1)=y;
    return ret;
}


void tetromino::rotate(string direction){
    int buffer;
    int first_sign,second_sign;
    if (value!=O_tetromino){
        if (direction=="clockwise"){
            first_sign=-1;   
            second_sign=1;
        }
        else if(direction=="cclockwise"){
            first_sign=1;
            second_sign=-1;
        }
        if (value==I_tetromino){
            first_sign=1;
            second_sign=1;
        }
        for(int i=0;i<3;i++){
            buffer=this->offset[i][0];
            this->offset[i][0]=first_sign*this->offset[i][1];
            this->offset[i][1]=second_sign*buffer;
        }
    }
};

void tetromino::lock(Board& board){
    arrayeight coords=this->getCoords();
    for(int i=0;i<4;i++)
        board.setcell(coords[i][0],coords[i][1],value);
};

void tetromino::update(Board& board,string direction,bool& reset){
    int buffer;
    bool toupdate=true;
    if (direction=="right"){
        for (auto coords: this->getCoords()){
            buffer=coords[0]+1;
            if(buffer==COLUMN||board.getvalue(buffer,coords[1])){
                toupdate=false;
                break;
            }
        }
        if (toupdate) x++;
    }
    else if(direction=="left"){
        for (auto coords: this->getCoords()){
            buffer=coords[0]-1;
            if(buffer==-1||board.getvalue(buffer,coords[1])){
                toupdate=false;
                break;
            }
        }
        if (toupdate) x--;

    }
    else if(direction=="down"){
        for (auto coords: this->getCoords()){
            buffer=coords[1]+1;
            if(buffer==ROW||board.getvalue(coords[0],buffer)){
                toupdate=false;
                this->lock(board);
                reset=true;
                break;
            } 
        }
        if (toupdate) y++;

    }
};


