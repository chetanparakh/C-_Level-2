// ----------------------------------------------------------------------------
//
//  Implementation file for class "deck"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 5/7/2016
//
// ----------------------------------------------------------------------------


#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"deck.h"


deck::deck()
{
	all_card.clear();
}

//Creating a Deck Of Card
void deck::cre_deck()
{
	card temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			temp.setshape(static_cast<Suit>(i));
			temp.setnumber(static_cast<Rank>(j));
			all_card.push_back(temp);
		}
	}
}

//Dividing a deck of card into two
void deck::div_deck(deck & pla_one, deck & pla_two)
{
	int ind;
	for (ind = 0; ind < (all_card.size() / 2) - 1; ind++)
	{
		pla_one.add_new(all_card[ind]);
	}
	ind++;
	for (int k = 0; k < (all_card.size() / 2) - 1; k++)
	{
		pla_two.add_new(all_card[ind]);
		ind++;
	}
}

//To shuffle deck of card
void deck::suffle_deck()
{
	srand(time(NULL));
	for (int ind = 0; ind < all_card.size() - 2; ind++)
	{
		int j = rand() % all_card.size() - ind;
		{
			card exc;
			exc = all_card[ind];
			all_card[ind] = all_card[ind + j];
			all_card[ind + j] = exc;
		}
	}
}

//To deal a single card from top of the deck
card deck::deal_single()
{
	card temp = all_card[all_card.size() - 1];
	all_card.pop_back();
	return(temp);
}

//To deal multiple card from top of the deck
deck deck::deal_multi(int n)
{
	deck a;
	for (int i = 0; i < n; i++)
	{
		a.add_new(all_card[all_card.size() - 1]);
		all_card.pop_back();
	}
	return(a);
}

//To find number of cards in a deck
int deck::num_cards() const
{
	return(all_card.size());
}

//To add new card
void deck::add_new(card temp)
{
	all_card.insert(all_card.begin(), temp);
}

//Get the card at i'th position
card deck::get_card(int i) const
{
	return(all_card[i]);
}

// To clear all the elements in the deck of the object
void deck::clear()
{
	all_card.clear();
}

//To add two deck objects
deck operator+(const deck & one, const deck & two)
{
	deck temp;
	int ind;
	for (ind = 0; ind < one.num_cards(); ind++)
	{
		temp.add_new(one.get_card(ind));
	}
	ind++;
	for (int j = 0; j < two.num_cards(); j++)
	{
		temp.add_new(two.get_card(j));
	}
	return(temp);
}

