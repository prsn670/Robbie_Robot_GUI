//#include "stdafx.h"
/*#include "robot_model.h"
#include "robot_torso.h"
#include "robot_arm.h"
#include "robot_battery.h"
#include "robot_head.h"
#include "robot_locomotor.h"*/
#include "store.h"


//Stores created components and model in vector.


void Store::left_store_arm(string str, double lbs, double money, int part, string desc, string pic, int pow)
{
	left_arm.push_back(new Left_Arm(str, lbs, money, part, desc, pic, pow));
}

void Store::right_store_arm(string str, double lbs, double money, int part, string desc, string pic, int pow)
{
	right_arm.push_back(new Right_Arm(str, lbs, money, part, desc, pic, pow));
}

void Store::store_batt(string str, double lbs, double money, int part, string desc, string pic, int nrg)
{
	batt.push_back(new Battery(str, lbs, money, part, desc, pic, nrg));
}

void Store::store_head(string str, double lbs, double money, int part, string desc, string pic)
{
	head.push_back(new Head(str, lbs, money, part, desc, pic));
}

void Store::store_locomotor(string str, double lbs, double money, int part, string desc, string pic, int speed, int pow)
{
	loco.push_back(new Locomotor(str, lbs, money, part, desc, pic, speed, pow));
}

void Store::store_torso(string str, double lbs, double money, int part, string desc, string pic, int amt)
{
	tor.push_back(new Torso(str, lbs, money, part, desc, pic, amt));
}

void Store::store_model(string str, double lbs, double money, int part, string desc, string pic)
{
	rob.push_back(new Robot_model(str, lbs, money, part, desc, pic));
	
}

void Store::store_cust(string f_name, string l_name, string add, string cty, string st, string code, string ctry, string num)
{
	cust.push_back(new Customer(f_name, l_name, add, cty, st, code, ctry, num));
	
}

