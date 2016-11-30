#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "FL/Fl.h"
#include "iostream"
using namespace std;

class Customer
{
private:
	string first;
	string last;
	string address;
	string city;
	string state;
	string zip;
	string country;
	string number;
	int cust_num;

public:
	string get_first();
	string get_last();
	string get_add();
	string get_city();
	string get_state();
	string get_zip();
	string get_country();
	string get_number();
	void set_cust_num(int cust_num);
	int get_cust_num();
	Customer(string first_n, string last_n, string add, string cty, string st, string code, string cntry, string num):
		first(first_n), last(last_n), address(add), city(cty), state(st), zip(code), country(cntry), number(num) {};

};

void custCB(Fl_Widget* w, void* p);
void create_custCB(Fl_Widget* w, void* p);
#endif // !_ROB_PART_INPUT_H


