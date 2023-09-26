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
	RectangleShape buttonMainMenu[5];
	Text buttonText[6];
	RenderWindow* window;
	string selectedMode = "";
	Event* gameEvent;
	Text playerOne;
	Text playerTwo;
	Text player;
	Text computer;
	Text turn;
	Text scoreOne;
	Text scoreTwo;
	Font font;
	Game game;

public:
	bool isPlayerVsPlayer = false;
	bool isPlayerVsComputer = false;

	WindowGraphic();
	void closeWindowAction();
	void processMainMenuEvents();
	void getMainMenuButtonsActions();
	Vector2i getMousePosition();
	void initializeTheMainMenuButtons();
	void drawMainButton();
	void printMainMenu();
	void printGameWindow();
	void initializeTheButtonText();
	void drawTextButton();
	void drawMatrixCard();
	void run();
	void getMouseMovementMainMenu();
	void drawPlayerVsPlayerGame();
	void drawPlayerVsComputerGame();
	void printHelpWindow();
	void playerTurn();
	void gameScore();
};

