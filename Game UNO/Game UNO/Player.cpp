#include "Player.h"


Player::Player(string aName, int aPoints)
{
	name = aName;
	points = aPoints;
}

string Player::getName()
{
	return name;
}

int Player::getPoints()
{
	return points;
}

void Player::setPoints(int aPoints)
{
	name = aPoints;
}

void Player::setName(string aName)
{
	name = aName;
}

vector<Card> Player::getPlayerDeck()
{
	return playerDeck;
}

void Player::setPlayerDeck(vector<Card> aPlayerDeck)
{
	playerDeck = aPlayerDeck;
}

void Player::AddCard(Card card)
{
	playerDeck.push_back(card);
}

void Player::deleteCard(int position)
{
	playerDeck.erase(playerDeck.begin() + position);
}
