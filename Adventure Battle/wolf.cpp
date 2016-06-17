// ----------------------------------------------------------------------------
//
//  Implementation file for class "wolf"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------

#include"wolf.h"

wolf::wolf()
{
	health_ = 300;
	name_ = "wolf";
}
string wolf::getname()
{
	return name_;
}
int wolf::enemy_health()
{
	return(health_);
}
void wolf::enemy_damage(int dam)
{
	health_ -= dam;
}
int wolf::enemy_attack(string a)
{
	int temp = time(NULL);
	if ((temp % 2) == 0)
	{
		cout << "Wolf Tackles!!!" << endl;
		return(50);
	}
	else
	{
		cout << "Wolf Bites!!!" << endl;
		return(75);
	}
}
bool wolf::enemy_isdefeated()
{
	if (health_ <= 0)
	{
		return(true);
	}
	return(false);
}
string wolf::getdescription() const
{
	return("You have encountered a wolf!");
}