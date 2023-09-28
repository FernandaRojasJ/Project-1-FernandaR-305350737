#include "WindowGraphic.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"


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

void WindowGraphic::processGameMenuEvents()
{
    while (window->pollEvent(*gameEvent)) {
        switch (gameEvent->type)
        {
        case Event::Closed:
            closeWindowAction();
            break;

        case Event::KeyPressed:

            break;

        case Event::MouseMoved:
            getMouseMovementMainMenu();
            break;

        case Event::MouseButtonReleased:
            getGameButtonsActions();
            break;


        }
    }
}

void WindowGraphic::drawPlayerOneCard()
{
    for (int i = 0; i < game.getPlayerOne().getPlayerDeck().size(); i++) {
        if (i <= 10) {
            RectangleShape temp = game.getPlayerOne().getPlayerDeck()[i].getGameCard();
            temp.setPosition((i * 100) + 300, 17);
            window->draw(temp);
        }
        if (i >= 10 && i <= 20) {
            RectangleShape temp = game.getPlayerOne().getPlayerDeck()[i].getGameCard();
            temp.setPosition(((i - 10) * 100) + 300, 117);
            window->draw(temp);
        }
    }
}

void WindowGraphic::drawPlayerTwoCard()
{
    
    for (int i = 0; i < game.getPlayerTwo().getPlayerDeck().size(); i++) {
        if (i <= 10) {
            RectangleShape temp = game.getPlayerTwo().getPlayerDeck()[i].getGameCard();
            temp.setPosition((i * 100) + 300, 675);
            window->draw(temp);
        }
        if (i >= 10 && i <= 20) {
            RectangleShape temp = game.getPlayerTwo().getPlayerDeck()[i].getGameCard();
            temp.setPosition(((i - 10) * 100) + 300, 575);
            window->draw(temp);
        }
    }
}

void WindowGraphic::drawMainDeck()
{
    Texture texture;
    if (!texture.loadFromFile("resources/Cartas/Carta_Trasera.jpg"))
    {
        cout << "no se pudo cargar la imagen";
    }

    RectangleShape rectangle(sf::Vector2f(texture.getSize().x, texture.getSize().y));

    rectangle.setTexture(&texture);
    rectangle.setPosition(810, 340);

    window->draw(rectangle);
}

void WindowGraphic::drawTrashDeck()
{
    RectangleShape rectangle = TrashCardImage;
    rectangle.setSize(Vector2f(114, 174));
    rectangle.setPosition(410, 340);
    window->draw(rectangle);
}

void WindowGraphic::drawOptionsMainDeck()
{
    if (mainDeckSelected) {
        Text continueEating;
        Text passTurn;
        continueEating.setFont(font);
        continueEating.setPosition(990, 340);
        continueEating.setFillColor(Color::White);
        continueEating.setCharacterSize(16);
        continueEating.setString("Comer");

        passTurn.setFont(font);
        passTurn.setPosition(990, 440);
        passTurn.setFillColor(Color::White);
        passTurn.setCharacterSize(16);
        passTurn.setString("Pasar turno");

        window->draw(continueEating);
        window->draw(passTurn);
    }
}

void WindowGraphic::initializeTheGameButtons()
{
    buttonGame[0].setSize(Vector2f(114, 174));
    buttonGame[0].setPosition(810, 340);
    buttonGame[0].setFillColor(Color::Transparent);

    buttonGame[1].setSize(Vector2f(130, 50));
    buttonGame[1].setPosition(970, 320);
    buttonGame[1].setFillColor(Color::Transparent);

    buttonGame[2].setSize(Vector2f(130, 50));
    buttonGame[2].setPosition(970, 420);
    buttonGame[2].setFillColor(Color::Transparent);

    buttonGame[3].setSize(Vector2f(114, 174));
    buttonGame[3].setPosition(410, 340);
    buttonGame[3].setFillColor(Color::Transparent);

    for (int i = 0; i < 20; i++) {
        if (i <= 10) {
            buttonGame[i + 4].setSize(Vector2f(57, 86));
            buttonGame[i + 4].setPosition((i * 100) + 300, 17);
            buttonGame[i + 4].setFillColor(Color::Transparent);
        }
        if (i >= 10 && i <= 20) {
            buttonGame[i + 4].setSize(Vector2f(57, 86));
            buttonGame[i + 4].setPosition(((i - 10) * 100) + 300, 117);
            buttonGame[i + 4].setFillColor(Color::Transparent);
        }
    }

    for (int i = 0; i < 20; i++) {
        if (i <= 10) {
            buttonGame[i + 24].setSize(Vector2f(57, 86));
            buttonGame[i + 24].setPosition((i * 100) + 300, 675);
            buttonGame[i + 24].setFillColor(Color::Transparent);
        }
        if (i >= 10 && i <= 20) {
            buttonGame[i + 24].setSize(Vector2f(57, 86));
            buttonGame[i + 24].setPosition(((i - 10) * 100) + 300, 575);
            buttonGame[i + 24].setFillColor(Color::Transparent);
        }
    }
}

void WindowGraphic::drawGameButton()
{
    for (int i = 0; i < 44; i++)
    {
        window->draw(buttonGame[i]);
    }
}

void WindowGraphic::getGameButtonsActions()
{
    if (gameEvent->mouseButton.button == Mouse::Left)
    {
        for (int i = 0; i < 44; i++) 
        {
            if (buttonGame[i].getGlobalBounds().contains(getMousePosition().x, getMousePosition().y)) 
            {
                switch (i)
                {
                case 0:
                    mainDeckSelected = true;
                    break;

                case 1:
                    if (game.getTurn() == 1) {
                        game.addCardToDeckOne();
                    }
                    if (game.getTurn() == 2) {
                        game.addCardToDeckTwo();
                    }
                    break;

                case 2:
                    if (game.getTurn() == 1) {
                        game.setTurn(2);
                    }else {
                        game.setTurn(1);
                    }
                    mainDeckSelected = false;
                    break;
                        
                case 3: 
                    CardTrashSelected = true;
                }
                if (i >= 4 && i <= game.getPlayerOne().getPlayerDeck().size() + 4) {
                    if (game.getTurn() == 1) {
                        ;
                        if (CardTrashSelected) {  
                            int index = (i - 4);
                         
                            game.logicGame(game.getPlayerOne().getPlayerDeck()[i - 4], index);
                            TrashCardImage = game.getTrashCard().getGameCard();
                        }
                    }
                }
                if (i >= 24) {
                    if (game.getTurn() == 2) {
                        
                        if (CardTrashSelected) {
                            int index = (i - 24);
                           
                            game.logicGame(game.getPlayerTwo().getPlayerDeck()[i - 24], index);
                            TrashCardImage = game.getTrashCard().getGameCard();
                        }
                    }
                }         
            }
        }
    }
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
    game.loadCards();
    game.assingCardsToPlayer(game.getCards());
    initializeTheGameButtons();
    game.setTrashCard(game.getRandomCard());
    TrashCardImage = game.getTrashCard().getGameCard();

    while (window->isOpen())
    {
        window->clear();
        processGameMenuEvents();
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
        drawPlayerOneCard();
        drawPlayerTwoCard();
        drawMainDeck();
        drawGameButton();
        drawOptionsMainDeck();
        drawTrashDeck();

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
    string nameTurn;
    if (game.getTurn() == 1) {
        nameTurn = "Jugador 1";
    }
    if (game.getTurn() == 2) {
        nameTurn = "Jugador 2";
    }

    Text turn("Turno: ", font, 18);
    Text player(nameTurn, font, 18);
    turn.setPosition(25, 370);
    turn.setFillColor(Color::White);
    player.setPosition(100, 370);
    player.setFillColor(Color::Black);

    window->draw(turn);
    window->draw(player);
}

void WindowGraphic::gameScore()
{

    Text scoreOne("Score: ", font, 20);
    scoreOne.setPosition(25, 60);
    scoreOne.setFillColor(Color::Black);

    Text scoreTwo("Score: ", font, 20);
    scoreTwo.setPosition(25, 710);
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




