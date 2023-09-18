#include "WindowGraphic.h"

WindowGraphic::WindowGraphic()
{
    font.loadFromFile("resources/Fonts/Crayon Kids.otf");

    gameEvent = new Event();
    window = new RenderWindow(VideoMode(1366, 768), "Game window UNO", Style::Fullscreen);
    window->setFramerateLimit(60);
    background.setSize(Vector2f(1372, 772));
    backroundTexture.loadFromFile("resources/backgrounds/BckUnoRedi.jpg");
    background.setTexture(&backroundTexture);

    backgroundGame.setSize(Vector2f(1372, 772));
    backroundGameTexture.loadFromFile("resources/backgrounds/mainMenu.jpg");
    backgroundGame.setTexture(&backroundGameTexture);
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

        case Event::KeyPressed:
            //getEscapeKeyActionCloseWindow();
            break;

        case Event::MouseMoved:
             getMouseMovementMainMenu();
            break;

        case Event::MouseButtonReleased:
            getMainMenuButtonsActions();
            break;


        }
    }
}

void WindowGraphic::drawMatrixCard()
{
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

    window->draw(_rectangle);
}

Vector2i WindowGraphic::getMousePosition()
{
    Vector2i mousePosition;
    mousePosition = Mouse::getPosition(*window);
    return mousePosition;
}


void WindowGraphic::initializeTheMainMenuButtons()
{
    buttonMainMenu[0].setSize(Vector2f(135, 50));
    buttonMainMenu[0].setPosition(270, 60);
    buttonMainMenu[0].setFillColor(Color::Transparent);

    buttonMainMenu[1].setSize(Vector2f(150, 50));
    buttonMainMenu[1].setPosition(260, 160);
    buttonMainMenu[1].setFillColor(Color::Transparent);

    buttonMainMenu[2].setSize(Vector2f(400, 40));
    buttonMainMenu[2].setPosition(120, 355);
    buttonMainMenu[2].setFillColor(Color::Transparent);

    buttonMainMenu[3].setSize(Vector2f(455, 40));
    buttonMainMenu[3].setPosition(93, 455);
    buttonMainMenu[3].setFillColor(Color::Transparent);

    buttonMainMenu[4].setSize(Vector2f(120, 50));
    buttonMainMenu[4].setPosition(265, 560);
    buttonMainMenu[4].setFillColor(Color::Transparent);





}

void WindowGraphic::drawMainButton()
{
    for (int i = 0; i < 5; i++)
    {
        window->draw(buttonMainMenu[i]);
    }

}

void WindowGraphic::getMainMenuButtonsActions() {
    if (gameEvent->mouseButton.button == Mouse::Left) {
        for (int i = 0; i < 5; i++) {
            if (buttonMainMenu[i].getGlobalBounds().contains(getMousePosition().x, getMousePosition().y)) {
                switch (i) {
                case 0:
                    if (isPlayerVsPlayer != false || isPlayerVsComputer != false)
                    {
                        printGameWindow();
                    }
                    break;

                case 1:
                    

                    break;

                case 2:
                    buttonText[3].setFillColor(Color::Black);
                    buttonText[4].setFillColor(Color::White);
                    isPlayerVsPlayer = true;
                    isPlayerVsComputer = false;
                    break;

                case 3:
                    buttonText[4].setFillColor(Color::Black);
                    buttonText[3].setFillColor(Color::White);
                    isPlayerVsPlayer = false;
                    isPlayerVsComputer = true;
                    break;

                case 4:
                    closeWindowAction();
                    break;

                }
            }
        }
    }
}

void WindowGraphic::printMainMenu()
{
    initializeTheMainMenuButtons();
    initializeTheButtonText();
    while (window->isOpen())
    {
        window->clear();
        processMainMenuEvents();
        window->draw(background);
        drawMainButton();
        drawTextButton();
        window->display();
        
    }

}

void WindowGraphic::printGameWindow()
{
    while (window->isOpen())
    {
        window->clear();
        window->draw(backgroundGame);
        if (isPlayerVsPlayer)
        {
            drawPlayerVsPlayerGame();
        }
        else
        {
            drawPlayerVsComputerGame();
        }

        drawMatrixCard();
        window->display();
    }
}

void WindowGraphic::drawPlayerVsPlayerGame()
{


}

void WindowGraphic::run()
{
    printMainMenu();
}

void WindowGraphic::drawPlayerVsComputerGame()
{
}

void WindowGraphic::initializeTheButtonText()
{

    buttonText[0].setFont(font);
    buttonText[0].setPosition(267, 50);
    buttonText[0].setFillColor(Color::White);
    buttonText[0].setCharacterSize(50);
    buttonText[0].setString("Start");
     
    buttonText[1].setFont(font);
    buttonText[1].setPosition(270, 150);
    buttonText[1].setFillColor(Color::White);
    buttonText[1].setCharacterSize(50);
    buttonText[1].setString("Help");

    buttonText[2].setFont(font);
    buttonText[2].setPosition(75, 250);
    buttonText[2].setFillColor(Color::White);
    buttonText[2].setCharacterSize(50);
    buttonText[2].setString("Select game mode:");

    buttonText[3].setFont(font);
    buttonText[3].setPosition(140, 350);
    buttonText[3].setFillColor(Color::White);
    buttonText[3].setCharacterSize(40);
    buttonText[3].setString("Player vs Player");

    buttonText[4].setFont(font);
    buttonText[4].setPosition(98, 450);
    buttonText[4].setFillColor(Color::White);
    buttonText[4].setCharacterSize(40);
    buttonText[4].setString("Player vs Computer");

    buttonText[5].setFont(font);
    buttonText[5].setPosition(270, 550);
    buttonText[5].setFillColor(Color::White);
    buttonText[5].setCharacterSize(50);
    buttonText[5].setString("Exit");

}

void WindowGraphic::drawTextButton()
{
    for (int i = 0; i < 6; i++)
    {
        window->draw(buttonText[i]);
    }

}

void WindowGraphic::getMouseMovementMainMenu() 
{
    for (int i = 0; i < 5; i++) 
    {
            if (buttonMainMenu[i].getGlobalBounds().contains(getMousePosition().x, getMousePosition().y)) 
            {
                switch (i) {
                case 0:
                    buttonText[0].setFillColor(Color::Yellow);
                    break;
                case 1:
                    buttonText[1].setFillColor(Color::Yellow);
                    break;
                case 4:
                    buttonText[5].setFillColor(Color::Yellow);
                    break;
                }
            }

            else 
            {
                switch (i) {
                case 0:
                    buttonText[0].setFillColor(Color::White);
                    break;
                case 1:
                    buttonText[1].setFillColor(Color::White);
                    break;
                case 4:
                    buttonText[5].setFillColor(Color::White);
                    break;
                }
            }
    }
}
