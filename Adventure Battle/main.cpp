// ----------------------------------------------------------------------------
//
// ----------------------------- Adventure Battle -------------------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose  : To Create combat game
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------


#include"bat_1.h"
#include"enemy.h"
#include"hero.h"
#include"dragon.h"
#include"wolf.h"
#include"bear.h"
#include"lizard.h"
#include<string>
#include<vector>
#include <stdlib.h>   
using namespace std;

hero* hero_1 = new hero;
vector<enemy*> enem;
int main(void)
{
	string name, command;
	int dam_amt, num, rand_num;

	srand(time(NULL));

	cout << "Welcome to Adventure Battle!" << endl;
	cout << "What is the name of your hero: ";
	cin >> name;
	hero_1->setname(name);
	cout << "How many enemies do you want to fight? ";
	cin >> num;

	// Creating Enemy
	for (int i = 0; i < num; i++)
	{
		rand_num = rand() % 5;
		switch (rand_num)
		{
		case 0: enem.push_back(new bat);
			break;
		case 1: enem.push_back(new dragon);
			break;
		case 2: enem.push_back(new bear);
			break;
		case 3: enem.push_back(new wolf);
			break;
		case 4: enem.push_back(new lizard);
			break;
		default:
			break;
		}
	}

	// Combat between hero and enemy
	for (int i = 0; i < num; i++)
	{

		cout << "You have encountered a " << enem[i]->getname() << endl;
		bool check = false;
		while (hero_1->enemy_health() > 0 && enem[i]->enemy_health() > 0)
		{
			cout << hero_1->get_status() << endl;
			do
			{
				cout << "Enter Commands: sword, shield, fireball, potion, exit" << endl;
				cin >> command;
				if (command == "exit")
				{
					cout << "Thanks For Playing!" << endl;
					return(0);
				}
				check = false;
				if (command != "sword" && command != "shield" && command != "fireball" && command != "potion")
				{
					check = true;
				}
				if(command=="fireball" && hero_1->get_fireball()<=0)
				{ 
					cout << "No more fireball" << endl;
					check = true;
				}
				if(command == "potion" && hero_1->get_potion() <= 0)
				{
					cout << "No more potion" << endl;
					check = true;
				}

			} while (check);
			dam_amt = hero_1->enemy_attack(command);
			enem[i]->enemy_damage(dam_amt);
			if (enem[i]->enemy_health() > 0)
			{
				dam_amt = enem[i]->enemy_attack("NULL");
				hero_1->enemy_damage(dam_amt);
			}
		}

		// Checking Winnwe
			if ((hero_1->enemy_health() <= 0) && (enem[i]->enemy_health() > 0))
			{
				cout << "Player Is Defeated!" << endl;
				return(0);
			}
			else if (hero_1->enemy_health() > 0 && enem[i]->enemy_health() <= 0)
			{
				cout << "Enemy Is Defeated!" << endl;
			}


		cout << endl << endl;
	}
	
	cout << "You have defeated all enemies and saved the world. Good Job." << endl;
	delete(hero_1);


	// Deleting Dynamically allocated memory
	for (int i = 0; i < num; i++)
	{
		delete (enem[i]);
	}

	return(0);
}