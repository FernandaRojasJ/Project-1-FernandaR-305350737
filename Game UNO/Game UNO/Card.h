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
	string id;
	bool cardSide;
	Texture* cardTexture;
	IntRect* frontImage;
	IntRect* rearImage;
	RectangleShape gameCard;
	bool cardSelected;
public:

	Card();
	Card(string anId);
	Card(string anId, IntRect* aFrontImage, IntRect* aRearImage, bool aCardSide, int aPoints);

	int getPoints();
	void setPoints(int aPoints);

	string getId();
	void setId(string anId);

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

