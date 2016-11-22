#include "stdafx.h"
#include "order.h"





void Order::set_indices(int ind, int amt)
{
	model_ind.push_back(ind);
	qty.push_back(amt);
}

void Order::set_ord_num(int num)
{
	order_num = num;
}

void Order::set_price(double cost)
{
	price += (cost*1.15);
}

string Order::get_name()
{
	return cust_name;
}

string Order::get_date()
{
	return date;
}

string Order::get_assoc()
{
	return sales_assoc;
}

int Order::get_ord_num()
{
	return order_num;
}

int Order::get_size()
{
	return model_ind.size();
}

int Order::get_model_index(int i)
{
	return model_ind[i];
}

int Order::get_qty(int i)
{
	return qty[i];
}

double Order::get_price()
{
	return price;
}