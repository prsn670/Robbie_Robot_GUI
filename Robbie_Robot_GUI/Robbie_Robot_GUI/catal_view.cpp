#include "catal_view.h"
#include "FL/Fl.h"
#include "FL/Fl_Window.h"
#include "FL/Fl_Box.h"
#include "FL/Fl_Button.h"
#include "store.h"
#include "FL/Fl_Shared_Image.h"
#include "FL/Fl_JPEG_Image.h"
#include "FL/Fl_Multiline_Output.h"
#include "FL/Fl_Button.h"
#include "iostream"

using namespace std;


Fl_Box* name_box;
Fl_Box* cost_box;
Fl_Box* weight_box;
Fl_Box *part_num_box;
Fl_Box *descr_box;
Fl_Multiline_Output *descr_out;




extern Store store;
extern int i;
int len;
double markup = 1.15; //15% markup on cost
char *label, *cost, *weight, *part_num, *descr;


void catalCB(Fl_Widget* w, void* p)
{
	Fl_Window* win = new Fl_Window(900, 500, "Robbie Robot Catalogue");
	Fl_Box* box;
	
	i = 0;
	int x = 32, y = 20, but_w = 100, but_h = 35;
	//int but_w = 100, but_h = 35;
	//int x = 32, y = 20;

	//cout << store.rob[i]->get_name() << endl;
	/*fl_register_images();
	pic = new char(store.rob[i]->get_filename().length() + 1);
	len2 = (store.rob[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.rob[i]->get_filename().c_str());
	box = new Fl_Box(x, y, 300, 300);
	img = new Fl_JPEG_Image(pic);
	box->image(img->copy(300, 300));*/



	//cout << c << endl;
	label = new char(store.rob[i]->get_name().length() + 1);
	len = (store.rob[i]->get_name().length() + 1);
	strcpy_s(label, len, store.rob[i]->get_name().c_str());
	name_box = new Fl_Box(x+ 100, y, 64, 15, label);
	box = new Fl_Box(x, y, 64, 15, "Model Name:");

	part_num = new char(to_string(store.rob[i]->get_part_num()).length() + 1);
	len = (to_string(store.rob[i]->get_part_num()).length() + 1);
	strcpy_s(part_num, len, to_string(store.rob[i]->get_part_num()).c_str());
	part_num_box = new Fl_Box(x + 100, y += 100, 64, 15, part_num);
	box = new Fl_Box(x, y, 64, 15, "Part Number:");

	cost = new char(to_string(store.rob[i]->get_cost() * markup).length() + 1);
	len = (to_string(store.rob[i]->get_cost()).length() + 1);
	strcpy_s(cost, len, to_string(store.rob[i]->get_cost()).c_str());
	cost_box = new Fl_Box(x + 100, y += 100, 64, 15, cost);
	box = new Fl_Box(x, y, 64, 15, "Price:");

	weight = new char(to_string(store.rob[i]->get_weight()).length() + 1);
	len = (to_string(store.rob[i]->get_weight()).length() + 1);
	strcpy_s(weight, len, to_string(store.rob[i]->get_weight()).c_str());
	weight_box = new Fl_Box(x + 100, y += 100, 64, 15, weight);
	box = new Fl_Box(x, y, 64, 15, "Weight:");
	
	descr = new char(store.rob[i]->get_description().length() + 1);
	len = (store.rob[i]->get_description().length() + 1);
	strcpy_s(descr, len, store.rob[i]->get_description().c_str());
	//descr_box = new Fl_Box(x + 100, y+=100, 64, 15, descr);
	//box = new Fl_Box(x, y, 64, 15, "Description:");
	descr_out = new Fl_Multiline_Output(x + 90, y + 30, 150, 80, "Description:");
	descr_out->wrap(1);
	descr_out->value(descr);

	Fl_Button *prev = new Fl_Button(x, y + 120, but_w, but_h, "Previous");
	Fl_Button *view = new Fl_Button(x+=but_w, y + 120, but_w, but_h, "View Image");
	Fl_Button *next = new Fl_Button(x +=but_w, y + 120, but_w, but_h, "Next");
	
	//shows and hides next and previous buttons if there is not next or no previous respectively
	if (i == 0)
	{
		prev->hide();
		
	}
	
	if (i == store.rob.size() - 1)
	{
		next->hide();

	}
	

	next->callback(nextCB, prev);
	prev->callback(prevCB, next);
	view->callback(show_imgCB);
	win->end();
	win->redraw();
	win->show();
}

void nextCB(Fl_Widget* w, void* p)
{
	Fl_Button *next = (Fl_Button*) w;
	Fl_Button *prev = (Fl_Button*)p;
	i++;
	//cout << i << endl;
	label = new char(store.rob[i]->get_name().length() + 1);
	len = (store.rob[i]->get_name().length() + 1);
	strcpy_s(label, len, store.rob[i]->get_name().c_str());
	name_box->label(label);

	part_num = new char(to_string(store.rob[i]->get_part_num()).length() + 1);
	len = (to_string(store.rob[i]->get_part_num()).length() + 1);
	strcpy_s(part_num, len, to_string(store.rob[i]->get_part_num()).c_str());
	part_num_box->label(part_num);
	

	cost = new char(to_string(store.rob[i]->get_cost() * markup).length() + 1);
	len = (to_string(store.rob[i]->get_cost()).length() + 1);
	strcpy_s(cost, len, to_string(store.rob[i]->get_cost()).c_str());
	cost_box->label(cost);

	weight = new char(to_string(store.rob[i]->get_weight()).length() + 1);
	len = (to_string(store.rob[i]->get_weight()).length() + 1);
	strcpy_s(weight, len, to_string(store.rob[i]->get_weight()).c_str());
	weight_box->label(weight);

	descr = new char(store.rob[i]->get_description().length() + 1);
	len = (store.rob[i]->get_description().length() + 1);
	strcpy_s(descr, len, store.rob[i]->get_description().c_str());
	//descr_box = new Fl_Box(x + 100, y+=100, 64, 15, descr);
	//box = new Fl_Box(x, y, 64, 15, "Description:");
	descr_out->wrap(1);
	descr_out->value(descr);

	if (i == 0)
	{
		prev->hide();
		
	}
	else
	{
		prev->show();
		
	}
	if (i == store.rob.size() - 1)
	{
		next->hide();

	}
	else
	{
		next->show();
	}

}

void prevCB(Fl_Widget* w, void* p)
{
	Fl_Button *prev = (Fl_Button*)w;
	Fl_Button *next = (Fl_Button*)p;
	i--;
	//cout << i << endl;
	label = new char(store.rob[i]->get_name().length() + 1);
	len = (store.rob[i]->get_name().length() + 1);
	strcpy_s(label, len, store.rob[i]->get_name().c_str());
	name_box->label(label);

	part_num = new char(to_string(store.rob[i]->get_part_num()).length() + 1);
	len = (to_string(store.rob[i]->get_part_num()).length() + 1);
	strcpy_s(part_num, len, to_string(store.rob[i]->get_part_num()).c_str());
	part_num_box->label(part_num);


	cost = new char(to_string(store.rob[i]->get_cost() * markup).length() + 1);
	len = (to_string(store.rob[i]->get_cost()).length() + 1);
	strcpy_s(cost, len, to_string(store.rob[i]->get_cost()).c_str());
	cost_box->label(cost);

	weight = new char(to_string(store.rob[i]->get_weight()).length() + 1);
	len = (to_string(store.rob[i]->get_weight()).length() + 1);
	strcpy_s(weight, len, to_string(store.rob[i]->get_weight()).c_str());
	weight_box->label(weight);

	descr = new char(store.rob[i]->get_description().length() + 1);
	len = (store.rob[i]->get_description().length() + 1);
	strcpy_s(descr, len, store.rob[i]->get_description().c_str());
	//descr_box = new Fl_Box(x + 100, y+=100, 64, 15, descr);
	//box = new Fl_Box(x, y, 64, 15, "Description:");
	descr_out->wrap(1);
	descr_out->value(descr);

	if (i == 0)
	{
		prev->hide();
		
	}
	else
	{
		prev->show();
		
	}
	if (i == store.rob.size() - 1)
	{
		next->hide();

	}
	else
	{
		next->show();
	}
}

void show_imgCB(Fl_Widget* w, void* p)
{
	char* pic;
	int len2;

	if (store.rob[i]->get_filename() == "")
	{
		Fl_Window *iwin = new Fl_Window(400, 400, "Image");
		Fl_Box *ibox = new Fl_Box(50, 50, 300, 300, "No Image Available");
		iwin->end();
		iwin->show();
		return;
	}
	Fl_Window *iwin = new Fl_Window(400, 400, "Image");
	fl_register_images();
	pic = new char(store.rob[i]->get_filename().length() + 1);
	len2 = (store.rob[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.rob[i]->get_filename().c_str());
	Fl_Box *ibox = new Fl_Box(50, 50, 300, 300);
	//Fl_JPEG_Image* img = new Fl_JPEG_Image(pic);
	Fl_Shared_Image* img = Fl_Shared_Image::get(pic);
	ibox->image(img->copy(300, 300));
	iwin->end();
	iwin->show();
	img->release();//releases image copy
}