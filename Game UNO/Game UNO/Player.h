#pragma once
#include<iostream>
#include "Card.h"

using namespace std;
class Player
{
private:

	string name;
	int points;
	vector<Card> playerOneDeck;
	vector<Card>playerTwoDeck;
	

public:

	Player(string aName);

	string getName();
	void setName(string aName);

	vector<Card> getPlayerOneDeck();
	void setPlayerOneDeck(vector<Card>aPlayerOneDeck);




	




};

