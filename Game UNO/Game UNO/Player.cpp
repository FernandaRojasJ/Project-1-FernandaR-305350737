#include "Player.h"


Player::Player(string aName)
{
	name = aName;
}

void Player::setName(string aName)
{
	name = aName;
}

vector<Card> Player::getPlayerOneDeck()
{
	return vector<Card>();
}

void Player::setPlayerOneDeck(vector<Card> aPlayerOneDeck)
{

}

string Player::getName()
{
	return name;
}
