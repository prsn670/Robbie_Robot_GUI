#pragma once
#ifndef _STORE_H
#define _STORE_H

//#include "stdafx.h"
#include "robot_model.h"
#include "robot_arm.h"
#include "robot_battery.h"
#include "robot_head.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "order.h"
#include "customer.h"

class Store{
public:
	vector<Robot_model*> rob;
	vector<Left_Arm*> left_arm;
	vector<Right_Arm*> right_arm;
	vector<Battery*> batt;
	vector<Head*> head;
	vector<Locomotor*> loco;
	vector<Torso*> tor;
	vector<Order*> ord;
	vector<Customer*> cust;
	

	void left_store_arm(string str, double lbs, double money, int part, string desc, string pic, int pow);
	void right_store_arm(string str, double lbs, double money, int part, string desc, string pic, int pow);
	void store_batt(string str, double lbs, double money, int part, string desc, string pic, int nrg);
	void store_head(string str, double lbs, double money, int part, string desc, string pic);
	void store_locomotor(string str, double lbs, double money, int part, string desc, string pic, int speed, int pow);
	void store_torso(string str, double lbs, double money, int part, string desc, string pic, int amt);
	void store_model(string str, double lbs, double money, int part, string desc, string pic);
	void store_cust(string f_name, string l_name, string add, string cty, string st, string code, string ctry, string num);
	
	

	
};


#endif // !_STORE_H

