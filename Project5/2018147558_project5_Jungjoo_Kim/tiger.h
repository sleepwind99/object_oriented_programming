#ifndef Tiger_H
#define Tiger_H

#include "critter.h"

class Tiger : public creature{
	public:
		static int num;
		Tiger();
		Tiger(int x, int y);
		int get_x() const;
		int get_y() const;
		int get_lifetime() const;
		void survive();
		void set_pos(int x, int y);
		void set_lifetime(int l);
		void move(int d);
	private:
		int x_pos;
		int y_pos;
		int lifetime; //the time of one's life
};

#endif
