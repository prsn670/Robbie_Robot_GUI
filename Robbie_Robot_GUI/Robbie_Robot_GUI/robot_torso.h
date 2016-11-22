#pragma once
#ifndef _ROBOT_TORSO_H
#define _ROBOT_TORSO_H

//#include "stdafx.h"
#include "robot_model.h"
#include "string"

using namespace std;


class Torso : public Robot_model
{
private:
	int battery_amt;
	
public:
	Torso(string str, double lbs, double money, int part, string desc, string pic, int amt) : Robot_model(str, lbs, money, part, desc, pic), battery_amt(amt) {}
	int get_battery();
};
#endif