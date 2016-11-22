#ifndef _ROB_PART_INPUT_H
#define _ROB_PART_INPUT_H
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "Fl/Fl_Input.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Input.H"
#include "Fl/Fl_Button.H"
#include "FL/Fl_Int_Input.H"
#include "iostream"


using namespace std;

/*class param
{
public:
	Fl_Input *name;
	Fl_Input *weight;
	Fl_Input *cost;
	Fl_Input *part_num;
	Fl_Input *descript;

};*/

void part_inputCB(Fl_Widget *w, void *p);
void model_inputCB(Fl_Widget *w, void *p);


void submit_left_armCB(Fl_Widget* w, void* p);
void submit_right_armCB(Fl_Widget* w, void* p);
void submit_headCB(Fl_Widget* w, void* p);
void submit_battCB(Fl_Widget* w, void* p);
void submit_locoCB(Fl_Widget* w, void* p);
void submit_torsoCB(Fl_Widget* w, void* p);
void choose_picCB(Fl_Widget* w, void* p);
void select_left_armCB(Fl_Widget* w, void* p);
void select_right_armCB(Fl_Widget* w, void* p);
void select_battCB(Fl_Widget* w, void* p);
void select_headCB(Fl_Widget* w, void* p);
void select_locoCB(Fl_Widget* w, void* p);
void select_torsoCB(Fl_Widget* w, void* p);

void set_left_arm_indCB(Fl_Widget* w, void* p);
void set_right_arm_indCB(Fl_Widget* w, void* p);
void set_batt_indCB(Fl_Widget* w, void* p);
void set_head_indCB(Fl_Widget* w, void* p);
void set_loco_indCB(Fl_Widget* w, void* p);
void set_torso_indCB(Fl_Widget* w, void* p);

void create_modelCB(Fl_Widget* w, void* p);




//void whenPushed6(Fl_Widget* w, void* p);
#endif // !_ROB_PART_INPUT_H
