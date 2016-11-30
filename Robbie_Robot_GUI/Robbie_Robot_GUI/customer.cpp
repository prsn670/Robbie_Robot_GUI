#include "customer.h"
#include "FL/Fl_Button.h"
#include "Fl/Fl_Input.h"
#include "Fl/Fl_Window.h"
#include "store.h"

string Customer::get_first()
{
	return first;
}

string Customer::get_last()
{
	return last;
}

string Customer::get_add()
{
	return address;
}

string Customer::get_city()
{
	return city;
}

string Customer::get_state()
{
	return state;
}

string Customer::get_zip()
{
	return zip;
}

string Customer::get_country()
{
	return country;
}
string Customer::get_number()
{
	return number;
}

int Customer::get_cust_num()
{
	return cust_num;
}
void Customer::set_cust_num(int num)
{
	cust_num = num;
}


Fl_Input* f_name;
Fl_Input* l_name;
Fl_Input* add_in;
Fl_Input* city_in;
Fl_Input* state_in;
Fl_Input* zip_in;
Fl_Input* country_in;
Fl_Input* num_in;
extern Store store;
void custCB(Fl_Widget* w, void* p)
{
	int but_w = 100, but_h = 35, in_w = 150, in_h = 30, x = 100, y = 0;
	
	Fl_Window* win = new Fl_Window(300, 300, "Create Customer");
	f_name = new Fl_Input(x, y, in_w, in_h, "First Name");
	l_name = new Fl_Input(x, y += in_h, in_w, in_h, "Last Name");
	add_in = new Fl_Input(x, y += in_h, in_w, in_h, "Address");
	city_in = new Fl_Input(x, y += in_h, in_w, in_h, "City");
	state_in = new Fl_Input(x, y += in_h, in_w, in_h, "State/Province");
	zip_in = new Fl_Input(x, y += in_h, in_w, in_h, "Zip Code");
	country_in = new Fl_Input(x, y += in_h, in_w, in_h, "Country");
	num_in = new Fl_Input(x, y += in_h, in_w, in_h, "Phone Number");
	Fl_Button* create = new Fl_Button(x + 25, y += in_h, but_w, but_h, "Create\nCustomer");
	create->callback(create_custCB);
	win->end();
	win->show();

}
void create_custCB(Fl_Widget* w, void* p)
{
	store.store_cust(f_name->value(), l_name->value(), add_in->value(), city_in->value(), state_in->value(), zip_in->value(), country_in->value(), num_in->value());
	store.cust.back()->set_cust_num(store.cust.size());
	cout << "Creating Customer" << endl;
	cout << "Name: " << store.cust.back()->get_first() << " " << store.cust.back()->get_last() << endl;
	cout << "Address: " << store.cust.back()->get_add() << endl;
	cout << "City: " << store.cust.back()->get_city() << endl;
	cout << "State/Province: " << store.cust.back()->get_state() << endl;
	cout << "Zip Code: " << store.cust.back()->get_zip() << endl;
	cout << "Country: " << store.cust.back()->get_country() << endl;
	cout << "Phone Number: " << store.cust.back()->get_number() << endl;
	cout << "Customer Number: " << store.cust.back()->get_cust_num() << endl << endl;

}
