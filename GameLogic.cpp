#include "GameLogic.h"
#include <cstdlib>


vector<int> GenerateDeck(int deckSize, int deckCount)
{
	vector<int> temp;
	int decksAdded = 0;

	while (decksAdded < deckCount)
	{
		int currentValue = 1;
		int currentCount = 0;
		for (int i = 0; i < deckSize; i++)
		{
			if (i > deckSize - 4)
			{
				currentValue = 11;
			}

			temp.push_back(currentValue);

			if (++currentCount >= 4)
			{
				currentValue++;
				currentCount = 0;
			}

			if (currentValue > 10)
			{
				currentValue = 10;
			}
		}
		decksAdded++;
	}
	
	srand(time(NULL));

	for (int i = 0; i < temp.size(); i++)
	{
		int r = rand() % temp.size();
		
		int tempValue = temp[r];
		temp[r] = temp[i];
		temp[i] = tempValue;
	}

	return temp;
	
}

int DealCard(vector<int>* deck)
{
	if (deck->empty())
	{
		return 0;
	}
	int card = deck->back();
	deck->pop_back();
	return card;
}

int HasAces(vector<int>* hand)
{
	for (int i = 0; i < hand->size(); i++)
	{
		if (hand->at(i) == 11)
		{
			return 1;
		}
	}
	return 0;
}

void AcesToOne(vector<int>* hand)
{
	for (int i = 0; i < hand->size(); i++)
	{
		if (hand->at(i) == 11)
		{
			hand->at(i) = 1;
			return;
		}
	}
	
}

int SumHand(vector<int>* hand)
{
	int sum = 0;
	for (int i = 0; i < hand->size(); i++)
	{
		sum += hand->at(i);
	}
	if (sum > 21)
	{
		if (HasAces(hand) == 1)
		{
			AcesToOne(hand);
			return SumHand(hand);
		}
	}
	return sum;
}

int HitOrStay(vector<int>* hand, int dealerFirstCard)
{
	int handSum = SumHand(hand);
	int hard = HasAces(hand);

	if (hard == 0)
	{
		if (handSum < 12)
		{
			return 1;
		}
		else
		{
			if (dealerFirstCard > 6 && handSum < 17)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		if (handSum < 15)
		{
			return 1;
		}
		else
		{
			if (handSum < 19)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

int DealerHitOrStay(int handSum)
{ 
	if (handSum < 17)
	{
		return 1;
	}
	return 0;
}