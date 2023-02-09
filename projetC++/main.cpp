#include "header/tetromino.hpp"
#include "header/drawing.hpp"

using namespace std;

Board board;

int main()
{
    std::random_device r;
    std::default_random_engine generator(r()) ;
    std::uniform_int_distribution<int> distribution(0,6);
    sf::RenderWindow window(sf::VideoMode(CELLSIZE*COLUMN, CELLSIZE*ROW), "My window");

    window.setFramerateLimit(200);
    int speedupdate=1000;

    //Pieces used in the game 
    
    tetromino piece;
    tetromino ghost;
    
    //Boolean to check if we need a new game or not

    bool newpiece=true;
    int choice = distribution(generator);
    sf::Clock clock;
    sf::Time timer= clock.getElapsedTime();
    while (window.isOpen())
    {
        if (newpiece){
            choice=distribution(generator);
            piece = tetromino_array[choice];
            piece.setCoord(int(COLUMN/2),0);
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
                    board.setcell(x,y,6);
                }
            }
            else if (e.type== sf::Event::KeyPressed){
                if (e.key.code==sf::Keyboard::Right||e.key.code==sf::Keyboard::D){
                    piece.update(board,"right",newpiece);
                }
                else if (e.key.code==sf::Keyboard::Left||e.key.code==sf::Keyboard::Q){
                    piece.update(board,"left",newpiece);

                }
                else if (e.key.code==sf::Keyboard::Down||e.key.code==sf::Keyboard::S){
                    piece.update(board,"down",newpiece);
                }
                else if(e.key.code==sf::Keyboard::Up||e.key.code==sf::Keyboard::X){
                    piece.update(board,"clockwise",newpiece);

                }
                else if(e.key.code==sf::Keyboard::Z){
                    piece.update(board,"counterwise",newpiece);

                }
                else if (e.key.code==sf::Keyboard::Space){
                    piece.harddrop(board,newpiece);
                }
                else if(e.key.code==sf::Keyboard::Escape){
                    window.close();
                }
                else if(e.key.code==sf::Keyboard::R){
                }
         
            }
        }
        
        if (clock.getElapsedTime().asMilliseconds()>speedupdate ){
            piece.update(board,"down",newpiece);
            clock.restart();
        }
        drawGrid(window);
        drawLocked(board,window);
        piece.draw(window);
        piece.drawGhost(window,board);
        window.display();
        window.clear();

    }
    return 0;
}