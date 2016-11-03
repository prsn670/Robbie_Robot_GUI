#include "iostream"
#include "rob_part_input.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "Fl/Fl_Input.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Input.H"
#include "Fl/Fl_Button.H"
#include "FL/Fl_Int_Input.H"


using namespace std;
void part_inputCB(Fl_Widget *w, void *p)
{
	

	Fl_Window *win = new Fl_Window(900, 300, "Create Robot Parts");
	Fl_Button *sub = new Fl_Button(50, 100, 100, 100, "Submit");
	Fl_Input *arm_weight = new Fl_Input(100, 0, 50, 30, "Arm weight");
	Fl_Input *arm_cost = new Fl_Input(250, 0, 50, 30, "Arm cost");
	sub->callback(submittedCB, &arm_weight);
	win->end();
	win->show();
	//Fl_Box *b = new Fl_Box(50, 50, 900, 300, "Something Here");
	//b->draw();
	//Fl_Input *l = new Fl_Input(50, 50, 100, 100);
	cout << "Does this work at least?" << endl;

}
void submittedCB(Fl_Widget* w, void* param1)
{
	//int num = *(reinterpret_cast<int*>(param1));
	int* num = (int*)(param1);
	int first, second;
	first = *num;
	
	cout << "The number entered was: " << first << endl;
	


}