#pragma once
#ifndef _BUILD_ROBOT_H
#define _BUILD_ROBOT_H

#include "stdafx.h"
#include "iostream"

using namespace std;


void build_base(int selection, class Store &store);//build the common data for each component


void build_model(class Store& store);//collect data specific to model

void build_arm(string str, double lbs, double money, int part, string desc, string pic, class Store& store); //collect data specific to arm

void build_battery(string str, double lbs, double money, int part, string desc, string pic, class Store& store);//collect data specific to battery

void build_head(string str, double lbs, double money, int part, string desc, string pic, class Store& store);

void build_locomotor(string str, double lbs, double money, int part, string desc, string pic, class Store& store); //collect data specific to locomotor

void build_torso(string str, double lbs, double money, int part, string desc, string pic, class Store& store); //collect data specific to torso
#endif // !_BUILD_ROBOT_H
