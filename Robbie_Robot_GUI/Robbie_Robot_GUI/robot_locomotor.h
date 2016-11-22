#pragma once
#ifndef _ROBOT_LOCOMOTOR_H
#define _ROBOT_LOCOMOTOR_H

#include "robot_model.h"
//#include "stdafx.h"

class Locomotor:public Robot_model
{
private:
	int max_speed;
	int power;

public:
	int get_power();
	int get_max_speed();
	Locomotor(string str, double lbs, double money, int part, string desc, string pic, int speed, int pow) : Robot_model(str, lbs, money, part, desc, pic), max_speed(speed), power(pow) {}

};
#endif // !_ROBOT_LOCOMOTOR_H
