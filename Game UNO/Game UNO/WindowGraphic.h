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
	bool modeSelected = false;




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
	bool playerVrsPlayerButton();
	bool playerVrsComputerButton();
	void gameWindow();
	string getselectedMode() const
	{
		return selectedMode;
	}
	void setSelectedMode(const string& mode)
	{
		selectedMode = mode;
	}
};

