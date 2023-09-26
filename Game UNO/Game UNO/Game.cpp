#include "Game.h"

Game::Game()
{


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
					card.setId(row + 0 + column);
				}
				else 
				{
					card.setId((row-4) + 0 + column);
				}
			}
			else if (column > 9 && column < 13) 
			{
				if (row < 4) 
				{
					card.setId(row + 1 + column);
				}
				else 
				{
					card.setId((row - 4) + 1 + column);
				}
			}
			else if (column == 13 && row < 4)
			{
				card.setId(2);
			}
			else if (column == 13 && row >= 4) 
			{
				card.setId(3);
			}

			if(cont != 56 && cont != 70 && cont != 84 && cont != 98) 
			{
				cards.push_back(card);
			}
			cont++;
			cout << "se agrega bien";
		}
	}
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

void Game::assingCardsToPlayer()
{
	
	
}
