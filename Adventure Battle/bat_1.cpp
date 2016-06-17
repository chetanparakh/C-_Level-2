// ----------------------------------------------------------------------------
//
//  Implementation file for class "bat"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------

#include"bat_1.h"

bat::bat()
{
	health_ = 300;
	name_ = "Bat";
}
string bat::getname()
{
	return name_;
}
int bat::enemy_health()
{
	return(health_);
}
void bat::enemy_damage(int dam)
{
	health_ -= dam;
}
int bat::enemy_attack(string a)
{
	int temp = time(NULL);
	if ((temp % 2) == 0)
	{
		cout << "Bat Screams with UltraSonic Waves" << endl;
		return(50);
	}
	else
	{
		cout << "Bat Bites You" << endl;
		return(75);
	}
}
bool bat::enemy_isdefeated()
{
	if (health_ <= 0)
	{
		return(true);
	}
	return(false);
}
string bat::getdescription() const
{
	return("You have encountered a Bat!");
}