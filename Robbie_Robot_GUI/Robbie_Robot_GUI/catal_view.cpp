#include "catal_view.h"
#include "FL/Fl.h"
#include "FL/Fl_Window.h"
#include "FL/Fl_Box.h"
#include "FL/Fl_Button.h"
#include "store.h"
#include "FL/Fl_Shared_Image.h"
#include "FL/Fl_JPEG_Image.h"
#include "iostream"

using namespace std;

Fl_Window* win;
Fl_Box* box;
Fl_Box* name;
Fl_JPEG_Image* img;

extern Store store;
int i = 0, len, len2;
char* pic, *label, *cost, *weight;

void catalCB(Fl_Widget* w, void* p)
{
	win = new Fl_Window(900, 500, "Robbie Robot Catalogue");
	int x = 32, y = 20;

	//cout << store.rob[i]->get_name() << endl;
	fl_register_images();
	pic = new char(store.rob[i]->get_filename().length() + 1);
	len2 = (store.rob[i]->get_filename().length() + 1);
	strcpy_s(pic, len2, store.rob[i]->get_filename().c_str());
	box = new Fl_Box(x, y, 300, 300);
	img = new Fl_JPEG_Image(pic);
	box->image(img->copy(300, 300));



	//cout << c << endl;
	//label = new char(store.rob[i]->get_name().length() + 1);
	//len = (store.rob[i]->get_name().length() + 1);
	//strcpy_s(label, len, store.rob[i]->get_name().c_str());
	//name = new Fl_Box(x+ 300, y + 300, 64, 15, label);
	//cout << pic;*/
	

	win->end();
	win->show();
}