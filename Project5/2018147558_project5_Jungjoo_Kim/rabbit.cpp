#include "rabbit.h"

int Rabbit::num =0;
Rabbit::Rabbit():x_pos(0),y_pos(0),lifetime(0),creature(3){num++;}
Rabbit::Rabbit(int x, int y):x_pos(x),y_pos(y),lifetime(0),creature(3){num++;}
int Rabbit::get_x() const{return x_pos;}
int Rabbit::get_y() const{return y_pos;}
int Rabbit::get_lifetime() const{return lifetime;}
void Rabbit::survive(){lifetime++;}
void Rabbit::set_lifetime(int l){lifetime = l;}

void Rabbit::set_pos(int x,int y){
	x_pos = x;
	y_pos = y;
}

void Rabbit::move(int d){ //get derection and move function
	if(d==1) y_pos--;
	else if(d==2) x_pos++;
	else if(d==3) y_pos++;
	else x_pos--;
}

