#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


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
	RectangleShape buttonMainMenu[5];
	Text buttonText[6];
	RenderWindow* window;
	string selectedMode = "";
	Event* gameEvent;
	Font font;

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

	
};

