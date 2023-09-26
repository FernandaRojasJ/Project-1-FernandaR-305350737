#include "WindowGraphic.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"

//Card cardInstance;

//position;

//vector<RectangleShape>cards = cardInstance.loadCards();


WindowGraphic::WindowGraphic()
{
    font.loadFromFile("resources/Fonts/Crayon Kids.otf");

    gameEvent = new Event();
    window = new RenderWindow(VideoMode(1366, 768), "Game window UNO", Style::Fullscreen);
    window->setFramerateLimit(60);
    background.setSize(Vector2f(1372, 772));
    backroundTexture.loadFromFile("resources/backgrounds/BackgroundReal.jpg");
    background.setTexture(&backroundTexture);

    backgroundGame.setSize(Vector2f(1372, 772));
    backroundGameTexture.loadFromFile("resources/backgrounds/BackgroundTwo.jpg");
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
    game.loadCards();

    RectangleShape temporal = game.getCards()[107].getGameCard();
    temporal.setPosition(1200, 600);

    RectangleShape temporal1 = game.getCards()[70].getGameCard();
    temporal1.setPosition(1200, 500);

    RectangleShape temporal2 = game.getCards()[84].getGameCard();
    temporal2.setPosition(1200, 400);

    RectangleShape temporal3 = game.getCards()[98].getGameCard();
    temporal3.setPosition(1200, 300);

    window->draw(temporal);
    window->draw(temporal1);
    window->draw(temporal2);
    window->draw(temporal3);

}

void WindowGraphic::drawPlayerOneCard()
{
    game.assingCardsToPlayer();

    RectangleShape temp = game.getPlayerOne().getPlayerDeck()[0].getGameCard();
    temp.setPosition(300, 100);

    RectangleShape temp0 = game.getPlayerOne().getPlayerDeck()[1].getGameCard();
    temp0.setPosition(400, 100);

    RectangleShape temp1 = game.getPlayerOne().getPlayerDeck()[2].getGameCard();
    temp1.setPosition(500, 100);

    RectangleShape temp2 = game.getPlayerOne().getPlayerDeck()[3].getGameCard();
    temp2.setPosition(600, 100);

    RectangleShape temp3 = game.getPlayerOne().getPlayerDeck()[4].getGameCard();
    temp3.setPosition(700, 100);

    RectangleShape temp4 = game.getPlayerOne().getPlayerDeck()[5].getGameCard();
    temp4.setPosition(800, 100);

    RectangleShape temp5 = game.getPlayerOne().getPlayerDeck()[6].getGameCard();
    temp5.setPosition(900, 100);

    RectangleShape temp6 = game.getPlayerOne().getPlayerDeck()[7].getGameCard();
    temp6.setPosition(1000, 100);

    window->draw(temp);
    window->draw(temp0);
    window->draw(temp1);
    window->draw(temp2);
    window->draw(temp3);
    window->draw(temp4);
    window->draw(temp5);
    window->draw(temp6);
}

void WindowGraphic::drawPlayerTwoCard()
{
    game.assingCardsToPlayer();

    RectangleShape temp = game.getPlayerTwo().getPlayerDeck()[0].getGameCard();
    temp.setPosition(300, 600);

    RectangleShape temp0 = game.getPlayerTwo().getPlayerDeck()[1].getGameCard();
    temp0.setPosition(400, 600);

    RectangleShape temp1 = game.getPlayerTwo().getPlayerDeck()[2].getGameCard();
    temp1.setPosition(500, 600);

    RectangleShape temp2 = game.getPlayerTwo().getPlayerDeck()[3].getGameCard();
    temp2.setPosition(600, 600);

    RectangleShape temp3 = game.getPlayerTwo().getPlayerDeck()[4].getGameCard();
    temp3.setPosition(700, 600);

    RectangleShape temp4 = game.getPlayerTwo().getPlayerDeck()[5].getGameCard();
    temp4.setPosition(800, 600);

    RectangleShape temp5 = game.getPlayerTwo().getPlayerDeck()[6].getGameCard();
    temp5.setPosition(900, 600);

    RectangleShape temp6 = game.getPlayerTwo().getPlayerDeck()[7].getGameCard();
    temp6.setPosition(1000, 600);

    window->draw(temp);
    window->draw(temp0);
    window->draw(temp1);
    window->draw(temp2);
    window->draw(temp3);
    window->draw(temp4);
    window->draw(temp5);
    window->draw(temp6);
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
                        gameScore();
                    }
                    break;

                case 1:
                    gameScore();
                    printHelpWindow();
                    

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
        gameScore();
        playerTurn();
        //drawMatrixCard();
        drawPlayerOneCard();
        drawPlayerTwoCard();

        window->display();
    }
}

void WindowGraphic::drawPlayerVsPlayerGame()
{

    Text playerOne(game.getPlayerOne().getName(), font, 20);
    playerOne.setPosition(25, 25);

    Text playerTwo(game.getPlayerTwo().getName(), font, 20);
    playerTwo.setPosition(25, 675);

    window->draw(playerOne);
    window->draw(playerTwo);

}

void WindowGraphic::run()
{
    printMainMenu();
}

void WindowGraphic::drawPlayerVsComputerGame()
{
    Text player("Player: ", font, 20);
    player.setPosition(25, 25);

    Text computer("Computer: ", font, 20);
    computer.setPosition(25, 675);

    window->draw(player);
    window->draw(computer);
}

void WindowGraphic::printHelpWindow()
{
    RenderWindow helpWindow(VideoMode(800, 600), "Help", Style::Close);

    Texture backgroundHelpTexture;
    backgroundHelpTexture.loadFromFile("resources/backgrounds/BackHelp.jpg");
    Sprite backgroundHelp(backgroundHelpTexture);

    if (!font.loadFromFile("resources/Fonts/Crayon Kids.otf"))
    {
        
        cerr << "Error al cargar la imagen de fondo." << endl;
    }

    Text defaultText("Reglas del juego", font, 18);
    defaultText.setPosition(20, 20);

    while (helpWindow.isOpen())
    {
        Event helpEvent;
        while (helpWindow.pollEvent(helpEvent))
        {
            if (helpEvent.type == Event::Closed)
            {
                helpWindow.close(); 
            }
        }

        helpWindow.clear();
        helpWindow.draw(backgroundHelp);
        helpWindow.draw(defaultText);
        helpWindow.display();
    }
}

void WindowGraphic::playerTurn()
{

    Text turn("Turn: ", font, 18);
    turn.setPosition(1250, 20);
    turn.setFillColor(Color::Black);

    window->draw(turn);
}

void WindowGraphic::gameScore()
{

    Text scoreOne("Score: ", font, 20);
    scoreOne.setPosition(170, 25);
    scoreOne.setFillColor(Color::Black);

    Text scoreTwo("Score: ", font, 20);
    scoreTwo.setPosition(170, 675);
    scoreTwo.setFillColor(Color::Black);

    window->draw(scoreOne);
    window->draw(scoreTwo);

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
