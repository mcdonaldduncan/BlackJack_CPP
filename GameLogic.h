#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<int> GenerateDeck(int deckSize, int deckCount);

int DealCard(vector<int>* deck);

int HasAces(vector<int>* hand);

void AcesToOne(vector<int>* hand);

int SumHand(vector<int>* hand);

int HitOrStay(vector<int>* hand, int dealerFirstCard);

int DealerHitOrStay(int handSum);

