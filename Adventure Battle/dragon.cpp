// ----------------------------------------------------------------------------
//
//  Implementation file for class "dragon"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------


#include"dragon.h"

dragon::dragon()
{
	health_ = 300;
	name_ = "dragon";
}
string dragon::getname()
{
	return name_;
}
int dragon::enemy_health()
{
	return(health_);
}
void dragon::enemy_damage(int dam)
{
	health_ -= dam;
}
int dragon::enemy_attack(string a)
{
	int temp = time(NULL);
	if ((temp % 2) == 0)
	{
		cout << "Dragon Flame!!!" << endl;
		return(50);
	}
	else
	{
		cout << "Dragon Crush!!!" << endl;
		return(75);
	}
}
bool dragon::enemy_isdefeated()
{
	if (health_ <= 0)
	{
		return(true);
	}
	return(false);
}
string dragon::getdescription() const
{
	return("You have encountered a dragon!");
}