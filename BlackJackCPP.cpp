// BlackJackCPP.cpp : Defines the entry point for the application.
//
#include "GameLogic.h"
#include "BlackJackCPP.h"

using namespace std;

int main()
{
	int deckSize = 52;
	int deckCount = 1;
	int handsToPlay = 100;
	int currentHand = 0;
	int startingCardsPerHand = 2;
	int win = 0;
	int loss = 0;
	int tie = 0;

	vector<int> deck;
	vector<int> dealerHand;
	vector<int> playerHand;

	deck = GenerateDeck(deckSize, deckCount);
	
	while (currentHand < handsToPlay)
	{
		if (!dealerHand.empty())
		{
			dealerHand.clear();
		}
		
		if (!playerHand.empty())
		{
			playerHand.clear();
		}

		int playerState = 1;
		int dealerState = 1;

		if (deck.size() < 4)
		{
			deck = GenerateDeck(deckSize, deckCount);
		}

		for (int i = 0; i < startingCardsPerHand; i++)
		{
			playerHand.push_back(DealCard(&deck));
			dealerHand.push_back(DealCard(&deck));
		}

		cout << "Player Hand " << playerHand[0] << ", " << playerHand[1] << endl;
		cout << "Dealer Hand " << dealerHand[0] << ", " << dealerHand[1] << endl;


		if (SumHand(&dealerHand) == 21 && SumHand(&playerHand) == 21)
		{
			cout << "Hand " << currentHand << " Result: Natural Stand-Off" << endl;
			currentHand++;
			tie++;
			continue;
		}

		if (SumHand(&dealerHand) == 21)
		{
			cout << "Hand " << currentHand << " Result: Dealer Natural" << endl;
			currentHand++;
			loss++;
			continue;
		}

		if (SumHand(&playerHand) == 21)
		{
			cout << "Hand " << currentHand << " Result: Player Natural" << endl;
			currentHand++;
			win++;
			continue;
		}


		while (HitOrStay(&playerHand, dealerHand[0]) == 1)
		{
			playerHand.push_back(DealCard(&deck));
			cout << "Player Hit, recieved: " << playerHand.back() << " HandSum: " << SumHand(&playerHand) << endl;
			cout << "Player Hand ";
			
			for (int i = 0; i < playerHand.size(); i++)
			{
				cout << playerHand[i] << ", ";
			}
			cout << endl;

			if (SumHand(&playerHand) > 21)
			{
				AcesToOne(&playerHand);
			}

			if (playerHand.back() == 0)
			{
				deck = GenerateDeck(deckSize, deckCount);
			}
		}

		if (SumHand(&playerHand) == 21)
		{
			cout << "Hand " << currentHand << " Result: Player BlackJack" << endl;
			currentHand++;
			win++;
			continue;
		}

		if (SumHand(&playerHand) > 21)
		{
			cout << "Hand " << currentHand << " Result: Player Busts" << endl;
			currentHand++;
			loss++;
			continue;
		}

		while (DealerHitOrStay(SumHand(&dealerHand)) == 1)
		{
			dealerHand.push_back(DealCard(&deck));
			cout << "Dealer Hit, recieved: " << dealerHand.back() << " HandSum: " << SumHand(&dealerHand) << endl;
			cout << "Player Hand ";

			for (int i = 0; i < dealerHand.size(); i++)
			{
				cout << dealerHand[i] << ", ";
			}
			cout << endl;
			if (dealerHand.back() == 0)
			{
				deck = GenerateDeck(deckSize, deckCount);
			}
		}

		if (SumHand(&dealerHand) > 21)
		{
			cout << "Hand " << currentHand << " Result: Dealer Busts" << endl;
			currentHand++;
			win++;
			continue;
		}


		if (SumHand(&playerHand) > SumHand(&dealerHand))
		{
			cout << "Hand " << currentHand << " Result: Player Wins" << endl;
			currentHand++;
			win++;
			continue;
		}
		else if (SumHand(&playerHand) < SumHand(&dealerHand))
		{
			cout << "Hand " << currentHand << " Result: Dealer Wins" << endl;
			loss++;
			currentHand++;
			continue;
		}
		else
		{
			cout << "Hand " << currentHand << " Result: Stand-Off" << endl;
			tie++;
			currentHand++;
			continue;
		}

	}
	


	cout << "Total Hands Won: " << win << endl;
	cout << "Total Hands Lost: " << loss << endl;
	cout << "Total Hands Tied: " << tie << endl;

	std::getchar();

	return 0;
}
