// ----------------------------------------------------------------------------
//
//  Header file for class "bat"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------



#ifndef _BAT_1_H_
#define _BAT_1_H_
#include<iostream>
#include<string>
#include"enemy.h"
using namespace std;
class bat : public enemy
{
public:
	bat();
	string getname(); //Returns name of this monster
	int enemy_health(); //Returns health of this monster
	void enemy_damage(int dam); // Causes damage to health
	int enemy_attack(string a); // Decides which attack to carry out
	bool enemy_isdefeated(); // Checks if this enemy is defeated or not
	string getdescription() const; //Returns Description of monster
};

#endif
