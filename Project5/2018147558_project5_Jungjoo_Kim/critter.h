#ifndef Critter_H
#define Critter_H

class creature{ //parents class
	public:
		creature();
		creature(int l);
		void de_life();
		void set_life(int l);
		int get_life() const;
	private:
		int life; 
};

#endif
