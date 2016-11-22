#include "stdafx.h"
#include "list_robot.h"
#include "store.h"
#include "iostream"
#include "iomanip"
#include "string"
using namespace std;
void list_arm(class Store& store)
{
	for (int i = 0; i < store.left_arm.size(); i++)
		{
			cout << i + 1 << ". " << store.left_arm[i]->get_name() << endl << endl;
		}
}

/*void list_batt(class Store& store)
{
	for (int i = 0; i < store.batt.size(); i++)
	{
		cout << i + 1 << ". " << store.batt[i]->get_name() << endl << endl;
	}
}

void list_head(class Store& store)
{
	for (int i = 0; i < store.head.size(); i++)
	{
		cout << i + 1 << ". " << store.head[i]->get_name() << endl << endl;
	}
}

void list_loco(class Store& store)
{
	for (int i = 0; i < store.loco.size(); i++)
	{
		cout << i + 1 << ". " << store.loco[i]->get_name() << endl << endl;
	}
}

void list_tor(class Store& store)
{
	for (int i = 0; i < store.tor.size(); i++)
	{
		cout << i + 1 << ". " << store.tor[i]->get_name() << endl << endl;
	}
}

void list_models(class Store& store)//lists models with associated parts
{
	string input;
	if (store.rob.empty())
	{
		cout << "No models to display." << endl << endl;
		return;
	}
	
	cout << "Model Name     " << "Price     " << endl << endl;

	for (int i = 0; i < store.rob.size(); i++)
	{
		cout << i + 1 << ". " << setw(12) << left << store.rob[i]->get_name() << '$' << setw(10) << left << (store.rob[i]->get_cost()) * 1.15 << endl << endl;
	}
	
	
	
	
	cout << "Make a selection to view an order in more detail. Enter 'q' to return to main menu: ";
	cin.ignore(100, '\n');
	getline(cin, input);
	if (input.compare("q") == 0 || input.compare("Q") == 0)
	{
		return;
	}

	else
	{
		try
		{
			stoi(input);
		}

		catch (invalid_argument e)
		{
			cout << "Invalid argument entered. Returning to main menu" << endl << endl;
			return;
		}

		if (stoi(input) > store.rob.size() || stoi(input) < 0)
		{
			cout << "This robot does not exist. Returning to main menu" << endl << endl;
		}

		else
		{
			cout << "Model Name     " << "Arm     " << "Battery     " << "Head      " << "Locomotor     " << "Torso     " << "Price     " << endl << endl;
		
			cout << setw(15) << left << store.rob[stoi(input) - 1]->get_name() << setw(8) << left << store.left_arm[store.rob[stoi(input) - 1]->get_index(1)]->get_name()
				<< setw(12) << left << store.batt[store.rob[stoi(input) - 1]->get_index(2)]->get_name() << setw(10) << left << store.head[store.rob[stoi(input) - 1]->get_index(3)]->get_name()
				<< setw(14) << left << store.loco[store.rob[stoi(input) - 1]->get_index(4)]->get_name() << setw(10) << left << store.tor[store.rob[stoi(input) - 1]->get_index(5)]->get_name()
				<< '$' << setw(10) << left << (store.rob[stoi(input) - 1]->get_cost()) * 1.15 << endl << endl;
		}
	}
	
	
	
		
	
}

void list_last_order(class Store& store)
{
	
	cout << "Here is your new order!" << endl << endl;
	cout << "Order Number: " << store.ord.back()->get_ord_num() << endl;
	cout << "Customer: " << store.ord.back()->get_name() << endl;
	cout << "Sales Associate: " << store.ord.back()->get_assoc() << endl << endl << endl;
	cout << "Qty    " << "Model Name     " << "Price     " << endl;
	for (int i = 0; i < store.ord.back()->get_size(); i++)
	{
		cout << setw(7) << left << store.ord.back()->get_qty(i) << left << setw(15) << store.rob[store.ord.back()->get_model_index(i)]->get_name();
		cout << setw(20) << left << fixed << setprecision(2) << (store.rob[store.ord.back()->get_model_index(i)]->get_cost())* 1.15 * store.ord.back()->get_qty(i) << endl << endl;
	}

	cout << "Total" << right << setw(24) << fixed << setprecision(2) << store.ord.back()->get_price() << endl << endl;
}
void list_all_order(class Store& store)
{
	string input;
	
	if (store.ord.empty())
	{
		cout << "There are no orders to display." << endl << endl;
		return;
	}

	cout << "Order Number     " << "Customer Name     " << "Total Price" << endl;
	for (int i = 0; i < store.ord.size(); i++)
	{
		cout << left << setw(17) << store.ord[i]->get_ord_num() << setw(18) << left << setw(18) << store.ord[i]->get_name() << "$" << fixed << setprecision(2) << store.ord[i]->get_price();
		cout << endl << endl;
	}

	cout << "Make a selection to view an order in more detail. Enter 'q' to return to main menu: ";
	cin.ignore(100, '\n');
	getline(cin, input);
	if (input.compare("q") == 0 || input.compare("Q") == 0)
	{
		return;
	}

	else 
	{
		try 
		{
			stoi(input);
		}

		catch (invalid_argument e)
		{
			cout << "Invalid argument entered. Returning to main menu" << endl << endl;
			return;
		}

		if (stoi(input) > store.ord.size() || stoi(input) < 0)
		{
			cout << "This order does not exist. Returning to main menu" << endl << endl;
		}

		else
		{
			cout << "Order Number: " << store.ord[stoi(input)-1]->get_ord_num() << endl;
			cout << "Customer: " << store.ord[stoi(input)-1]->get_name() << endl;
			cout << "Sales Associate: " << store.ord[stoi(input)-1]->get_assoc() << endl << endl << endl;
			cout << "Qty    " << "Model Name     " << "Price     " << endl;
			for (int i = 0; i < store.ord[stoi(input)-1]->get_size(); i++)
			{
				cout << setw(7) << left << store.ord[stoi(input)-1]->get_qty(i) << left << setw(15) << store.rob[store.ord[stoi(input)-1]->get_model_index(i)]->get_name();
				cout << setw(20) << left << fixed << setprecision(2) << (store.rob[store.ord[stoi(input)-1]->get_model_index(i)]->get_cost())* 1.15 * store.ord[stoi(input)-1]->get_qty(i) << endl << endl;
			}

			cout << "Total" << right << setw(24) << fixed << setprecision(2) << store.ord[stoi(input)-1]->get_price() << endl << endl;
		}
	}
}*/