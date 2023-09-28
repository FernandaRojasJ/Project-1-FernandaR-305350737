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
	vector<Card> playerDeck;

	Player(string aName, int aPoints);

	string getName();
	void setName(string aName);

	int getPoints();
	void setPoints(int aPoints);

	vector<Card> getPlayerDeck();
	void setPlayerDeck(vector<Card> aPlayerDeck);

	void AddCard(Card card);
	void deleteCard(int position);
};

