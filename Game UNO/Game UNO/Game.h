#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Card.h"
#include "Player.h"


using namespace std;
using namespace sf;

class Game
{
private:
	int rows = 8;
	int columns = 14;
	Texture cardTexture;
	Player playerOne= Player("Jugador 1: ");
	Player playerTwo = Player("Judador 2: ");
	vector<Card> trashDeck;
	vector<Card> cards;
public:
	Game();

	void loadCards();

	Player getPlayerOne();
	void setPlayerOne(Player aPlayerOne);

	Player getPlayerTwo();
	void setPlayerTwo(Player aPlayerTwo);

	vector<Card> getTrashDeck();
	void getTrashDeck(vector<Card> aTrashDeck);

	vector<Card> getCards();
	void getCards(vector<Card> aCards);

	void assingCardsToPlayer();

	void mainDeck();


};

