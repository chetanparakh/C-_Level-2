// ----------------------------------------------------------------------------
//
//  Implementation file for class "hero"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------

#include"hero.h"
#include<sstream>
hero::hero()
{
	health_ = 1000;
	potion_ = 6;
	fireball_ = 10;
	defend_mode = false;
}
void hero::setname(string temp)
{
	name_ = temp;
}
string hero::getname()
{
	return(name_);
}
int hero::get_fireball()
{
	return(fireball_);
}
int hero::get_potion()
{
	return(potion_);
}
int hero::enemy_health()
{
	return(health_);
}
void hero::enemy_damage(int dam)
{
	if (defend_mode)
	{
		health_ -= (dam/2);
	}
	else
	{
		health_ -= dam;
	}
	defend_mode = false;
}
int hero::enemy_attack(string att)
{
	if (att == "sword")
	{
		cout << "Sword Slash Attack!" << endl;
		return(50);
	}
	if (att == "fireball")
	{
		if (fireball_ > 0)
		{
			cout << "Fireeee" << endl;
			fireball_--;
			return(100);
		}
		else
		{
			cout << "No more fireball" << endl;
		}
	}
	if (att == "potion")
	{
		if (potion_ > 0)
		{
			potion_--;
			health_ += 85;
			return(0);
		}
		else
		{
			cout << "No more potion" << endl;
			return(0);						// Check this out;
		}
	}
	if (att == "shield")
	{
		defend_mode = true;
		return(0);
	}
}
bool hero::enemy_isdefeated()
{
	if (health_ <= 0)
	{
		return(true);
	}
	return(false);
}
string hero::getdescription() const
{
	return("ERRRROR");
}

string hero::get_status()
{
	ostringstream temp;
	temp << name_ << ": " << enemy_health() << "/1000 health Remaining: " << fireball_ << " Fireballs, " << potion_ << " Potions.";
	return(temp.str());
}