#ifndef Grass_H
#define Grass_H

class Grass{ //Grass class
	public:
		static int num; //Indicates the number of grass
		Grass();
		Grass(int x, int y);
		int get_x() const; 
		int get_y() const; 
		void set_pos(int x, int y);
	private:
		int x_pos;
		int y_pos;
};

#endif
