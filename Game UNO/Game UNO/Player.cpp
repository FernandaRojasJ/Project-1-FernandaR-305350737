#include "Player.h"


Player::Player(string aName)
{
	name = aName;
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


string Player::getName()
{
	return name;
}
