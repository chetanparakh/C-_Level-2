// ----------------------------------------------------------------------------
//
//  Header file for class "hero"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------

#ifndef _HERO_H_
#define _HERO_H_

#include<iostream>
#include<string>
#include"enemy.h"
using namespace std;
class hero : public enemy
{
public:
	hero();
	void setname(string temp); // Sets name of the hero
	string getname(); // Returns name of the hero
	int enemy_health(); // Returns health of the hero
	int get_fireball();// Returns number of fireball remaining
	int get_potion(); // Returns number of potion remaining
	void enemy_damage(int dam); // Causes damage to health
	int enemy_attack(string att); // Decides which attack to carry out
	bool enemy_isdefeated(); // Checks if this hero is defeated or not
	string getdescription() const; // Returns description of hero
	string get_status(); // Returns Status of hero
private:
	int potion_; // Store number of potion remaining
	int fireball_; //Store number of fireball remaining
	bool defend_mode; // Checks if the shield is activated or not
};
#endif // !_HERO_H_