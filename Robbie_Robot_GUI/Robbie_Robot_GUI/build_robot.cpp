#include "stdafx.h"
#include "build_robot.h"
#include "iostream"
#include "store.h"
#include "vector"
#include "list_robot.h"

using namespace std;

void build_base(int selection, class Store& store)//build the common data for each component
{
	
	string str, desc;
	double lbs, money;
	int part;
	bool valid = false;
	//static int i = 0;
	//string enter_data[] = { "Please enter data for torso component\n", "Please enter data for head component\n", "Please enter data for arm component\n", "Please enter data for locomotor component\n", "Please enter data for battery component\n" };
	
	
	
	//cout << enter_data[i];
	cout << "Please enter the name of the part: ";
	cin.ignore(100, '\n');
	getline(cin, str);
	while (!valid)
	{
		cout << "Please enter the weight of the item: ";
		cin >> lbs;
		if (!cin)
		{
			cout << "Invalid input. Must be a positive number." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (lbs < 0)
		{
			cout << "Invalid input. Must be a positive number." << endl << endl;
		}
		else
		{
			valid = true;
		}

	}
	valid = false;
	while (!valid)
	{
		cout << "Please enter the cost of the item: ";
		cin >> money;
		if (!cin)
		{
			cout << "Invalid input. Must be a positive number." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (money < 0)
		{
			cout << "Invalid input. Must be a positive number." << endl << endl;
		}
		else
		{
			valid = true;
		}
	}
	valid = false;
	while (!valid)
	{
		cout << "Please enter the part number of the item: ";
		cin >> part;
		if (!cin)
		{
			cout << "Invalid input. Must be a positive number." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (part < 1)
		{
			cout << "Invalid input. Must be a positive number." << endl << endl;
		}
		else
		{
			valid = true;
		}
	}
	cin.ignore(100, '\n');
	cout << "Please enter a brief description of the item: ";
	getline(cin, desc);

	if (selection == 1)
	{
		build_arm(str, lbs, money, part, desc, store);
		
	}

	else if (selection == 2)
	{
		build_battery(str, lbs, money, part, desc, store);
	}

	else if (selection == 3)
	{
		build_head(str, lbs, money, part, desc, store);
		
	}

	else if (selection == 4)
	{
		build_locomotor(str, lbs, money, part, desc, store);
	}

	else if (selection == 5)
	{
		build_torso(str, lbs, money, part, desc, store);
	}
}

void build_model(class Store& store)//collects data for model specific data
{
	if (store.arm.empty() || store.batt.empty() || store.head.empty() || store.loco.empty() || store.tor.empty())
	{
		if (store.arm.empty())
		{
			cout << "No arms have been created. Cannot create a model." << endl;
		}

		if (store.batt.empty())
		{
			cout << "No batteries have been created. Cannot create a model." << endl;
		}

		if (store.head.empty())
		{
			cout << "No heads have been created. Cannot create a model." << endl;
		}

		if (store.loco.empty())
		{
			cout << "No locomotors have been created. Cannot create a model." << endl;
		}

		if (store.tor.empty())
		{
			cout << "No torsos have been created. Cannot create a model." << endl;
		}

		cout << "Exiting to main menu" << endl << endl;
		return;
	}
	
	int part, index;
	double lbs, money;
	string desc, name;
	bool valid = false;
	while (!valid)
	{
		cout << "Please enter the model number: ";
		cin >> part;
		if (!cin)
		{
			cout << "Invalid argument. Must be a positive integer." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			part = 1;
		}

		else if (part < 1)
		{
			cout << "Invalid argument. Must be a positive integer." << endl;
		}

		else
		{
			valid = true;
		}
	}
	valid = false;
	cout << "Please enter a brief description of the robot model: ";
	cin.ignore(100, '\n');
	getline(cin, desc);
	cout << "Please enter a name for the robot model: ";
	getline(cin, name);
	store.store_model(name, 0, 0, part, desc);
	list_tor(store);
	while (!valid)
	{
		cout << "Please select a torso for the robot model: ";
		cin >> index;
		if (!cin)
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			list_tor(store);
		}

		else if (index < 1 || index > store.tor.size())
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			list_tor(store);
		}
		else
		{
			store.rob.back()->set_index(5, index);
			valid = true;
		}
	}

	valid = false;
	list_loco(store);
	while (!valid)
	{
		
		cout << "Please select a locomotor for your model: ";
		cin >> index;
		if (!cin)
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			list_loco(store);
		}

		else if (index < 1 || index > store.loco.size())
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			list_tor(store);
		}
		else
		{
			store.rob.back()->set_index(4, index);
			valid = true;
		}
	}
	valid = false;
	list_head(store);
	while (!valid)
	{
		cout << "Please select a head for your model: ";
		cin >> index;
		if (!cin)
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			list_head(store);
		}

		else if (index < 1 || index > store.head.size())
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			list_head(store);
		}
		else
		{
			store.rob.back()->set_index(3, index);
			valid = true;
		}
	}
	valid = false;
	list_batt(store);
	while (!valid)
	{
		cout << "Please select a battery for your model: ";
		cin >> index;
		if (!cin)
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			list_batt(store);
		}

		else if (index < 1 || index > store.batt.size())
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			list_batt(store);
		}
		else
		{
			store.rob.back()->set_index(2, index);
			valid = true;
		}
	}
	valid = false;
	list_arm(store);
	while (!valid)
	{
		cout << "Please select an arm for your model: ";
		cin >> index;
		if (!cin)
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
			list_arm(store);
		}

		else if (index < 1 || index > store.arm.size())
		{
			cout << "Invalid input. Please select from the menu." << endl << endl;
			list_tor(store);
		}
		else
		{
			store.rob.back()->set_index(1, index); //this line and above ask for parts that make up new model
			valid = true;
		}
	}
	lbs = (store.arm[store.rob.back()->get_index(1)]->get_weight()) * 2 + (store.batt[store.rob.back()->get_index(2)]->get_weight() * (store.tor[store.rob.back()->get_index(5)]->get_battery())) + store.head[store.rob.back()->get_index(3)]->get_weight() + store.loco[store.rob.back()->get_index(4)]->get_weight() + store.tor[store.rob.back()->get_index(5)]->get_weight();
	money = store.arm[store.rob.back()->get_index(1)]->get_cost() * 2 + ((store.batt[store.rob.back()->get_index(2)]->get_cost())*(store.tor[store.rob.back()->get_index(5)]->get_battery())) + store.head[store.rob.back()->get_index(3)]->get_cost() + store.loco[store.rob.back()->get_index(4)]->get_cost() + store.tor[store.rob.back()->get_index(5)]->get_cost();
	store.rob.back()->set_weight(lbs);
	store.rob.back()->set_cost(money);

}

void build_arm(string str, double lbs, double money, int part, string desc, class Store& store)//collect data specific to arm
{
	
	int pow;
	bool valid = false;
	while (!valid)
	{
		cout << "Please enter the power consumption of the arm: ";
		cin >> pow;
		if (!cin)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if(pow < 1)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
		}

		else
		{
			valid = true;
		}
	}
	store.store_arm(str, lbs, money, part, desc, pow);
}

void build_battery(string str, double lbs, double money, int part, string desc, class Store& store) //collect data specific to battery
{
	
	int nrg;
	bool valid = false;
	while (!valid)
	{

		cout << "Please enter the amount of energy stored in the battery: ";
		cin >> nrg;
		if (!cin)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (nrg < 1)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
		}

		else
		{
			valid = true;
		}
	}
	store.store_batt(str, lbs, money, part, desc, nrg);
	
}

void build_head(string str, double lbs, double money, int part, string desc, class Store& store)
{
	store.store_head(str, lbs, money, part, desc);
}

void build_locomotor(string str, double lbs, double money, int part, string desc, class Store& store) //collect data specific to locomotor
{
	
	int pow, speed;
	bool valid = false;
	while (!valid)
	{
		cout << "Please enter the power consumption of the locomotor: ";
		cin >> pow;
		if (!cin)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (pow < 1)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
		}

		else
		{
			valid = true;
		}
	}
	valid = false;
	while(!valid)
	{ 
		cout << "Please enter the max speed of the locomotor: ";
		cin >> speed;
		if (!cin)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (speed < 1)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
		}

		else
		{
			valid = true;
		}
	}
	store.store_locomotor(str, lbs, money, part, desc, speed, pow);
}

void build_torso(string str, double lbs, double money, int part, string desc, class Store& store) //collect data specific to torso
{
	
	int amt;
	bool valid = false;
	while (!valid)
	{
		cout << "Please enter the number of batteries needed for this torso: ";
		cin >> amt;
		if (!cin)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}

		else if (amt < 1)
		{
			cout << "Invalid input. Please enter a positive integer." << endl << endl;
		}

		else
		{
			valid = true;
		}
	
	}

	store.store_torso(str, lbs, money, part, desc, amt);
}