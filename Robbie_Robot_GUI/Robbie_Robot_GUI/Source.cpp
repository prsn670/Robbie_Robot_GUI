#include "FL/Fl.H"
// Include each �widget� you use
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"
#include "Fl/Fl_Menu_Bar.H"
#include "FL/Fl_Menu_Item.H"
#include "rob_part_input.h"



int main()
{
	Fl_Window *win = new Fl_Window(900, 300, "Robbie Robot");
	Fl_Box *box = new Fl_Box(0, 0, 900, 300, "Robbie Robot");
	

	Fl_Menu_Bar *menu_bar = new Fl_Menu_Bar(0, 0, 300, 30);
	Fl_Menu_Item menu_items[] =
	{
		{"&Product Manager", 0 , 0 , 0, FL_SUBMENU},
			{"Create Robot Parts", 0, (Fl_Callback *)part_inputCB},
			{"Create Robot Model"},
		{0},
		{ "Customer" },
		{0},
	};
	menu_bar->menu(menu_items);
	//win->resizable(box);
	//win->resizable(bx);
	win->end();
	win->show();

	return (Fl::run());
}