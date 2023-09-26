#pragma once
#include<iostream>
#include "Card.h"

using namespace std;
class Player
{
private:

	string name;
	int points;

	

public:

	Player(string aName);

	vector<Card> playerDeck;

	string getName();
	void setName(string aName);

	vector<Card> getPlayerDeck();
	void setPlayerDeck(vector<Card> aPlayerDeck);

	




	




};

