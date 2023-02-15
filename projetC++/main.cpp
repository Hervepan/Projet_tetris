#include "header/tetromino.hpp"
#include "header/drawing.hpp"

using namespace std;

Board board;

int main()
{
    std::random_device r;
    std::default_random_engine generator(r()) ;
    std::uniform_int_distribution<int> distribution(0,6);
    sf::RenderWindow window(sf::VideoMode(CELLSIZE*COLUMN+CELLSIZE*8, CELLSIZE*ROW), "My window");

    window.setFramerateLimit(200);
    int speed=1000;

    //Pieces used in the game 
    
    tetromino piece;
    tetromino ghost;
    
    //boolean to check if I can lock the piece and if I have to create a new piece
    bool tolock=false;
    bool newpiece=true;
    bool keyhold=false;

    int levelCounter{0};
    int lineCleared{0};
    int score{0};
    int choice;

    sf::Clock gameTime;
    sf::Clock clockSpeed;

    while (window.isOpen())
    {
        while(true){
            if(board.inHiddenLayer()) break;
            if (newpiece){
                choice=distribution(generator);
                piece=tetromino_array[choice];
                piece.setCoord(int(COLUMN/2),2);
                newpiece=false;
            }
            sf::Event e;
            while (window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                    window.close();

                else if(e.type==sf::Event::MouseButtonPressed){
                    if(e.mouseButton.button==sf::Mouse::Left){
                        int x=sf::Mouse::getPosition(window).x/CELLSIZE; 
                        int y=sf::Mouse::getPosition(window).y/CELLSIZE;
                        board.setCell(x,y+3,6);
                    }
                }
                else if (e.type== sf::Event::KeyPressed){
                    if (e.key.code==sf::Keyboard::Right||e.key.code==sf::Keyboard::D){
                        piece.updateRight(board);
                    }
                    else if (e.key.code==sf::Keyboard::Left||e.key.code==sf::Keyboard::Q){
                        piece.updateLeft(board);
                    }
                    else if (e.key.code==sf::Keyboard::Down||e.key.code==sf::Keyboard::S){
                        piece.updateDown(board,newpiece); 
                    }
                    else if(e.key.code==sf::Keyboard::Up||e.key.code==sf::Keyboard::X){
                        piece.updateKickRotate(board);
                    }
                    else if(e.key.code==sf::Keyboard::Space){
                        piece.harddrop(board,newpiece);
                    }
                    else if(e.key.code==sf::Keyboard::Z){
                        piece.updateKickRotate(board,false);
                    }
                    else if(e.key.code==sf::Keyboard::Escape){
                        window.close();
                    }
                    else if(e.key.code==sf::Keyboard::R){
                        newpiece=true;
                    }
            
                }
            }         

            if(clockSpeed.getElapsedTime().asMilliseconds()>speed){
                clockSpeed.restart();
                piece.updateDown(board,newpiece);
            }

            if(levelCounter>=10){
                speed/=1.7;
                levelCounter=levelCounter%10    ;
                cout << "Increase speed !" << endl;
            }

            score+=board.lineClear(levelCounter,lineCleared);
            drawScoreBoard(window,lineCleared,score);
            drawGrid(window);
            piece.draw(window);
            piece.drawGhost(board,window);
            drawLocked(board,window);
            window.display();
            window.clear();
        }
        sf::Event e;
        while(window.pollEvent(e)){
            if (e.type==sf::Event::Closed){
                window.close();
            }
            if (e.type==sf::Event::KeyPressed){
                if (e.key.code==sf::Keyboard::Escape){
                    window.close();
                }
            }
        }
        drawGrid(window);
        drawEnd(board,window);
        window.display();
        window.clear();

    }
    return 0;
}