#include "iostream"
#include "rob_part_input.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "Fl/Fl_Input.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Input.H"
#include "Fl/Fl_Button.H"
#include "FL/Fl_Float_Input.H"
#include "FL/Fl_Int_Input.H"
#include "FL/Fl_Multiline_Input.H"
#include "robot_model.h"
#include "store.h"
#include "FL/Fl_File_Chooser.h"
#include "FL/Fl_Shared_Image.h"
#include "FL/Fl_Image.h"
#include "FL/Fl_PNG_Image.h"
#include "FL/Fl_JPEG_Image.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H> 
#include "FL/Fl_Help_View.h"
#include "sstream"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;
Fl_Input *name;
Fl_Float_Input *weight;
Fl_Float_Input *cost;
Fl_Int_Input *part_num;
Fl_Multiline_Input *descript;
Fl_Int_Input *arm_power;
Fl_Int_Input *batt_nrg;
Fl_Int_Input *loco_power;
Fl_Int_Input *loco_speed;
Fl_Int_Input *torso_batt_amt;
extern Store store;
string file = "";
int left_arm_ind = -1, right_arm_ind = -1, batt_ind = -1, head_ind = -1, loco_ind = -1, torso_ind = -1;


void part_inputCB(Fl_Widget *w, void *p)
{
	
	int x = 425, y = 50, width_input = 50, height_input = 30;
	int but_w = 100, but_h = 35;//button width and height
	int x1 = 50, x2 = 100;
	Fl_Window *win = new Fl_Window(900, 500, "Create Robot Parts");
	//Fl_Box *box = new Fl_Box(0, 0, 1900, 300);
	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Basic Information");
	basic->box(FL_UP_BOX);
	name = new Fl_Input(x, y, 150, 30, "Part Name");
	weight = new Fl_Float_Input(x, y+=30, width_input, height_input, "Weight");
	cost = new Fl_Float_Input(x, y += 30, width_input, height_input, "Cost");
	part_num = new Fl_Int_Input(x, y += 30, width_input, height_input, "Part Number");
	descript = new Fl_Multiline_Input(x, y += 30, width_input + 100, height_input + 50, "Description");
	arm_power = new Fl_Int_Input(x-290, y+100, width_input, height_input, "Arm Power\nConsumption");
	batt_nrg = new Fl_Int_Input(x - 125, y + 100, width_input, height_input, "Energy\nStorage");
	loco_power = new Fl_Int_Input(x + 30, y + 140, width_input, height_input, "Locomotor\nPower\nConsumption");
	loco_speed = new Fl_Int_Input(x + 30, y + 100, width_input, height_input, "Locomotor\nSpeed");
	torso_batt_amt = new Fl_Int_Input(x + 190, y + 100, width_input, height_input, "Battery\nCompartments");
	Fl_Button* left_arm_button = new Fl_Button(x - 410, y + 140, but_w, but_h, "Create\nLeft Arm");
	Fl_Button* right_arm_button = new Fl_Button(x - 300, y + 140, but_w, but_h, "Create\nRight Arm");
	Fl_Button* batt_button = new Fl_Button(x - 175, y + 140, but_w, but_h, "Create\nBattery");
	Fl_Button* loco_button = new Fl_Button(x - 20, y + 180, but_w, but_h, "Create\nLocomotor");
	Fl_Button* tor_button = new Fl_Button(x + 150, y + 140, but_w, but_h, "Create\nTorso");
	Fl_Button* head_button = new Fl_Button(x + 290, y + 140, but_w, but_h, "Create\nHead");
	Fl_Button* choose_pic = new Fl_Button(x + 290, y, but_w, but_h, "Choose\nPicture");
	descript->wrap(1);//enables wrapping of text in description input
	ShowCursor(1);
	left_arm_button->callback(submit_left_armCB);
	right_arm_button->callback(submit_right_armCB);
	batt_button->callback(submit_battCB);
	loco_button->callback(submit_locoCB);
	tor_button->callback(submit_torsoCB);
	head_button->callback(submit_headCB);
	choose_pic->callback(choose_picCB);

	//win->resizable(*win);
	win->end();
	win->show();
	
	

}

void model_inputCB(Fl_Widget *w, void *p)
{

	int x = 425, y = 50, width_input = 50, height_input = 30;
	int but_w = 100, but_h = 35;//button width and height
	int x1 = 50, x2 = 100;
	Fl_Window *win = new Fl_Window(900, 500, "Create Robot Model");
	//Fl_Box *box = new Fl_Box(0, 0, 1900, 300);
	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Basic Information");
	basic->box(FL_UP_BOX);
	name = new Fl_Input(x, y, 150, 30, "Model Name");
	//weight = new Fl_Float_Input(x, y += 30, width_input, height_input, "Weight");
	//cost = new Fl_Float_Input(x, y += 30, width_input, height_input, "Cost");
	part_num = new Fl_Int_Input(x, y += 30, width_input, height_input, "Part Number");
	descript = new Fl_Multiline_Input(x, y += 30, width_input + 100, height_input + 50, "Description");
	//arm_power = new Fl_Int_Input(x - 290, y + 100, width_input, height_input, "Arm Power\nConsumption");
	//batt_nrg = new Fl_Int_Input(x - 125, y + 100, width_input, height_input, "Energy\nStorage");
	//loco_power = new Fl_Int_Input(x + 30, y + 140, width_input, height_input, "Locomotor\nPower\nConsumption");
	//loco_speed = new Fl_Int_Input(x + 30, y + 100, width_input, height_input, "Locomotor\nSpeed");
	//torso_batt_amt = new Fl_Int_Input(x + 190, y + 100, width_input, height_input, "Battery\nCompartments");
	Fl_Button* left_arm_button = new Fl_Button(x - 420, y + 140, but_w, but_h, "Add\nLeft Arm");
	Fl_Button* right_arm_button = new Fl_Button(x - 300, y + 140, but_w, but_h, "Add\nRight Arm");
	Fl_Button* batt_button = new Fl_Button(x - 175, y + 140, but_w, but_h, "Add\nBattery");
	Fl_Button* loco_button = new Fl_Button(x - 20, y + 140, but_w, but_h, "Add\nLocomotor");
	Fl_Button* tor_button = new Fl_Button(x + 150, y + 140, but_w, but_h, "Add\nTorso");
	Fl_Button* head_button = new Fl_Button(x + 290, y + 140, but_w, but_h, "Add\nHead");
	Fl_Button* choose_pic = new Fl_Button(x + 290, y, but_w, but_h, "Choose\nPicture");
	Fl_Button* mod_button = new Fl_Button(x - 20, y + 200, but_w, but_h, "Create\nModel");
	descript->wrap(1);//enables wrapping of text in description input
	ShowCursor(1);
	left_arm_button->callback(select_left_armCB);
	right_arm_button->callback(select_right_armCB);
	batt_button->callback(select_battCB);
	loco_button->callback(select_locoCB);
	tor_button->callback(select_torsoCB);
	head_button->callback(select_headCB);
	choose_pic->callback(choose_picCB);
	mod_button->callback(create_modelCB);

	//win->resizable(*win);
	win->end();
	win->show();

}

void submit_left_armCB(Fl_Widget* w, void* p)
{
	//Fl_Button* butt = (Fl_Button*)w;
	//Fl_Input* name = (Fl_Input*)nme;
	//cout << "The number entered was: " << cost->value() << endl;
	store.left_store_arm(name->value(), stod(weight->value()), stod(cost->value()), stoi(part_num->value()), descript->value(), file, stoi(arm_power->value()));
	
	file = ""; //resets filename to empty string

	cout << "Creating Left Arm:" << endl;
	cout << "Name: "<< store.left_arm.back()->get_name() << endl;
	cout << "Weight: " << store.left_arm.back()->get_weight() << endl;
	cout << "Cost: " << store.left_arm.back()->get_cost() << endl;
	cout << "Part Number :" << store.left_arm.back()->get_part_num() << endl;
	cout << "Picture file: " << store.left_arm.back()->get_filename() << endl;
	cout << "Power Consumption: " << store.left_arm.back()->get_power() << endl << endl; //Test code

}
void submit_right_armCB(Fl_Widget* w, void* p)
{
	//Fl_Button* butt = (Fl_Button*)w;
	//Fl_Input* name = (Fl_Input*)nme;
	//cout << "The number entered was: " << cost->value() << endl;
	store.right_store_arm(name->value(), stod(weight->value()), stod(cost->value()), stoi(part_num->value()), descript->value(), file, stoi(arm_power->value()));

	file = ""; //resets filename to empty string

	cout << "Creating Right Arm:" << endl;
	cout << "Name: " << store.right_arm.back()->get_name() << endl;
	cout << "Weight: " << store.right_arm.back()->get_weight() << endl;
	cout << "Cost: " << store.right_arm.back()->get_cost() << endl;
	cout << "Part Number :" << store.right_arm.back()->get_part_num() << endl;
	cout << "Picture file: " << store.right_arm.back()->get_filename() << endl;
	cout << "Power Consumption: " << store.right_arm.back()->get_power() << endl << endl; //Test code

}
void submit_battCB(Fl_Widget* w, void* p)
{
	//Fl_Button* butt = (Fl_Button*)w;
	//Fl_Input* name = (Fl_Input*)nme;
	//cout << "The number entered was: " << cost->value() << endl;
	store.store_batt(name->value(), stod(weight->value()), stod(cost->value()), stoi(part_num->value()), descript->value(), file, stoi(torso_batt_amt->value()));
	file = ""; //resets filename to empty string
	cout << "Creating Battery:" << endl;
	cout << "Name: " << store.batt.back()->get_name() << endl;
	cout << "Weight: " << store.batt.back()->get_weight() << endl;
	cout << "Cost: " << store.batt.back()->get_cost() << endl;
	cout << "Part Number :" << store.batt.back()->get_part_num() << endl;
	cout << "Picture file: " << store.batt.back()->get_filename() << endl;
	cout << "Power Storage: " << store.batt.back()->get_energy() << endl << endl; //Test code
	//cout << store.arm[0]->get_cost() << endl;

}

void submit_headCB(Fl_Widget* w, void* p)
{
	//Fl_Button* butt = (Fl_Button*)w;
	//Fl_Input* name = (Fl_Input*)nme;
	//cout << "The number entered was: " << cost->value() << endl;
	store.store_head(name->value(), stod(weight->value()), stod(cost->value()), stoi(part_num->value()), descript->value(), file);
	file = ""; //resets filename to empty string

	cout << "Creating Head:" << endl;
	cout << "Name: " << store.head.back()->get_name() << endl;
	cout << "Weight: " << store.head.back()->get_weight() << endl;
	cout << "Cost: " << store.head.back()->get_cost() << endl;
	cout << "Part Number :" << store.head.back()->get_part_num() << endl;
	cout << "Picture file: " << store.head.back()->get_filename() << endl << endl;
	//cout << store.arm[0]->get_cost() << endl;

}


void submit_locoCB(Fl_Widget* w, void* p)
{
	//Fl_Button* butt = (Fl_Button*)w;
	//Fl_Input* name = (Fl_Input*)nme;
	//cout << "The number entered was: " << cost->value() << endl;
	store.store_locomotor(name->value(), stod(weight->value()), stod(cost->value()), stoi(part_num->value()), descript->value(), file, stoi(loco_speed->value()), stoi(loco_power->value()));
	file = ""; //resets filename to empty string
	cout << "Creating Locomotor:" << endl;
	cout << "Name: " << store.loco.back()->get_name() << endl;
	cout << "Weight: " << store.loco.back()->get_weight() << endl;
	cout << "Cost: " << store.loco.back()->get_cost() << endl;
	cout << "Part Number :" << store.loco.back()->get_part_num() << endl;
	cout << "Picture file: " << store.loco.back()->get_filename() << endl;
	cout << "Max Speed: " << store.loco.back()->get_max_speed() << endl; 
	cout << "Power Consumption: " << store.loco.back()->get_power() << endl << endl; //Test code
	//cout << store.arm[0]->get_cost() << endl;

}

void submit_torsoCB(Fl_Widget* w, void* p)
{
	//Fl_Button* butt = (Fl_Button*)w;
	//Fl_Input* name = (Fl_Input*)nme;
	//cout << "The number entered was: " << cost->value() << endl;
	store.store_torso(name->value(), stod(weight->value()), stod(cost->value()), stoi(part_num->value()), descript->value(), file, stoi(torso_batt_amt->value()));
	file = ""; //resets filename to empty string
	cout << "Creating Torso:" << endl;
	cout << "Name: " << store.tor.back()->get_name() << endl;
	cout << "Weight: " << store.tor.back()->get_weight() << endl;
	cout << "Cost: " << store.tor.back()->get_cost() << endl;
	cout << "Part Number :" << store.tor.back()->get_part_num() << endl;
	cout << "Picture file: " << store.tor.back()->get_filename() << endl;
	cout << "Battery Storage: " << store.tor.back()->get_battery() << endl << endl; //Test code
	//cout << store.arm[0]->get_cost() << endl;

}

void create_modelCB(Fl_Widget* w, void* p)
{
	double wt, cost;
	wt = cost = 0;
	
	
	store.store_model(name->value(), 0, 0, stoi(part_num->value()), descript->value(), file);
	
	
	store.rob.back()->set_index(1, left_arm_ind);
	store.rob.back()->set_index(2, right_arm_ind);
	store.rob.back()->set_index(3, batt_ind);
	store.rob.back()->set_index(4, head_ind);
	store.rob.back()->set_index(5, loco_ind);
	store.rob.back()->set_index(6, torso_ind);
	if (left_arm_ind != -1)
	{
		cost += store.left_arm[left_arm_ind]->get_cost();
		wt += store.left_arm[left_arm_ind]->get_weight();
		cout << "Weight: " << wt << endl;
	}

	if (right_arm_ind != -1)
	{
		cost += store.right_arm[right_arm_ind]->get_cost();
		wt += store.right_arm[right_arm_ind]->get_weight();
		cout << "Weight: " << wt << endl;
	}

	if (batt_ind != -1)
	{
		cost += store.batt[batt_ind]->get_cost() * store.tor[torso_ind]->get_battery();
		wt += store.batt[batt_ind]->get_weight() * store.tor[torso_ind]->get_battery();
		cout << "Weight: " << wt << endl;
	}

	if (head_ind != -1)
	{
		cost += store.head[head_ind]->get_cost();
		wt += store.head[head_ind]->get_weight();
		cout << "Weight: " << wt << endl;
	}

	if (loco_ind != -1)
	{
		cost += store.loco[loco_ind]->get_cost();
		wt += store.loco[loco_ind]->get_weight();
		cout << "Weight: " << wt << endl;
	}

	if (torso_ind != -1)
	{
		cost += store.tor[torso_ind]->get_cost();
		wt += store.tor[torso_ind]->get_weight();
		cout << "Weight: " << wt << endl;
	}

	store.rob.back()->set_cost(cost);
	store.rob.back()->set_weight(wt);
	left_arm_ind = right_arm_ind = batt_ind = head_ind = loco_ind = torso_ind = -1; //reset all back to -1

	cout << "Creating Model:" << endl;
	cout << "Name: " << store.rob.back()->get_name() << endl;
	cout << "Weight: " << store.rob.back()->get_weight() << endl;
	cout << "Cost: " << store.rob.back()->get_cost() << endl;
	cout << "Part Number :" << store.rob.back()->get_part_num() << endl;
	cout << "Picture file: " << store.rob.back()->get_filename() << endl << endl;
	file = "";//reset file strin to empty
	
}

void choose_picCB(Fl_Widget* w, void* p)
{
	Fl_File_Chooser chooser(".", "*", Fl_File_Chooser::MULTI, "Title");
	chooser.show();
	while (chooser.shown())
	{
		Fl::wait();
	}
	if (chooser.value() == NULL)
	{
		file = "";
		cout << file << endl;
		return;
	}
	file = chooser.value();
	cout << file << endl << endl;
}

void select_left_armCB(Fl_Widget* w, void* p)
{
	/*Fl_Window* win = new Fl_Window(900, 500, "Radio Button");
	Fl_Help_View* v = new Fl_Help_View(0, 0, 900, 500, "<HTML><Head>Something</Head></HTML>");
	v->load("test.html");
	win->end();
	win->show();*/
	
	int i, x = 32, y = 80;
	Fl_Window* win = new Fl_Window(900, 500, "Select Arm");
	Fl_PNG_Image* img;
	Fl_Button* o;
	char* label;
	char* pic;
	int len, len2;
		
	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Please Select an Arm");
	basic->labelfont(FL_BOLD);
	basic->labelsize(36);
	
	//Fl_Group* o = new Fl_Group(10, 10, 347, 73);
	//o->box(FL_DOWN_BOX);
	for (i = 0; i < store.left_arm.size(); i++)
	{

		//cout << c << endl;
		label = new char(store.left_arm[i]->get_name().length() + 1);
		len = (store.left_arm[i]->get_name().length() + 1);
		strcpy_s(label, len, store.left_arm[i]->get_name().c_str());
		o = new Fl_Button(x, y, 64, 15, label);
		//cout << pic;
		y += 25;
		if (i != 0 && i % 5 == 0)
		{
			x += 100;
			y = 80;
		}
		
		o->callback(set_left_arm_indCB);
		//cout << store.left_arm[i]->get_filename().length() << endl;
	}

	

	/*x = 32, y = 20;
	
	for (i = 0; i < store.left_arm.size(); i++)
	{
		fl_register_images();
		pic = new char(store.left_arm[i]->get_filename().length() + 1);
		len2 = (store.left_arm[i]->get_filename().length() + 1);
		strcpy_s(pic, len2, store.left_arm[i]->get_filename().c_str());
		Fl_Box* box = new Fl_Box(x, y, 50, 50);
		img = new Fl_PNG_Image(pic);
		box->image(img->copy(50, 50));
		x += 20;
		if (i != 0 && i % 5 == 0)
		{
			x = 32;
			y += 25;
		}
	}*/
	
	
	win->end();
	win->show();
	
	
}

void select_right_armCB(Fl_Widget* w, void* p)
{
	/*Fl_Window* win = new Fl_Window(900, 500, "Radio Button");
	Fl_Help_View* v = new Fl_Help_View(0, 0, 900, 500, "<HTML><Head>Something</Head></HTML>");
	v->load("test.html");
	win->end();
	win->show();*/

	int i, x = 32, y = 80;
	Fl_Window* win = new Fl_Window(900, 500, "Select Arm");
	Fl_PNG_Image* img;
	Fl_Button* o;
	char* label;
	char* pic;
	int len, len2;

	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Please Select an Arm");
	basic->labelfont(FL_BOLD);
	basic->labelsize(36);

	//Fl_Group* o = new Fl_Group(10, 10, 347, 73);
	//o->box(FL_DOWN_BOX);
	for (i = 0; i < store.right_arm.size(); i++)
	{

		//cout << c << endl;
		label = new char(store.right_arm[i]->get_name().length() + 1);
		len = (store.right_arm[i]->get_name().length() + 1);
		strcpy_s(label, len, store.right_arm[i]->get_name().c_str());
		o = new Fl_Button(x, y, 64, 15, label);
		//cout << pic;
		y += 25;
		if (i != 0 && i % 5 == 0)
		{
			x += 100;
			y = 80;
		}

		o->callback(set_right_arm_indCB);
		//cout << store.left_arm[i]->get_filename().length() << endl;
	}



	/*x = 32, y = 20;

	for (i = 0; i < store.left_arm.size(); i++)
	{
	fl_register_images();
	pic = new char(store.left_arm[i]->get_filename().length() + 1);
	len2 = (store.left_arm[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.left_arm[i]->get_filename().c_str());
	Fl_Box* box = new Fl_Box(x, y, 50, 50);
	img = new Fl_PNG_Image(pic);
	box->image(img->copy(50, 50));
	x += 20;
	if (i != 0 && i % 5 == 0)
	{
	x = 32;
	y += 25;
	}
	}*/


	win->end();
	win->show();


}

void select_battCB(Fl_Widget* w, void* p)
{
	/*Fl_Window* win = new Fl_Window(900, 500, "Radio Button");
	Fl_Help_View* v = new Fl_Help_View(0, 0, 900, 500, "<HTML><Head>Something</Head></HTML>");
	v->load("test.html");
	win->end();
	win->show();*/

	int i, x = 32, y = 80;
	Fl_Window* win = new Fl_Window(900, 500, "Select Battery");
	Fl_PNG_Image* img;
	Fl_Button* o;
	char* label;
	char* pic;
	int len, len2;

	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Please Select a Battery");
	basic->labelfont(FL_BOLD);
	basic->labelsize(36);

	//Fl_Group* o = new Fl_Group(10, 10, 347, 73);
	//o->box(FL_DOWN_BOX);
	for (i = 0; i < store.batt.size(); i++)
	{

		//cout << c << endl;
		label = new char(store.batt[i]->get_name().length() + 1);
		len = (store.batt[i]->get_name().length() + 1);
		strcpy_s(label, len, store.batt[i]->get_name().c_str());
		o = new Fl_Button(x, y, 64, 15, label);
		//cout << pic;
		y += 25;
		if (i != 0 && i % 5 == 0)
		{
			x += 100;
			y = 80;
		}

		o->callback(set_batt_indCB);
		//cout << store.left_arm[i]->get_filename().length() << endl;
	}



	/*x = 32, y = 20;

	for (i = 0; i < store.left_arm.size(); i++)
	{
	fl_register_images();
	pic = new char(store.left_arm[i]->get_filename().length() + 1);
	len2 = (store.left_arm[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.left_arm[i]->get_filename().c_str());
	Fl_Box* box = new Fl_Box(x, y, 50, 50);
	img = new Fl_PNG_Image(pic);
	box->image(img->copy(50, 50));
	x += 20;
	if (i != 0 && i % 5 == 0)
	{
	x = 32;
	y += 25;
	}
	}*/


	win->end();
	win->show();


}

void select_headCB(Fl_Widget* w, void* p)
{
	/*Fl_Window* win = new Fl_Window(900, 500, "Radio Button");
	Fl_Help_View* v = new Fl_Help_View(0, 0, 900, 500, "<HTML><Head>Something</Head></HTML>");
	v->load("test.html");
	win->end();
	win->show();*/

	int i, x = 32, y = 80;
	Fl_Window* win = new Fl_Window(900, 500, "Select Head");
	Fl_PNG_Image* img;
	Fl_Button* o;
	char* label;
	char* pic;
	int len, len2;

	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Please Select a Head");
	basic->labelfont(FL_BOLD);
	basic->labelsize(36);

	//Fl_Group* o = new Fl_Group(10, 10, 347, 73);
	//o->box(FL_DOWN_BOX);
	for (i = 0; i < store.head.size(); i++)
	{

		//cout << c << endl;
		label = new char(store.head[i]->get_name().length() + 1);
		len = (store.head[i]->get_name().length() + 1);
		strcpy_s(label, len, store.head[i]->get_name().c_str());
		o = new Fl_Button(x, y, 64, 15, label);
		//cout << pic;
		y += 25;
		if (i != 0 && i % 5 == 0)
		{
			x += 100;
			y = 80;
		}

		o->callback(set_head_indCB);
		//cout << store.left_arm[i]->get_filename().length() << endl;
	}



	/*x = 32, y = 20;

	for (i = 0; i < store.left_arm.size(); i++)
	{
	fl_register_images();
	pic = new char(store.left_arm[i]->get_filename().length() + 1);
	len2 = (store.left_arm[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.left_arm[i]->get_filename().c_str());
	Fl_Box* box = new Fl_Box(x, y, 50, 50);
	img = new Fl_PNG_Image(pic);
	box->image(img->copy(50, 50));
	x += 20;
	if (i != 0 && i % 5 == 0)
	{
	x = 32;
	y += 25;
	}
	}*/


	win->end();
	win->show();


}

void select_locoCB(Fl_Widget* w, void* p)
{
	/*Fl_Window* win = new Fl_Window(900, 500, "Radio Button");
	Fl_Help_View* v = new Fl_Help_View(0, 0, 900, 500, "<HTML><Head>Something</Head></HTML>");
	v->load("test.html");
	win->end();
	win->show();*/

	int i, x = 32, y = 80;
	Fl_Window* win = new Fl_Window(900, 500, "Select Locomotor");
	Fl_PNG_Image* img;
	Fl_Button* o;
	char* label;
	char* pic;
	int len, len2;

	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Please Select a Locomotor");
	basic->labelfont(FL_BOLD);
	basic->labelsize(36);

	//Fl_Group* o = new Fl_Group(10, 10, 347, 73);
	//o->box(FL_DOWN_BOX);
	for (i = 0; i < store.loco.size(); i++)
	{

		//cout << c << endl;
		label = new char(store.loco[i]->get_name().length() + 1);
		len = (store.loco[i]->get_name().length() + 1);
		strcpy_s(label, len, store.loco[i]->get_name().c_str());
		o = new Fl_Button(x, y, 64, 15, label);
		//cout << pic;
		y += 25;
		if (i != 0 && i % 5 == 0)
		{
			x += 100;
			y = 80;
		}

		o->callback(set_loco_indCB);
		//cout << store.left_arm[i]->get_filename().length() << endl;
	}



	/*x = 32, y = 20;

	for (i = 0; i < store.left_arm.size(); i++)
	{
	fl_register_images();
	pic = new char(store.left_arm[i]->get_filename().length() + 1);
	len2 = (store.left_arm[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.left_arm[i]->get_filename().c_str());
	Fl_Box* box = new Fl_Box(x, y, 50, 50);
	img = new Fl_PNG_Image(pic);
	box->image(img->copy(50, 50));
	x += 20;
	if (i != 0 && i % 5 == 0)
	{
	x = 32;
	y += 25;
	}
	}*/


	win->end();
	win->show();


}

void select_torsoCB(Fl_Widget* w, void* p)
{
	/*Fl_Window* win = new Fl_Window(900, 500, "Radio Button");
	Fl_Help_View* v = new Fl_Help_View(0, 0, 900, 500, "<HTML><Head>Something</Head></HTML>");
	v->load("test.html");
	win->end();
	win->show();*/

	int i, x = 32, y = 80;
	Fl_Window* win = new Fl_Window(900, 500, "Select Torso");
	Fl_PNG_Image* img;
	Fl_Button* o;
	char* label;
	char* pic;
	int len, len2;

	Fl_Box *basic = new Fl_Box(425, 0, 135, 50, "Please Select a Torso");
	basic->labelfont(FL_BOLD);
	basic->labelsize(36);

	//Fl_Group* o = new Fl_Group(10, 10, 347, 73);
	//o->box(FL_DOWN_BOX);
	for (i = 0; i < store.tor.size(); i++)
	{

		//cout << c << endl;
		label = new char(store.tor[i]->get_name().length() + 1);
		len = (store.tor[i]->get_name().length() + 1);
		strcpy_s(label, len, store.tor[i]->get_name().c_str());
		o = new Fl_Button(x, y, 64, 15, label);
		//cout << pic;
		y += 25;
		if (i != 0 && i % 5 == 0)
		{
			x += 100;
			y = 80;
		}

		o->callback(set_torso_indCB);
		//cout << store.left_arm[i]->get_filename().length() << endl;
	}



	/*x = 32, y = 20;

	for (i = 0; i < store.left_arm.size(); i++)
	{
	fl_register_images();
	pic = new char(store.left_arm[i]->get_filename().length() + 1);
	len2 = (store.left_arm[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.left_arm[i]->get_filename().c_str());
	Fl_Box* box = new Fl_Box(x, y, 50, 50);
	img = new Fl_PNG_Image(pic);
	box->image(img->copy(50, 50));
	x += 20;
	if (i != 0 && i % 5 == 0)
	{
	x = 32;
	y += 25;
	}
	}*/


	win->end();
	win->show();


}

void set_left_arm_indCB(Fl_Widget* w, void* p)
{
	int i, len;
	char* label;
	Fl_Button* sel = (Fl_Button*)w;
	for (i = 0; i < store.left_arm.size(); i++)
	{
		label = new char(store.left_arm[i]->get_name().length() + 1);
		len = (store.left_arm[i]->get_name().length() + 1);
		strcpy_s(label, len, store.left_arm[i]->get_name().c_str());
		if (strcmp(sel->label(), label) == 0)
		{
			left_arm_ind = i;
			return;
		}
	}

	/*cout << sel->label() << endl; //test*/
}

void set_right_arm_indCB(Fl_Widget* w, void* p)
{
	int i, len;
	char* label;
	Fl_Button* sel = (Fl_Button*)w;
	for (i = 0; i < store.right_arm.size(); i++)
	{
		label = new char(store.right_arm[i]->get_name().length() + 1);
		len = (store.right_arm[i]->get_name().length() + 1);
		strcpy_s(label, len, store.right_arm[i]->get_name().c_str());
		if (strcmp(sel->label(), label) == 0)
		{
			right_arm_ind = i;
			return;
		}
	}

	/*cout << sel->label() << endl; //test*/
}

void set_batt_indCB(Fl_Widget* w, void* p)
{
	int i, len;
	char* label;
	Fl_Button* sel = (Fl_Button*)w;
	for (i = 0; i < store.batt.size(); i++)
	{
		label = new char(store.batt[i]->get_name().length() + 1);
		len = (store.batt[i]->get_name().length() + 1);
		strcpy_s(label, len, store.batt[i]->get_name().c_str());
		if (strcmp(sel->label(), label) == 0)
		{
			batt_ind = i;
			return;
		}
	}

	/*cout << sel->label() << endl; //test*/
}

void set_head_indCB(Fl_Widget* w, void* p)
{
	int i, len;
	char* label;
	Fl_Button* sel = (Fl_Button*)w;
	for (i = 0; i < store.head.size(); i++)
	{
		label = new char(store.head[i]->get_name().length() + 1);
		len = (store.head[i]->get_name().length() + 1);
		strcpy_s(label, len, store.head[i]->get_name().c_str());
		if (strcmp(sel->label(), label) == 0)
		{
			head_ind = i;
			return;
		}
	}

	/*cout << sel->label() << endl; //test*/
}

void set_loco_indCB(Fl_Widget* w, void* p)
{
	int i, len;
	char* label;
	Fl_Button* sel = (Fl_Button*)w;
	for (i = 0; i < store.loco.size(); i++)
	{
		label = new char(store.loco[i]->get_name().length() + 1);
		len = (store.loco[i]->get_name().length() + 1);
		strcpy_s(label, len, store.loco[i]->get_name().c_str());
		if (strcmp(sel->label(), label) == 0)
		{
			loco_ind = i;
			return;
		}
	}

	/*cout << sel->label() << endl; //test*/
}
void set_torso_indCB(Fl_Widget* w, void* p)
{
	int i, len;
	char* label;
	Fl_Button* sel = (Fl_Button*)w;
	for (i = 0; i < store.tor.size(); i++)
	{
		label = new char(store.tor[i]->get_name().length() + 1);
		len = (store.tor[i]->get_name().length() + 1);
		strcpy_s(label, len, store.tor[i]->get_name().c_str());
		if (strcmp(sel->label(), label) == 0)
		{
			torso_ind = i;
			return;
		}
	}

	/*cout << sel->label() << endl; //test*/
}




/*void whenPushed6(Fl_Widget* w, void* p)
{
	printf("%s says:", (char*)p);
	if (((Fl_Button*)w)->value())
		printf("Ouch!\n");
	else
		printf("Ahhh!\n");
}*/