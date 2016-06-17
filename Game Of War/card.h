// ----------------------------------------------------------------------------
//
//  Header file for class "card"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 5/7/2016
//
// ----------------------------------------------------------------------------


#include<iostream>
#include<string>
using namespace std;
#ifndef _CARD_H_
#define _CARD_H_

enum Suit { CLUBS, SPADES, DIAMONDS, HEARTS };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class card
{
public:
	card();
	Suit getshape(); //Returns suit of the card
	Rank getnumber(); //Returns rank of the card
	void setshape(Suit); //Set suit of the card
	void setnumber(Rank); //Set rank of the card
	string convert_shape(Suit); //Convert suit to it's equivalent alphabet
	string convert_number(Rank); //Convert rank to it's equivalent alphabet/ number


private :
	Suit shape;
	Rank number;
};

ostream & operator<<(ostream & out, card & ca); // To print a card
bool operator==(card one, card two); //To compare weather two cards are equal or not
bool operator<(card one, card two); //To check if first card is greater than second card
bool operator>(card one, card two); //To check if first card is smaller than second card









#endif