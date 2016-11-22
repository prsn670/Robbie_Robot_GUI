#pragma once
#ifndef _ROBOT_ARM_H
#define	_ROBOT_ARM_H
#include "robot_model.h"
//#include "stdafx.h"

class Left_Arm : public Robot_model
{
protected:
	int power;

public:
	int get_power();
	Left_Arm(string str, double lbs, double money, int part, string desc,string pic, int pow) : Robot_model(str, lbs, money, part, desc, pic), power(pow) {}
};

class Right_Arm : public Robot_model
{
protected:
	int power;

public:
	int get_power();
	Right_Arm(string str, double lbs, double money, int part, string desc, string pic, int pow) : Robot_model(str, lbs, money, part, desc, pic), power(pow) {}
};


#endif // !_ROBOT_ARM_H
