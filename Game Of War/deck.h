// ----------------------------------------------------------------------------
//
//  Header file for class "deck"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 5/7/2016
//
// ----------------------------------------------------------------------------


#include<iostream>
#include<vector>
#include"card.h"
using namespace std;

#ifndef _DECK_H_
#define _DECK_H_

class deck
{
public:
	deck();

	void cre_deck(); //Creating a Deck Of Card
	void div_deck(deck & pla_one, deck & pla_two); //Dividing a deck of card into two
	void suffle_deck(); //To shuffle deck of card
	card deal_single(); //To deal a single card from top of the deck
	deck deal_multi(int); //To deal multiple card from top of the deck
	int num_cards() const; //To find number of cards in a deck
	void add_new(card); //To add new card
	card get_card(int i) const; //Get the card at i'th position
	void clear(); // To clear all the elements in the deck of the object

private:
	vector<card> all_card;
};

deck operator+(const deck & one, const deck & two); //To add two deck objects

#endif

