#include "WindowGraphic.h"


WindowGraphic::WindowGraphic()
{
	window = new RenderWindow(VideoMode(1366, 768), "Game window UNO", Style::Default);
	window->setFramerateLimit(60);
    gameEvent = new Event();
    background.setSize(Vector2f(1366, 768));
    backroundTexture.loadFromFile("resources/backgrounds/mainMenu.jpg");
    background.setTexture(&backroundTexture);

}

void WindowGraphic::printMainMenu()
{
	while (window->isOpen()) {
		window->clear();
        window->draw(background);

        Texture _texture;
        if (!_texture.loadFromFile("resources/Cartas/Cartas UNO.png"))
        {
            cout << "no se pudo cargar la imagen";
        }

        RectangleShape _rectangle(Vector2f(57, 86));
        _rectangle.setPosition(100, 100);

        _rectangle.setTexture(&_texture);

        IntRect area(0, 0, 57, 86);
        _rectangle.setTextureRect(area);
        
        window->draw(_rectangle);
        window->display();
        processMainMenuEvents();
 
	}
}

void WindowGraphic::closeWindowAction()
{
    window->close();
    exit(1);
}

void WindowGraphic::processMainMenuEvents() {
    while (window->pollEvent(*gameEvent)) {
        switch (gameEvent->type)
        {
        case Event::Closed:
            closeWindowAction();
            break;



        //case Event::KeyPressed:
        //    getEscapeKeyActionCloseWindow();
        //    break;

        //case Event::MouseMoved:
        //    getMouseMovementMainMenu();
        //    break;

        //case Event::MouseButtonReleased:
        //    getMainMenuButtonsActions();
        //    break;


        }
    }
}
