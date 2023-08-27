
#include <iostream>
#include<SFML/Graphics.hpp>

using namespace std;

int main()
{
    //Window creation//

    unsigned int windowWidth = 900u;
    unsigned int windowLength = 500u;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowLength), "Game window UNO");

    while (window.isOpen())
    {
        sf::Event _event;
        while(window.pollEvent(_event))
        {
            switch (_event.type)
            {
            case sf::Event::Closed:
                    window.close();
                    break;
            }

        }

    }

























   /*Window
    sf::Window window(sf::VideoMode(640, 480), "Game UNO", sf::Style::Titlebar |  sf::Style::Close);
    sf::Event _event;

    //Bucle del juego//

    while (window.isOpen())
    {
        //sondeo de eventos//
        while (window.pollEvent(_event))
        {
            switch (_event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (_event.key.code == sf::Keyboard::Escape)
                    window.close();
                    break;
            }
        }

    }
    

    //Fin de la aplicacion*/





    return 0;
}


