#ifndef Rabbit_H
#define Rabbit_H

#include "critter.h"

class Rabbit : public creature{
	public:
		static int num; //Indicates the number of rabbits
		Rabbit();
		Rabbit(int x,int y);
		int get_x() const;
		int get_y() const;
		int get_lifetime() const;
		void survive();
		void set_pos(int x,int y);
		void move(int d);
		void set_lifetime(int l);
	private:
		int x_pos;
		int y_pos;
		int lifetime; //the time of one's life
};

#endif
