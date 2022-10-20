#ifndef	CREATURE_Hpp
#define CREATURE_Hpp

class creature{
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
