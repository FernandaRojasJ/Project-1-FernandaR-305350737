#pragma once
#include <iostream>
#include <string>
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
	Player playerOne = Player("Jugador 1", 0);
	Player playerTwo = Player("Judador 2", 0);
	vector<Card> trashDeck;
	vector<Card> cards;

	
	
public:
	Game();
	Card trashCard;
	int Turn = 1;

	int getTurn();
	void setTurn(int aTurn);

	Player getPlayerOne();
	void setPlayerOne(Player aPlayerOne);

	Player getPlayerTwo();
	void setPlayerTwo(Player aPlayerTwo);

	vector<Card> getTrashDeck();
	void getTrashDeck(vector<Card> aTrashDeck);

	vector<Card> getCards();
	void getCards(vector<Card> aCards);

	void setTrashCard(Card aTrashCard);
	Card getTrashCard();

	void assingCardsToPlayer(vector<Card> aCards);

	void loadCards();

	void addCardToDeckOne();
	void addCardToDeckTwo();

	void deleteCardToDeckOne(int position);
	void deleteCardToDeckTwo(int position);

	Card getRandomCard();

	void logicGame(Card aCardselected, int position);

};

