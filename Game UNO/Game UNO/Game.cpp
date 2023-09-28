#include "Game.h"

Game::Game()
{


}

int Game::getTurn()
{
	return Turn;
}

void Game::setTurn(int aTurn)
{
	Turn = aTurn;
}

Player Game::getPlayerOne()
{
	
	return playerOne;
}

void Game::setPlayerOne(Player aPlayerOne)
{
	playerOne = aPlayerOne;
}

Player Game::getPlayerTwo()
{

	return playerTwo;
}

void Game::setPlayerTwo(Player aPlayerTwo)
{
	playerTwo = aPlayerTwo;
}

vector<Card> Game::getTrashDeck()
{
	return trashDeck;
}

void Game::getTrashDeck(vector<Card> aTrashDeck)
{
	trashDeck = aTrashDeck;
}

vector<Card> Game::getCards()
{
	return cards;
}

void Game::getCards(vector<Card> aCards)
{
	cards = aCards;
}

void Game::setTrashCard(Card aTrashCard)
{
	trashCard = aTrashCard;
}

Card Game::getTrashCard()
{
	return trashCard;
}

void Game::assingCardsToPlayer(vector<Card> cards)
{
	
	int index;
	srand(time(NULL));
	
	 
	for (int i = 0; i < 8; ++i)
	{
		
		index = rand() % cards.size();

		playerOne.playerDeck.push_back(cards[index]);
		
		cards.erase(cards.begin() + index); 
		
		
	}

	
	for (int i = 0; i < 8; ++i)
	{
		index = rand() % cards.size(); 
		playerTwo.playerDeck.push_back(cards[index]); 
		cards.erase(cards.begin() + index); 
		
	}
}


void Game::loadCards()
{
	cardTexture.loadFromFile("resources/Cartas/Cartas UNO.png");

	if (!cardTexture.loadFromFile("resources/Cartas/Cartas UNO.png"))
	{
		cout << "no se pudo cargar la imagen";
	}
	Vector2f cardSize(57, 86);
	int cont = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			RectangleShape rectangle;
			Card card;
			rectangle.setSize(cardSize);
			rectangle.setTexture(&cardTexture);
			IntRect area(column * cardSize.x, row * cardSize.y, cardSize.x, cardSize.y);
			rectangle.setTextureRect(area);
			card.setGameCard(rectangle);
			card.setPoints(column);

			if (column < 10)
			{
				if (row < 4)
				{
					card.setId(to_string(row) + "0" + to_string(column));
				}
				else
				{
					card.setId(to_string(row - 4) + "0" + to_string(column));
				}
			}
			else if (column > 9 && column < 13)
			{
				if (row < 4)
				{
					card.setId(to_string(row) + "1" + to_string(column));
				}
				else
				{
					card.setId(to_string(row - 4) + "1" + to_string(column));
				}
			}
			else if (column == 13 && row < 4)
			{
				card.setId(to_string(2));
			}
			else if (column == 13 && row >= 4)
			{
				card.setId(to_string(3));
			}

			if (cont != 56 && cont != 70 && cont != 84 && cont != 98)
			{
				cards.push_back(card);
			}
			cont++;
		}
	}

}

void Game::addCardToDeckOne()
{
	int index;
	index = rand() % cards.size();
	if (playerOne.getPlayerDeck().size() <= 20) {
		playerOne.AddCard(cards[index]);
		cards.erase(cards.begin() + index);
	}
}

void Game::addCardToDeckTwo()
{
	int index;
	index = rand() % cards.size();
	if (playerTwo.getPlayerDeck().size() <= 20) {
		playerTwo.AddCard(cards[index]);
		cards.erase(cards.begin() + index);
	}
	
}

void Game::deleteCardToDeckOne(int position)
{
	playerOne.deleteCard(position);
}

void Game::deleteCardToDeckTwo(int position)
{
	playerTwo.deleteCard(position);
}

Card Game::getRandomCard()
{
	int index;
	index = rand() % cards.size();
	Card temp = cards[index];
	cards.erase(cards.begin() + index);
	return temp;
}

void Game::logicGame(Card aCardselected, int position)
{
	
	if (trashCard.getId()[1] == '0') {
		
		if (aCardselected.getId()[0] == trashCard.getId()[0]) {
			setTrashCard(aCardselected);
			deleteCardToDeckOne(position);
			cout << "Coincide en color (primer carácter)" << endl;
		}
		else {
			cout << "No coincide en color (primer carácter)" << endl;
		}

		
		if (aCardselected.getId()[2] == trashCard.getId()[2]) {
			setTrashCard(aCardselected);
			deleteCardToDeckOne(position);
			cout << "Coincide en numero (tercer carácter)" << endl;
		}
		else {
			cout << "No coincide en numero (tercer carácter)" << endl;
		}
	}
	
	else if (trashCard.getId()[1] == '1') {
		if (aCardselected.getId()[0] == trashCard.getId()[0]) {
			setTrashCard(aCardselected);
			deleteCardToDeckTwo(position);
			cout << "Coincide en color (primer carácter)" << endl;

		}
		else {
			cout << "No coincide en color (primer carácter)" << endl;
		}
	}

	else {
		cout << "No es de tipo numérico" << endl;
	}
}






