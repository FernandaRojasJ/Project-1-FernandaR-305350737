#include "Player.h"


Player::Player(string aName)
{
	name = aName;
}

void Player::setName(string aName)
{
	name = aName;
}

string Player::getName()
{
	return name;
}
