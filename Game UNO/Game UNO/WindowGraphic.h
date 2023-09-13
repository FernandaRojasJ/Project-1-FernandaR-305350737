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
	//RenderWindow window;
	
	Texture backroundTexture;
	RectangleShape background;
	RectangleShape button;




public:
	WindowGraphic();
	void printMainMenu();
	void processMainMenuEvents();
	void closeWindowAction();
    bool startGamebutton();
	

};

