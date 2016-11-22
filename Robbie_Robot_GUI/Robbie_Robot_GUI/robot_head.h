#pragma once
#ifndef _ROBOT_HEAD_H
#define _ROBOT_HEAD_H

//#include "stdafx.h"
#include "robot_model.h"
#include "string"

using namespace std;


class Head : public Robot_model
{
public:
	Head(string str, double lbs, double money, int part, string desc, string pic) : Robot_model(str, lbs, money, part, desc, pic) {}
	
};
#endif