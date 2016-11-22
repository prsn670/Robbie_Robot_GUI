#pragma once
#ifndef _ORDER_H
#define _ORDER_H

#include "stdafx.h"
#include "vector"

using namespace std;
class Order {

private:
	vector<int> model_ind;//index of model ordered
	vector<int> qty; //quantity of model ordered
	string cust_name;//customer name
	string date;//date of order
	string sales_assoc;//name of sales associate
	int order_num;//order number
	double price;//sub total
	
public:
	void set_indices(int ind, int amt);//sets the indexes for model_ind and qty
	void set_ord_num(int num);//sets order number
	void set_price(double cost);
	string get_name();
	string get_date();
	string get_assoc();
	int get_ord_num();
	int get_size();//returns size of the vector model_ind
	int get_model_index(int i);//gets index of model ordered
	int get_qty(int i);
	double get_price();
	Order(string name, string date, string sa_name, double cost) : cust_name(name), date(date), sales_assoc(sa_name), price(cost) {};
	
};



#endif // !_ORDER_H

