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
	RectangleShape pauseBackground, instructionsBackground, gameBackground, windowFlipBackground;
	Texture pauseBackgroundTexture, instructionsBackgroundTexture, gameBackgroundTexture, windowFlipBackgroundTexture;
	Texture backroundTexture;
	RectangleShape background;
	RectangleShape button;
	string selectedMode = "";
	



public:
	WindowGraphic();
	void printMainMenu();
	void processMainMenuEvents();
	void closeWindowAction();
    bool startGameButton();
	bool exitButton();
	bool helpButton();
	bool openHelpWindow();
	int modeTitle();
	void playerVrsPlayerButton();
	void playerVrsComputerButton();
	void gameWindow();
	
};

