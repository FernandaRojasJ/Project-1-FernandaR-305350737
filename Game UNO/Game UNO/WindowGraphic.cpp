#include "WindowGraphic.h"

RenderWindow window(VideoMode(1366, 768), "Game window UNO", Style::Default);
Event gameEvent;

    bool WindowGraphic::startGamebutton()
{
       
    Font font;
   
    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {
       
        cerr << "Error al cargar la fuente." << std::endl;
      
    }

    Text playText("Start", font, 50);
    playText.setPosition(120, 120);

    RectangleShape playButton;
    playButton.setSize(Vector2f(playText.getGlobalBounds().width, playText.getGlobalBounds().height));
    playButton.setPosition(playText.getPosition());
    playButton.setFillColor(Color::Transparent);

   
    Event event;
    while (window.pollEvent(event))
    {
      
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button ==Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect textBounds = playText.getGlobalBounds();

                if(playButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
                {
                    return true;
                }
            }
        }
    }

        window.draw(playText);
        
    



}

WindowGraphic::WindowGraphic()
{
   
	window.setFramerateLimit(60);
    background.setSize(Vector2f(1372, 772));
    backroundTexture.loadFromFile("resources/backgrounds/BckUnoRedi.jpg");
    background.setTexture(&backroundTexture);

}

void WindowGraphic::printMainMenu()
{
	while (window.isOpen()) {
		window.clear();
        window.draw(background);
        if (startGamebutton()==true) {

            RenderWindow newWindow(VideoMode(1366, 768), "Nueva Ventana");
            while (newWindow.isOpen())
            {
                Event newEvent;
                while (newWindow.pollEvent(newEvent))
                {
                    if (newEvent.type == Event::Closed)
                        newWindow.close();
                }
            }
            window.close(); 
       }

        Texture _texture;
        if (!_texture.loadFromFile("resources/Cartas/Cartas UNO.png"))
        {
            cout << "no se pudo cargar la imagen";
        }

        RectangleShape _rectangle(Vector2f(57, 86));
        _rectangle.setPosition(1200, 600);

        _rectangle.setTexture(&_texture);

        IntRect area(0, 0, 57, 86);
        _rectangle.setTextureRect(area);
        
        window.draw(_rectangle);
        window.display();
        processMainMenuEvents();
 
	}
}

void WindowGraphic::closeWindowAction()
{
    window.close();
    exit(1);
}

void WindowGraphic::processMainMenuEvents() {
    while (window.pollEvent(gameEvent)) {
        switch (gameEvent.type)
        {
        case Event::Closed:
            closeWindowAction();
            break;



        //case Event::KeyPressed:
        //    getEscapeKeyActionCloseWindow();
        //    break;

        //case Event::MouseMoved:
        //    getMouseMovementMainMenu();
        //   break;

        //case Event::MouseButtonReleased:
        //    getMainMenuButtonsActions();
        //    break;


        }
    }
}
