#ifndef Pit_H
#define Pit_H

class Pit{ //pit class
	public:
		static int num; //Indicates the number of pits
		Pit();
		int get_x() const;
		int get_y() const;
		void set_pos(int x,int y);
	private:
		int x_pos;
		int y_pos;
};

#endif
