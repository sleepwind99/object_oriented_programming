#include "pit.h"

Pit::Pit(){ 
	x_pos = 0;
	y_pos = 0;
	num++;
}

int Pit::num = 0; //static number initialization
int Pit::get_x() const{return x_pos;}
int Pit::get_y() const{return y_pos;}
void Pit::set_pos(int x, int y){
	x_pos = x;
	y_pos = y;
}


