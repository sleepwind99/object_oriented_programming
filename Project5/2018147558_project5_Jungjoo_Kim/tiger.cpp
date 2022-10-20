#include "tiger.h"

int Tiger::num=0;
Tiger::Tiger():x_pos(0),y_pos(0),creature(3){num++;}
Tiger::Tiger(int x, int y):x_pos(x),y_pos(y),creature(3){num++;}
int Tiger::get_x() const{return x_pos;}
int Tiger::get_y() const{return y_pos;}
int Tiger::get_lifetime() const{return lifetime;}
void Tiger::survive(){lifetime++;}
void Tiger::set_lifetime(int l){lifetime = l;}

void Tiger::set_pos(int x, int y){
	x_pos = x;
	y_pos = y;
}

void Tiger::move(int d){ //get derection and move function
	if(d==1) y_pos--;
	else if(d==2) x_pos++;
	else if(d==3) y_pos++;
	else x_pos--;
}


