#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Card
{
private:
	int points;
	int id;
	bool cardSide;
	Texture* cardTexture;
	IntRect* frontImage;
	IntRect* rearImage;
	RectangleShape gameCard;
public:

	Card();
	Card(int anId);
	Card(int anId, IntRect* aFrontImage, IntRect* aRearImage, bool aCardSide, int aPoints);

	int getPoints();
	void setPoints(int aPoints);

	int getId();
	void setId(int anId);

	Texture* getCardTexture();
	void setCardTexture(Texture* aFrontImage);

	IntRect* getFrontImage();
	void setFrontImage(IntRect* aFrontImage);

	IntRect* getRearImage();
	void setRearImage(IntRect* aRearImage);

	RectangleShape getGameCard();
	void setGameCard(RectangleShape aGameCard);

	bool getCardSide();
	void setCardSide(bool aCardSide);
	
	
	
};

