// ----------------------------------------------------------------------------
//
// ----------------------------- WAR -------------------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To Create a Simulated Game of War
//
//  Author   : Chetan Kumar Parakh
//  Date     : 5/7/2016
//
// ----------------------------------------------------------------------------



#include<iostream>
#include"card.h"
#include"deck.h"
using namespace std;

int winner();
int game_start();
int check_war(deck temp_1_b, deck temp_2_b);

deck temp, pla_one, pla_two, total;

int main(void)
{
	temp.cre_deck();  //Create A Deck
	temp.suffle_deck(); // Suffle A Deck
	temp.div_deck(pla_one, pla_two);  // Divide the deck into two
	game_start(); // Game Start
	winner(); //Prints out the winner of the game
	return(0);
}


int game_start()
{
	while (pla_one.num_cards() > 0 && pla_two.num_cards() > 0)
	{
		card temp_1 = pla_one.deal_single();
		card temp_2 = pla_two.deal_single();
	
		if (temp_1 > temp_2)
		{
			pla_one.add_new(temp_1);
			pla_one.add_new(temp_2);
			cout << temp_1 << " VS " << temp_2 << endl;
		}
		else if (temp_1 < temp_2)
		{
			pla_two.add_new(temp_2);
			pla_two.add_new(temp_1);
			cout << temp_1 << " VS " << temp_2 << endl;
		}
		else if (temp_1 == temp_2)
		{
			cout<< temp_1 << " VS " << temp_2 << endl;

			if (pla_one.num_cards() > 1 && pla_two.num_cards() > 1)
			{
				deck temp_1_a = pla_one.deal_multi(2);
				deck temp_2_a = pla_two.deal_multi(2);

				total = (total + temp_1_a) + temp_2_a;

				int t = check_war(temp_1_a, temp_2_a);

				if (t == 1)
				{
					pla_one = pla_one + total;
					total.clear();
				}
				else if (t == 2)
				{
					pla_two = pla_two + total;
					total.clear();
				}
				else if (t == 0)
				{
					return(0);
				}
			}
			else
			{
				return(0);
			}
			
		}
	}
	return(0);
}

int check_war(deck temp_1_b, deck temp_2_b)
{
	card a = temp_1_b.get_card(1);
	card b = temp_2_b.get_card(1);
	cout << "WAR!!  " << a << " VS " << b << endl;

	if (a>b)
	{
		return(1);
	}
	else if (a<b)
	{
		return(2);
	}
	else if (a == b)
	{
		if (pla_one.num_cards() > 1 && pla_two.num_cards() > 1)
		{
			deck temp_1_a = pla_one.deal_multi(2);
			deck temp_2_a = pla_two.deal_multi(2);
			total = (total + temp_1_a) + temp_2_a;
			return(check_war(temp_1_a, temp_2_a));
		}
		else
		{
			return(0);
		}
	}
	return(0);
}

int winner()
{
	if ((pla_one.num_cards() == 0 && pla_two.num_cards() == 0) || (pla_one.num_cards() == 1 && pla_two.num_cards() == 1))
	{
		cout << endl << "TIE!" << endl;
		return(0);
	}
	else if ((pla_one.num_cards() == 0 && pla_two.num_cards() != 0) || (pla_one.num_cards() == 1 && pla_two.num_cards() > 1))
	{
		cout << endl << "Player 2 Wins!" << endl;
		return(0);
	}
	else if ((pla_one.num_cards() != 0 && pla_two.num_cards() == 0) || (pla_one.num_cards() > 1 && pla_two.num_cards() == 1))
	{
		cout << endl << "Player 1 Wins!" << endl;
		return(0);
	}
	return(0);
}

