#include "header/tetromino.hpp"
#include "header/drawing.hpp"

using namespace std;

array20x10 board={0};

int main()
{
    std::random_device r;
    std::default_random_engine generator(r()) ;
    std::uniform_int_distribution<int> distribution(0,6);

    sf::RenderWindow window(sf::VideoMode(CELLSIZE*COLUMN, CELLSIZE*ROW), "My window");
    restart:
    int choice = distribution(generator);
    Tetromino piece = tetromino_array[choice];
    piece.setCoord(5,6);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        drawGrid(window);
        piece.draw(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type== sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Right){
                    if(!piece.collision(board,"right"s)){
                        piece.x++;
                    }
                }
                if (event.key.code==sf::Keyboard::Left){
                    if(!piece.collision(board,"left"s)){
                        piece.x--;
                    }
                }
                if (event.key.code==sf::Keyboard::Down){
                    if(!piece.collision(board,"down"s)){
                        piece.y++;
                    }
                }
                if(event.key.code==sf::Keyboard::Escape){
                    goto restart;
                }
            }

        }
        if(clock.getElapsedTime().asSeconds()>1){
            if(!piece.collision(board,"down"s))
                piece.fall();
            clock.restart();
        }
        window.display();
        window.clear();

    }
    return 0;
}