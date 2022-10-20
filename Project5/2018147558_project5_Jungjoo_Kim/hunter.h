#ifndef Hunter_H
#define Hunter_H

#include "critter.h"

class Hunter : public creature{ //a class for children of creature
	public:
		Hunter();
		Hunter(int po_num);
		Hunter(int x, int y, int po_num);
		int get_x() const;
		int get_y() const;
		int get_score() const;
		int get_potion() const;
		void set_pos(int x, int y);
		void up_score(int a);
		void set_potion(int p);
		void use_potion();
		void move();
	private:
		int score;
		int potion;
		int x_pos;
		int y_pos;
};

#endif
