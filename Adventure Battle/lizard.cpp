// ----------------------------------------------------------------------------
//
//  Implementation file for class "lizard"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------

#include"lizard.h"

lizard::lizard()
{
	health_ = 400;
	name_ = "lizard";
}
string lizard::getname()
{
	return name_;
}
int lizard::enemy_health()
{
	return(health_);
}
void lizard::enemy_damage(int dam)
{
	health_ -= dam;
}
int lizard::enemy_attack(string a)
{
	int temp = time(NULL);
	if ((temp % 2) == 0)
	{
		cout << "Lizard Jumps!!!" << endl;
		return(50);
	}
	else
	{
		cout << "Lizard Flash Attack!!!" << endl;
		return(75);
	}
}
bool lizard::enemy_isdefeated()
{
	if (health_ <= 0)
	{
		return(true);
	}
	return(false);
}
string lizard::getdescription() const
{
	return("You have encountered a lizard!");
}