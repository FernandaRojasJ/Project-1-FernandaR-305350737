#include "WindowGraphic.h"

VideoMode _window = VideoMode::getDesktopMode();
RenderWindow window(_window, "Game window UNO", Style::Fullscreen);
string selectedMode = "";
bool selected_PvsP;
bool selected_PvsPC;
Event gameEvent;

bool WindowGraphic::startGameButton()
{
    Font font;

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {

        cerr << "Error al cargar la fuente." << endl;

    }

    Text playText("Start", font, 50);
    playText.setPosition(220, 50);

    RectangleShape playButton;
    playButton.setSize(Vector2f(playText.getGlobalBounds().width, playText.getGlobalBounds().height));
    playButton.setPosition(playText.getPosition());
    playButton.setFillColor(Color::Transparent);

    Color colorNormal = Color::White;
    Color colorHover = Color::Black;
    playText.setFillColor(colorNormal);

    Event event;
    while (window.pollEvent(event))
    {

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect textBounds = playText.getGlobalBounds();

                if (playButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
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


bool WindowGraphic::openHelpWindow()
{
    RenderWindow helpWindow(VideoMode(700, 500), "Window Help");
    Font font;

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {
        cerr << "Error al cargar la fuente." << endl;
    }

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("resources/backgrounds/BackHelp.jpg"))
    {
        cerr << "Error al cargar la imagen de fondo." << endl;
    }

    Sprite backgroundSprite(backgroundTexture);

    Text defaultText("Reglas del juego", font, 18);
    defaultText.setPosition(20, 20);

    while (helpWindow.isOpen())
    {
        Event event;
        while (helpWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                helpWindow.close();
        }

        helpWindow.clear();
        helpWindow.draw(backgroundSprite);
        helpWindow.draw(defaultText);
        helpWindow.display();
    }

    return true; 
}

int WindowGraphic::modeTitle()
{
    Font font;
    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf")) 
    {
        return 1;
    }

    Text titleText("Select game mode:", font, 50);
    titleText.setPosition(25, 250);

    RectangleShape title;
    title.setSize(Vector2f(titleText.getGlobalBounds().width, titleText.getGlobalBounds().height));
    title.setPosition(titleText.getPosition());
    title.setFillColor(Color::Transparent);

    window.draw(titleText);
}

void WindowGraphic::playerVrsPlayerButton()
{
    Font font;

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {

        cerr << "Error al cargar la fuente." << endl;

    }

    Text playerVrsPlayerText("-Player vrs Player", font, 40);
    playerVrsPlayerText.setPosition(75, 350);

    if ((selected_PvsP == true) && (selected_PvsPC == false))
    {
        playerVrsPlayerText.setFillColor(Color::Black);
    }

    RectangleShape playerButton;
    playerButton.setSize(Vector2f(playerVrsPlayerText.getGlobalBounds().width, playerVrsPlayerText.getGlobalBounds().height));
    playerButton.setPosition(playerVrsPlayerText.getPosition());
    playerButton.setFillColor(Color::Transparent);


    Event event;
    while (window.pollEvent(event))
    {

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect textBounds = playerVrsPlayerText.getGlobalBounds();

                if (playerButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
                {
                    selectedMode = "Player vs Player";
                    selected_PvsP = true;
                    selected_PvsPC = false;
                }
            }
        }
    }

    window.draw(playerVrsPlayerText);




}

void WindowGraphic::playerVrsComputerButton()
{
    Font font;

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {

        cerr << "Error al cargar la fuente." << endl;

    }

    Text playerVrsComputerText("-Player vrs Computer", font, 40);
    playerVrsComputerText.setPosition(75, 450);

    if ((selected_PvsPC == true) && (selected_PvsP == false))
    {
        playerVrsComputerText.setFillColor(Color::Black);
    }

    RectangleShape player_ComputerButton;
    player_ComputerButton.setSize(Vector2f(playerVrsComputerText.getGlobalBounds().width, playerVrsComputerText.getGlobalBounds().height));
    player_ComputerButton.setPosition(playerVrsComputerText.getPosition());
    player_ComputerButton.setFillColor(Color::Transparent);


    Event event;
    while (window.pollEvent(event))
    {

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect textBounds = playerVrsComputerText.getGlobalBounds();

                

                if (player_ComputerButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
                {
                    selectedMode = "Player vs Computer";
                    selected_PvsPC = true;
                    selected_PvsP = false;
                }
            }
        }
    }

    window.draw(playerVrsComputerText);

}

void WindowGraphic::gameWindow()
{
    VideoMode _newWindow = VideoMode::getDesktopMode();
    RenderWindow newWindow(_newWindow, "Game Screen", Style::Fullscreen);

    if (!selectedMode.empty())
    {
        Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("resources/backgrounds/mainMenu.jpg"))
        {

        }

        Sprite backgroundSprite;
        backgroundSprite.setTexture(backgroundTexture);

        while (newWindow.isOpen())
        {
            Event newEvent;

            while (newWindow.pollEvent(newEvent))
            {
                if (newEvent.type == Event::Closed)
                    newWindow.close();
            }

            newWindow.clear();

            newWindow.draw(backgroundSprite);

            newWindow.display();
        }
    }
}

bool WindowGraphic::exitButton()
{
    Font font;

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {

        cerr << "Error al cargar la fuente." << endl;

    }

    Text exitText("Exit", font, 50);
    exitText.setPosition(220, 550);

    RectangleShape exitButton;
    exitButton.setSize(Vector2f(exitText.getGlobalBounds().width, exitText.getGlobalBounds().height));
    exitButton.setPosition(exitText.getPosition());
    exitButton.setFillColor(Color::Transparent);


    Event event;
    while (window.pollEvent(event))
    {

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect textBounds = exitText.getGlobalBounds();

                if (exitButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
                {
                    return true;
                }
            }
        }
    }

    window.draw(exitText);

}

bool WindowGraphic::helpButton()
{
    Font font;

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {

        cerr << "Error al cargar la fuente." << endl;

    }

    Text helpText("Help", font, 50);
    helpText.setPosition(220, 150);

    RectangleShape helpButton;
    helpButton.setSize(Vector2f(helpText.getGlobalBounds().width, helpText.getGlobalBounds().height));
    helpButton.setPosition(helpText.getPosition());
    helpButton.setFillColor(Color::Transparent);

    Event event;
    while (window.pollEvent(event))
    {

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect textBounds = helpText.getGlobalBounds();

                if (helpButton.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
                {
                    return true;

                }
            }
       }
    }

    window.draw(helpText);
}

void WindowGraphic::printMainMenu()
{
    while (window.isOpen()) {
        window.clear();
        window.draw(background);

        if (startGameButton() == true)
        {
            if (!selectedMode.empty())
            {
                window.close();
                gameWindow();
            }
        }

        if (exitButton() == true) {

            window.close();
            exitButton();
        }
        
        if (helpButton() == true) {

            openHelpWindow();
            helpButton();
        }

        if (modeTitle() == true) {

            modeTitle();
        }

            playerVrsPlayerButton();

            playerVrsComputerButton();
        

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
