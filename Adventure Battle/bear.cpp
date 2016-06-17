
// ----------------------------------------------------------------------------
//
//  Implementation file for class "bear"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------
#include"bear.h"

bear::bear()
{
	health_ = 300;
	name_ = "bear";
}
string bear::getname()
{
	return name_;
}
int bear::enemy_health()
{
	return(health_);
}
void bear::enemy_damage(int dam)
{
	health_ -= dam;
}
int bear::enemy_attack(string a)
{
	int temp = time(NULL);
	if ((temp % 2) == 0)
	{
		cout << "Bear Roar!!!" << endl;
		return(100);
	}
	else
	{
		cout << "Bear Hit!!!" << endl;
		return(75);
	}
}
bool bear::enemy_isdefeated()
{
	if (health_ <= 0)
	{
		return(true);
	}
	return(false);
}
string bear::getdescription() const
{
	return("You have encountered a bear!");
}