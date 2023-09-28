#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"


using namespace std;
using namespace sf;

class WindowGraphic
{

private:
	int mainMenuSelected;
	Texture backroundTexture;
	RectangleShape background;
	Texture backroundGameTexture;
	RectangleShape backgroundGame;
	Texture backgroundHelpTexture;
	RectangleShape backgroundHelp;
	RectangleShape buttonShape;
	RectangleShape buttonMainMenu[5];
	RectangleShape buttonGame[44];
	Text buttonText[6];
	RenderWindow* window;
	string selectedMode = "";
	Event* gameEvent;
	Text player;
	Text computer;
	Text turn;
	Text scoreOne;
	Text scoreTwo;
	Font font;
	Game game;
	RectangleShape TrashCardImage;
	bool CardTrashSelected;

public:
	bool isPlayerVsPlayer = false;
	bool isPlayerVsComputer = false;
	bool mainDeckSelected = false;

	WindowGraphic();
	void closeWindowAction();
	void processMainMenuEvents();
	void processGameMenuEvents();
	void getMainMenuButtonsActions();
	Vector2i getMousePosition();
	void initializeTheMainMenuButtons();
	void drawMainButton();
	void printMainMenu();
	void printGameWindow();
	void initializeTheButtonText();
	void drawTextButton();
	void run();
	void getMouseMovementMainMenu();
	void drawPlayerVsPlayerGame();
	void drawPlayerVsComputerGame();
	void printHelpWindow();
	void playerTurn();
	void gameScore();
	void initializeTheGameButtons();
	void drawGameButton();
	void getGameButtonsActions();
	void drawPlayerOneCard();
	void drawPlayerTwoCard();
	void drawMainDeck();
	void drawTrashDeck();
	void drawOptionsMainDeck();

};