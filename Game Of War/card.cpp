// ----------------------------------------------------------------------------
//
//  Implementation file for class "card"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 5/7/2016
//
// ----------------------------------------------------------------------------

#include"card.h"
using namespace std;
card::card()
{
	shape = HEARTS;
	number = ACE;
}

//Returns suit of the card
Suit card::getshape()
{
	return(shape);
}

//Returns rank of the card
Rank card::getnumber()
{
	return(number);
}

//Set suit of the card
void card::setshape(Suit temp_s)
{
	shape = temp_s;
}

//Set rank of the card
void card::setnumber(Rank temp_r)
{
	number = temp_r;
}

//Convert suit to it's equivalent alphabet
string card::convert_shape(Suit temp)
{
	switch (temp)
	{
	case CLUBS: return("C");
		break;
	case SPADES: return("S");
		break;
	case DIAMONDS: return("D");
		break;
	case HEARTS: return("H");
		break;
	default:
		break;
	}
}

//Convert rank to it's equivalent alphabet/ number
string card::convert_number(Rank temp)
{
	switch (temp)
	{
	case TWO: return("2");
		break;
	case THREE:return("3");
		break;
	case FOUR:return("4");
		break;
	case FIVE:return("5");
		break;
	case SIX:return("6");
		break;
	case SEVEN:return("7");
		break;
	case EIGHT:return("8");
		break;
	case NINE:return("9");
		break;
	case TEN:return("10");
		break;
	case JACK:return("J");
		break;
	case QUEEN:return("Q");
		break;
	case KING:return("K");
		break;
	case ACE:return("A");
		break;
	default:
		break;
	}
}

// To print a card
ostream & operator<<(ostream & out, card & ca)
{
	out << ca.convert_number(ca.getnumber());
	out << ca.convert_shape(ca.getshape());
	return(out);
}

//To compare weather two cards are euqal or not
bool operator==(card one, card two)
{
	if ((one.getnumber() == two.getnumber())) //&& (one.getshape == two.getshape())
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

//To check if first card is greater than second card
bool operator>(card one, card two)
{
	if (one.getnumber()>two.getnumber())
	{
		return(true);
	}
	return(false);
}

//To check if first card is smaller than second card
bool operator<(card one, card two)
{
	if (one.getnumber() < two.getnumber())
	{
		return(true);
	}
	return(false);
}