#include "critter.h"

void creature::de_life(){life--;} //Decrease life
creature::creature():life(0){} //default constructor
creature::creature(int l):life(l){} //constructor
int creature::get_life() const{return life;} //return life
void creature::set_life(int l){life = l;} //mutator

