#include "grass.h"

int Grass::num = 0; //static number initialization
Grass::Grass():x_pos(0),y_pos(0){num++;} 
Grass::Grass(int x,int y):x_pos(x),y_pos(y){num++;}
int Grass::get_x() const{return x_pos;} //Acesser
int Grass::get_y() const{return y_pos;} //Acesser

void Grass::set_pos(int x, int y){
	x_pos = x;
	y_pos = y;
}

