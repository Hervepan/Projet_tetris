#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");
    sf::Window window2(sf::VideoMode(500, 500), "My window");
    window.setPosition(sf::Vector2i(0,0));
    window2.setPosition(sf::Vector2i(800;600))
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}