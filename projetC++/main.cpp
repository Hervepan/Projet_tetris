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
    restart:

    bool reset=false;
    //Defintion of all the boolean that we will use
    int choice = distribution(generator);
    tetromino piece = tetromino_array[choice];
    piece.setCoord(int(COLUMN/2),5);
    sf::Clock clock;
    float timer= clock.getElapsedTime().asSeconds();
    while (window.isOpen())
    {
        drawGrid(window);
        drawLocked(board,window);
        piece.draw(window);
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
                    piece.update(board,"right",reset);
                }
                else if (e.key.code==sf::Keyboard::Left||e.key.code==sf::Keyboard::Q){
                    piece.update(board,"left",reset);

                }
                else if (e.key.code==sf::Keyboard::Down||e.key.code==sf::Keyboard::S){
                    piece.update(board,"down",reset);
                    if(reset) goto restart;
                }
                else if(e.key.code==sf::Keyboard::Up||e.key.code==sf::Keyboard::X){
                    // piece.update(board,"clockwise");
                    piece.rotate();

                }
                else if(e.key.code==sf::Keyboard::Z){
                    // piece.update(board,"cclockwise");
                    piece.rotate();

                }
                else if(e.key.code==sf::Keyboard::Escape){
                    window.close();
                }
                else if(e.key.code==sf::Keyboard::R){
                    goto restart;
                }
         
            }
        }
        if(timer-clock.getElapsedTime().asSeconds()>1){
            cout << "bonjour" << endl;
            piece.update(board,"down",reset);
            clock.restart();
            if (reset) goto restart;
        }
        window.display();
        window.clear();

    }
    return 0;
}