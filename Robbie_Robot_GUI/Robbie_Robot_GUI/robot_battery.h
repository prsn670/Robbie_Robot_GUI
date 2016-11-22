#pragma once
#ifndef _ROBOT_BATTERY_H
#define _ROBOT_BATTERY_H

//#include "stdafx.h"
#include "robot_model.h"

class Battery : public Robot_model
{
private:
	int energy;

public:
	int get_energy();
	Battery(string str, double lbs, double money, int part, string desc, string pic, int nrg) : Robot_model(str, lbs, money, part, desc, pic), energy(nrg) {}

};
#endif // !_ROBOT_BATTERY_H
