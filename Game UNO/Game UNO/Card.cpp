#include "Card.h"

Card::Card()
{
	points = 0;
	id = "";
	cardSide = true;
	rearImage = 	frontImage = new IntRect();
new IntRect();
	gameCard.setSize(Vector2f(57, 86));

}

Card::Card(string anId)
{
	points = 0;
	id = anId;
	cardSide = true;
	frontImage = new IntRect();
	rearImage = new IntRect();

	gameCard.setSize(Vector2f(57, 86));
}

Card::Card(string anId, IntRect* aFrontImage, IntRect* aRearImage, bool aCardSide, int aPoints)
{
	id = anId;
	frontImage = aFrontImage;
	rearImage = aRearImage;
	cardSide = aCardSide;
	points = aPoints;
	gameCard.setSize(Vector2f(57, 86));

}

int Card::getPoints()
{
	return points;
}

void Card::setPoints(int aPoints)
{
	points = aPoints;
}

string Card::getId() 
{
	return id;
}

void Card::setId(string anId)
{
	id = anId;
}

IntRect* Card::getRearImage()
{
	return rearImage;
}

Texture* Card::getCardTexture()
{
	return cardTexture;
}

void Card::setCardTexture(Texture* aFrontImage)
{
	cardTexture = aFrontImage;
}

IntRect* Card::getFrontImage()
{
	return frontImage;
}

void Card::setFrontImage(IntRect* aFrontImage)
{
	frontImage = aFrontImage;
}

void Card::setRearImage(IntRect* aRearImage)
{
	rearImage = aRearImage;
}

RectangleShape Card::getGameCard()
{
	return gameCard;
}

void Card::setGameCard(RectangleShape aGameCard)
{
	gameCard = aGameCard;
}

bool Card::getCardSide()
{
	return cardSide;
}

void Card::setCardSide(bool aCardSide)
{
	if (aCardSide)
	{
		gameCard.setTextureRect(*frontImage);

	}

	else
	{
		gameCard.setTextureRect(*rearImage);
	}
}

