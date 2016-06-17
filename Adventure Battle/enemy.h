// ----------------------------------------------------------------------------
//
//  Header file for class "enemy"
//
//  Author   : Chetan Kumar Parakh
//  Date     : 6/2/2016
//
// ----------------------------------------------------------------------------

#ifndef _ENEMY_H_
#define _ENEMY_H_
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class enemy {
public:
	enemy();
	virtual string getname() = 0;
	virtual int enemy_health() = 0;
	virtual void enemy_damage(int) = 0;
	virtual int enemy_attack(string) = 0;
	virtual bool enemy_isdefeated() = 0;
	virtual string getdescription() const = 0;
protected:
	int health_;
	string name_;

};
#endif // !_ENEMY_H_#pragma once
