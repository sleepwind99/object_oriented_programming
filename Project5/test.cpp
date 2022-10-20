#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;
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

void creature::de_life(){life--;}
creature::creature():life(0){}
creature::creature(int l):life(l){}
int creature::get_life() const{return life;}
void creature::set_life(int l){life = l;}

class Tiger;
class Hunter;

class Rabbit : public creature{
	public:
		static int num;
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
		int lifetime;
};
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

void Rabbit::move(int d){
	if(d==1) y_pos--;
	else if(d==2) x_pos++;
	else if(d==3) y_pos++;
	else x_pos--;
}

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
		int lifetime;
};

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

void Tiger::move(int d){
	if(d==1) y_pos--;
	else if(d==2) x_pos++;
	else if(d==3) y_pos++;
	else x_pos--;
}

class Hunter : public creature{
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

Hunter::Hunter():score(0),potion(0),x_pos(0),y_pos(0),creature(5){}
Hunter::Hunter(int x,int y,int po_num):score(0),potion(po_num),x_pos(x),y_pos(y),creature(5){}
Hunter::Hunter(int po_num):score(0),potion(po_num),x_pos(rand()%19),y_pos(rand()%19),creature(5){}
int Hunter::get_x() const{return x_pos;}
int Hunter::get_y() const{return y_pos;}
int Hunter::get_score() const{return score;}
int Hunter::get_potion() const{return potion;}
void Hunter::up_score(int a){score += a;}

void Hunter::set_pos(int x, int y){
	x_pos = x;
	y_pos = y;
}

void Hunter::set_potion(int p){
	potion = p;
}

void Hunter::use_potion(){
	string use;
	while(true){
		cout << "Are you going to use potion( Yes: 'y', No: 'n' ) : ";
		cin >> use;
		if(use.compare("y")==0){
			if(potion==0) {
				cout << "You are consume all of the potion!" <<endl;
				break;
			}
			else{
				potion--;
				set_life(5);
				break;
			}
		}
		else if(use.compare("n")==0){
			break;
		}
		else{
			cout << "Worng Input!"<<endl;
		}
	}
}

void Hunter::move(){
	string moving;
	while(1){
		cout << "Input the moving direction( Up: 'w', Down: 's', Left: 'a', Right: 'd' ): ";
		cin >> moving;
		if(moving.compare("w")==0){
			y_pos--;
			break;
		}
		else if(moving.compare("d")==0){
			x_pos++;
			break;
		}
		else if(moving.compare("s")==0){
			y_pos++;
			break;
		}
		else if(moving.compare("a")==0){
			x_pos--;
			break;
		}
		else if(moving.compare("wd")==0){
			y_pos-=1;
			x_pos+=1;
			break;
		}
		else if(moving.compare("wa")==0){
			y_pos-=1;
			x_pos-=1;
			break;
		}
		else if(moving.compare("sd")==0){
			y_pos+=1;
			x_pos+=1;
			break;
		}
		else if(moving.compare("sa")==0){
			y_pos+=1;
			x_pos-=1;
			break;
		}
		else cout << "Wrong Input" <<endl;
	}
}

class Grass{
	public:
		static int num;
		Grass();
		Grass(int x, int y);
		int get_x() const;
		int get_y() const;
		void set_pos(int x, int y);
	private:
		int x_pos;
		int y_pos;
};

int Grass::num = 0;
Grass::Grass():x_pos(0),y_pos(0){num++;}
Grass::Grass(int x,int y):x_pos(x),y_pos(y){num++;}
int Grass::get_x() const{return x_pos;}
int Grass::get_y() const{return y_pos;}

void Grass::set_pos(int x, int y){
	x_pos = x;
	y_pos = y;
}

class Pit{
	public:
		static int num;
		Pit();
		int get_x() const;
		int get_y() const;
		void set_pos(int x,int y);
	private:
		int x_pos;
		int y_pos;
};

Pit::Pit(){
	x_pos = 0;
	y_pos = 0;
	num++;
}

int Pit::num = 0;
int Pit::get_x() const{return x_pos;}
int Pit::get_y() const{return y_pos;}
void Pit::set_pos(int x, int y){
	x_pos = x;
	y_pos = y;
}

int CharToInt(){
	char c[3];
	cin >> c;
	int arr_num=0, int_num=0, square=0;
	for(int i=0;i<3;i++){
		if(c[i]<48 || c[i]>57){
			if(c[i]!=0) return -1;
		}
		else arr_num++;
	}
	for(int i=arr_num-1;i>=0;i--){
		int_num += (c[i]-48)*pow(10,square);
		square++;
	}
	return int_num;
}

bool operator ==(const Hunter* H,const Tiger& T){return H->get_x()==T.get_x() && H->get_y()==T.get_y();}
bool operator ==(const Hunter* H,const Rabbit& R){return H->get_x()==R.get_x() && H->get_y()==R.get_y();}
bool operator ==(const Tiger& T,const Rabbit& R){return T.get_x()==R.get_x() && T.get_y()==R.get_y();}
bool operator ==(const Rabbit& R,const Grass& G){return R.get_x()==G.get_x() && R.get_y()==G.get_y();}
bool operator ==(const Hunter* H,const Grass& G){return H->get_x()==G.get_x() && H->get_y()==G.get_y();}
bool operator ==(const Tiger& T,const Grass& G){return T.get_x()==G.get_x() && T.get_y()==G.get_y();}
bool operator ==(const Pit& P,const Grass& G){return P.get_x()==G.get_x() && P.get_y() ==G.get_y();}
bool operator ==(const Hunter* H,const Pit& P){return H->get_x()==P.get_x() && H->get_y()==P.get_y();}
bool operator ==(const Rabbit& R,const Pit& P){return R.get_x()==P.get_x() && R.get_y()==P.get_y();}
bool operator ==(const Tiger& T,const Pit& P){return T.get_x()==P.get_x() && T.get_y()==P.get_y();}

void R_breed(Rabbit& PR,Rabbit& CR,int a){
	if(a==1) CR = Rabbit(PR.get_x(),PR.get_y()-1);
	else if(a==2) CR = Rabbit(PR.get_x()+1,PR.get_y());
	else if(a==3) CR = Rabbit(PR.get_x(),PR.get_y()+1);
	else CR = Rabbit(PR.get_x()-1,PR.get_y());
	CR.set_lifetime(0);
}

void T_breed(Tiger& PT,Tiger& CT,int a){
	if(a==1) CT = Tiger(PT.get_x(),PT.get_y()-1);
	else if(a==2) CT = Tiger(PT.get_x()+1,PT.get_y());
	else if(a==3) CT = Tiger(PT.get_x(),PT.get_y()+1);
	else CT = Tiger(PT.get_x()-1,PT.get_y());
	CT.set_lifetime(0);
}

int main(){
	int r, t, p, h, g, total, *x, *y, TorF, xn, yn;
	Rabbit *R;
	Tiger *T;
	Pit *P;
	Grass *G;
	Hunter *user;
	char demention[20][20];
	while(1){
		cout << "Enter initial number of rabbits : ";
		r = CharToInt();
		if(r!=-1) break;
	}
	R = new Rabbit[r];
	while(1){
		cout << "Enter initial number of tigers : ";
		t = CharToInt(); 
		if(t!=-1) break;
	}
	T = new Tiger[t];
	while(1){
		cout << "Enter initial number of grasses : ";
		g = CharToInt(); 
		if(g!=-1) break;
	}
	G = new Grass[g];
	while(1){
		cout << "Enter initial number of pits : ";
		h = CharToInt(); 
		if(h!=-1) break;
	}
	P = new Pit[h];
	while(1){
		cout << "Enter initial number of potions : ";
		p = CharToInt(); 
		if(p!=-1) break;
	}
	user = new Hunter;
	user->set_potion(p);
	total = r+t+h+g+1;
	x = new int[total];
	y = new int[total];
	srand(time(0));
	
	for(int i=0;i<total;i++){
		x[i]=rand()%20;
		y[i]=rand()%20;
	}

	TorF = -1;
	while(TorF == -1){
		TorF = 0;
		for(int i=0;i<total;i++){
			for(int j=i+1;j<total;j++){
				if(x[i]==x[j] && y[i]==y[j]){
					x[j] = rand()%20;
					y[j] = rand()%20;
					TorF = -1;
				}
			}
		}
	}
	xn = 0;
	yn = 0;
	for(int rn=0; rn<r; rn++){
		R[rn].set_pos(x[xn],y[yn]);
		xn++;
		yn++;
	}
	for(int tn=0; tn<t; tn++){
		T[tn].set_pos(x[xn],y[yn]);
		xn++;
		yn++;
	}
	for(int gn=0; gn<g; gn++){
		G[gn].set_pos(x[xn],y[yn]);
		xn++;
		yn++;
	}
	for(int hn=0; hn<h; hn++){
		P[hn].set_pos(x[xn],y[yn]);
		xn++;
		yn++;
	}
	user->set_pos(x[xn],y[yn]);
	int br,sr, cr, fr, bt, st, ct, ft, time=0;
	
	while(1){
		cout << "Time step: " << time <<endl;
		cout << "<Score:" <<user->get_score()<<", HP:"<<user->get_life()<<", Potions:"<<user->get_potion() <<">"<<endl<<endl;
		
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				demention[j][i] = '-';
			}
		}
		for(int gn=0;gn<Grass::num;gn++){
			demention[G[gn].get_x()][G[gn].get_y()] = '*';
		}
		for(int rn=0;rn<Rabbit::num;rn++){
			demention[R[rn].get_x()][R[rn].get_y()] = 'R';
		}
		for(int tn=0;tn<Tiger::num;tn++){
			demention[T[tn].get_x()][T[tn].get_y()] = 'T';
		}
		for(int hn=0;hn<Pit::num;hn++){
			demention[P[hn].get_x()][P[hn].get_y()] = 'O';
		}
		demention[user->get_x()][user->get_y()] = 'H';
		
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				cout <<demention[j][i]<<" ";
			}
			cout << "\n";
		}
		
		if(time==0){
			cout << "\nnumber of rabbits: " << Rabbit::num << "      <born:"<<Rabbit::num <<", starve:0, captured: 0, fall:0>"<<endl;
			cout << "number of tigers: "<< Tiger::num <<"      <born:"<<Tiger::num <<", starve:0, captured: 0, fall:0>"<<endl;
			cout << "number of grasses: "<<Grass::num <<endl;
			cout << "number of pits: " <<Pit::num <<endl;
		}
		else{
			cout << "\nnumber of rabbits: " << Rabbit::num << "      <born:"<< br <<", starve:"<< sr << ", captured:"<< cr <<" , fall:"<< fr << ">"<<endl;
			cout << "number of tigers: "<< Tiger::num <<"      <born:"<< bt <<", starve:"<< st << ", captured:"<< ct <<" , fall:"<< ft << ">"<<endl;
			cout << "number of grasses: "<<Grass::num <<endl;
			cout << "number of pits: " <<Pit::num <<endl;
		}
		br=0; sr=0; cr=0; fr=0; bt=0; st=0; ct=0; ft=0;
		user->move();
		user->de_life();
		user->use_potion();
		
		//All of rabbit and tiger are dead
		if(Rabbit::num==0 && Tiger::num==0){
			cout << "Your final score is "<< user->get_score() <<endl;
			cout << "End of the program" <<endl;
			exit(0);
		}
		
		//User hunts the Rabbit
		for(int i=0;i<Rabbit::num;i++){
			if(user==R[i]){
				user->up_score(1);
				user->set_life(5);
				for(int j=i;j<Rabbit::num;j++){
					R[j] = R[j+1];
				}
				Rabbit::num--;
				cr++;
			}
		}
		
		//User hunts the Tiger
		for(int i=0;i<Tiger::num;i++){
			if(user==T[i]){
				user->up_score(2);
				user->set_life(5);
				for(int j=i;j<Tiger::num;j++){
					T[j] = T[j+1];
				}
				Tiger::num--;
				ct++;
			}
		}
		
		//User fall in the hole
		for(int i=0;i<Pit::num;i++){
			if(user==P[i]){
				cout << "Your final score is "<< user->get_score() <<endl;
				cout << "End of the program" <<endl;
				exit(0);
			}
		}
		
		//User consumes all of life
		if(user->get_life()==0){
			cout << "Your final score is "<< user->get_score() <<endl;
			cout << "End of the program" <<endl;
			exit(0);
		}
		
		//Tiger move
		for(int i=0;i<Tiger::num;i++){
			int TorF = -1, ter = -1;
			int index;
			int a[4]={1,2,3,4};
			for(int j=0;j<Rabbit::num;j++){
				if(T[i].get_y()-1==R[j].get_y() && T[i].get_x()==R[j].get_x()){
					T[i].move(1);
					ter = 1;
				}
				if(ter == -1){
					if(T[i].get_y()==R[j].get_y() && T[i].get_x()+1==R[j].get_x()){
						T[i].move(2);
						ter = 1;
					}
				}
				if(ter == -1){
					if(T[i].get_y()-1==R[j].get_y() && T[i].get_x()==R[j].get_x()){
						T[i].move(3);
						ter = 1;
					}
				}
				if(ter == -1){
					if(T[i].get_y()==R[j].get_y() && T[i].get_x()-1 == R[j].get_x()){
						T[i].move(4);
						ter = 1;
					}
				}
			}
			if(ter == -1){
				for(int j=0;j<Tiger::num;j++){
					if(T[i].get_y()-1==T[j].get_y() && T[i].get_x() == T[j].get_x()) a[0] = 0;
					else if(T[i].get_y()-1==user->get_y() && T[i].get_x() == user->get_x()) a[0] = 0;
					else if(T[i].get_y()-1 < 0) a[0] = 0;
					
					if(T[i].get_y()==T[j].get_y() && T[i].get_x()+1 == T[j].get_x()) a[1] = 0;
					else if(T[i].get_y()==user->get_y() && T[i].get_x()+1 == user->get_x()) a[1] = 0;
					else if(T[i].get_x()+1 ==20) a[1] = 0;
					
					if(T[i].get_y()+1==T[j].get_y() && T[i].get_x() == T[j].get_x()) a[2] = 0;
					else if(T[i].get_y()+1==user->get_y() && T[i].get_x() == user->get_x()) a[2] = 0;
					else if(T[i].get_y()+1==20) a[2] = 0;
					
					if(T[i].get_y()==T[j].get_y() && T[i].get_x()-1 == T[j].get_x()) a[3] = 0;
					else if(T[i].get_y()==user->get_y() && T[i].get_x()-1 == user->get_x()) a[3] = 0;
					else if(T[i].get_x()-1 < 0) a[3] = 0;
				}
				
				for(int j=0;j<4;j++){
					if(a[j]!=0){
						TorF = 1;
					}
				}
				
				if(TorF!=-1){
					while(1){
						index = rand()%4;
						if(a[index]!=0){
							T[i].move(a[index]);
							break;	
						}
					}
				}
			}
		}
		
		//Tiger hunts the Rabbit
		for(int n=0;n<Tiger::num;n++){
			for(int i=0;i<Rabbit::num;i++){
				if(T[n]==R[i]){
					T[n].set_life(3);
					for(int j=i;j<Rabbit::num;j++){
						R[j] = R[j+1];
					}
					Rabbit::num--;
				}
			}
		}
		
		//Tiger fall in hole
		for(int n=0;n<Tiger::num;n++){
			for(int i=0;i<Pit::num;i++){
				if(T[n]==P[i]){
					for(int j=i;j<Tiger::num;j++){
						T[j] = T[j+1];
					}
					Tiger::num--;
					ft++;
				}
			}
		}
		int tigerb = -1;
		int tigern = 0;
		while(tigern<Tiger::num){
			int fie = -1;
			T[tigern].survive();
			T[tigern].de_life();
			//The Tiger starve
			if(T[tigern].get_life() == 0){
				T[tigern].set_lifetime(1);
				for(int j=tigern;j<Tiger::num;j++){
					T[j] = T[j+1];
				}
				fie = 1;
				Tiger::num--;
				st++;
			}
			//Tiger breed
			if(T[tigern].get_lifetime()%4 == 0){
					int TorF = -1;
					int index;
					int a[4]={1,2,3,4};
			
				for(int j=0;j<Tiger::num;j++){
					if(T[tigern].get_y()-1==T[j].get_y() && T[tigern].get_x() == T[j].get_x()) a[0] = 0;
					else if(T[tigern].get_y()-1==user->get_y() && T[tigern].get_x() == user->get_x()) a[0] = 0;
					else if(T[tigern].get_y()-1<0) a[0] = 0;
						
					if(T[tigern].get_y()==T[j].get_y() && T[tigern].get_x()+1 == T[j].get_x()) a[1] = 0;
					else if(T[tigern].get_y()==user->get_y() && T[tigern].get_x()+1 == user->get_x()) a[1] = 0;
					else if(T[tigern].get_x()+1==20) a[1] = 0;
						
					if(T[tigern].get_y()+1==T[j].get_y() && T[tigern].get_x() == T[j].get_x()) a[2] = 0;
					else if(T[tigern].get_y()+1==user->get_y() && T[tigern].get_x() == user->get_x()) a[2] = 0;
					else if(T[tigern].get_y()+1==20) a[2] = 0;
						
					if(T[tigern].get_y()==T[j].get_y() && T[tigern].get_x()-1 == T[j].get_x()) a[3] = 0;
					else if(T[tigern].get_y()==user->get_y() && T[tigern].get_x()-1 == user->get_x()) a[3] = 0;
					else if(T[tigern].get_x()-1 < 0) a[3] = 0;
				}
					
				for(int j=0;j<Rabbit::num;j++){
					if(T[tigern].get_y()-1==R[j].get_y() && T[tigern].get_x() == R[j].get_x()) a[0] = 0;
						
					if(T[tigern].get_y()==R[j].get_y() && T[tigern].get_x()+1 == R[j].get_x()) a[1] = 0;
						
					if(T[tigern].get_y()+1==R[j].get_y() && T[tigern].get_x() == R[j].get_x()) a[2] = 0;
						
					if(T[tigern].get_y()==R[j].get_y() && T[tigern].get_x()-1 == R[j].get_x()) a[3] = 0;
				}
					
				for(int j=0;j<4;j++){
					if(a[j]!=0){
						TorF = 1;
					}
				}
					
				if(TorF!=-1){
					while(1){
						index = rand()%4;
						if(a[index]!=0){
							T_breed(T[tigern],T[Tiger::num],a[index]);
							bt++;
							break;	
						}
					}
					Tiger::num++;
					tigerb = 1;
				}
			}
			
			if(fie == -1) tigern++;
		}
		
		for(int tn = 0;tn<Tiger::num;tn++){
			int ten = -1;
			if(T[tn].get_x() < 0 || T[tn].get_y() < 0){
				for(int n=tn;n<Tiger::num;n++){
					T[n] = T[n+1];
				}
				Tiger::num--;
				ten = 1;
			}
			
			if(ten==-1){
				if(T[tn].get_x() > 20 || T[tn].get_y() > 20){
					for(int n=tn;n<Tiger::num;n++){
						T[n] = T[n+1];
					}
					Tiger::num--;
					ten = 1;
				}
			}
		}
		if(Tiger::num%2!=0 && tigerb==1){
			Tiger::num--;
		}
		
		//Rabbit move
		for(int i=0;i<Rabbit::num;i++){
			int TorF = -1, reg=-1;
			int index;
			int a[4]={1,2,3,4};
			for(int j=0;j<Grass::num;j++){
				if(R[i].get_y()-1==G[j].get_y() && R[i].get_x() == G[j].get_x()){
					R[i].move(1);
					reg = 1;
				}
				if(reg != 1){
					if(R[i].get_y()==G[j].get_y() && R[i].get_x()+1==G[j].get_x()){
						R[i].move(2);
						reg = 1;
					}
				}
				if(reg != 1){
					if(R[i].get_y()+1==G[j].get_y() && R[i].get_x()==G[j].get_x()){
						R[i].move(3);
						reg = 1;
					}
				}
				if(reg != 1){
					if(R[i].get_y()==G[j].get_y() && R[i].get_x()-1==G[j].get_x()){
						R[i].move(4);
						reg = 1;
					}
				}
			}
			if(reg != 1){
				for(int j=0;j<Rabbit::num;j++){
					if(R[i].get_y()-1==R[j].get_y() && R[i].get_x() == R[j].get_x()) a[0] = 0;
					else if(R[i].get_y()-1==user->get_y() && R[i].get_x() == user->get_x()) a[0] = 0;
					else if(R[i].get_y()-1 < 0) a[0] = 0;
					
					if(R[i].get_y()==R[j].get_y() && R[i].get_x()+1 == R[j].get_x()) a[1] = 0;
					else if(R[i].get_y()==user->get_y() && R[i].get_x()+1 == user->get_x()) a[1] = 0;
					else if(R[i].get_x()+1 ==20) a[1] = 0;
					
					if(R[i].get_y()+1==R[j].get_y() && R[i].get_x() == R[j].get_x()) a[2] = 0;
					else if(R[i].get_y()+1==user->get_y() && R[i].get_x() == user->get_x()) a[2] = 0;
					else if(R[i].get_y()+1==20) a[2] = 0;
					
					if(R[i].get_y()==R[j].get_y() && R[i].get_x()-1 == R[j].get_x()) a[3] = 0;
					else if(R[i].get_y()==user->get_y() && R[i].get_x()-1 == user->get_x()) a[3] = 0;
					else if(R[i].get_x()-1 < 0) a[3] = 0;
				}
				
				for(int j=0;j<Tiger::num;j++){
					if(R[i].get_y()-1==T[j].get_y() && R[i].get_x() == T[j].get_x()) a[0] = 0;
					
					if(R[i].get_y()==T[j].get_y() && R[i].get_x()+1 == T[j].get_x()) a[1] = 0;
					
					if(R[i].get_y()+1==T[j].get_y() && R[i].get_x() == T[j].get_x()) a[2] = 0;
					
					if(R[i].get_y()==T[j].get_y() && R[i].get_x()-1 == T[j].get_x()) a[3] = 0;
				}
				
				for(int j=0;j<4;j++){
					if(a[j]!=0){
						TorF = 1;
					}
				}
				
				if(TorF!=-1){
					while(1){
						index = rand()%4;
						if(a[index]!=0){
							R[i].move(a[index]);
							break;	
						}
					}
				}
			}
		}
		
		//Eat Grass
		for(int n=0;n<Rabbit::num;n++){
			for(int i=0;i<Grass::num;i++){
				if(R[n]==G[i]){
					R[n].set_life(3);
					while(1){
						G[i].set_pos(rand()%20,rand()%20);
						int inve = 1;
						for(int w=0;w<Rabbit::num;w++){
							if(R[w]==G[i]) inve = -1;
						}
						for(int w=0;w<Tiger::num;w++){
							if(T[w]==G[i]) inve = -1;
						}
						for(int w=0;w<Pit::num;w++){
							if(P[w]==G[i]) inve = -1;
						}
						if(user==G[i]) inve = -1;
						
						if(inve == 1) break;
					}
				}
			}
		}
		
		//The Rabbit falls in hole
		for(int n=0;n<Rabbit::num;n++){
			for(int i=0;i<Pit::num;i++){
				if(R[n]==P[i]){
					for(int j=i;j<Rabbit::num;j++){
						R[j] = R[j+1];
					}
					Rabbit::num--;
					fr++;
				}
			}
		}
		int rabbitb = -1;
		int rabbitn = 0;
		while(rabbitn < Rabbit::num){
			int fie = -1;
			R[rabbitn].survive();
			R[rabbitn].de_life();
			
			//The Rabbit starves
			if(R[rabbitn].get_life() == 0){
				R[rabbitn].set_lifetime(1);
				for(int j=rabbitn;j<Rabbit::num;j++){
					R[j] = R[j+1];
				}
				Rabbit::num--;
				sr++;
				fie = 1;
			}

			//The Rabbit breeds
			if(R[rabbitn].get_lifetime()%3==0){
				int TorF = -1;
				int index;
				int a[4]={1,2,3,4};
				for(int j=0;j<Rabbit::num;j++){
					if(R[rabbitn].get_y()-1==R[j].get_y() && R[rabbitn].get_x() == R[j].get_x()) a[0] = 0;
					else if(R[rabbitn].get_y()-1==user->get_y() && R[rabbitn].get_x() == user->get_x()) a[0] = 0;
					else if(R[rabbitn].get_y()-1 < 0) a[0] = 0;
						
					if(R[rabbitn].get_y()==R[j].get_y() && R[rabbitn].get_x()+1 == R[j].get_x()) a[1] = 0;
					else if(R[rabbitn].get_y()==user->get_y() && R[rabbitn].get_x()+1 == user->get_x()) a[1] = 0;
					else if(R[rabbitn].get_x()+1 ==20) a[1] = 0;
						
					if(R[rabbitn].get_y()+1==R[j].get_y() && R[rabbitn].get_x() == R[j].get_x()) a[2] = 0;
					else if(R[rabbitn].get_y()+1==user->get_y() && R[rabbitn].get_x() == user->get_x()) a[2] = 0;
					else if(R[rabbitn].get_y()+1==20) a[2] = 0;
						
					if(R[rabbitn].get_y()==R[j].get_y() && R[rabbitn].get_x()-1 == R[j].get_x()) a[3] = 0;
					else if(R[rabbitn].get_y()==user->get_y() && R[rabbitn].get_x()-1 == user->get_x()) a[3] = 0;
					else if(R[rabbitn].get_x()-1 < 0) a[3] = 0;
				}
					
				for(int j=0;j<Tiger::num;j++){
					if(R[rabbitn].get_y()-1==T[j].get_y() && R[rabbitn].get_x() == T[j].get_x()) a[0] = 0;
						
					if(R[rabbitn].get_y()==T[j].get_y() && R[rabbitn].get_x()+1 == T[j].get_x()) a[1] = 0;
						
					if(R[rabbitn].get_y()+1==T[j].get_y() && R[rabbitn].get_x() == T[j].get_x()) a[2] = 0;
						
					if(R[rabbitn].get_y()==T[j].get_y() && R[rabbitn].get_x()-1 == T[j].get_x()) a[3] = 0;
				}
					
				for(int j=0;j<4;j++){
					if(a[j]!=0){
							TorF = 1;
					}
				}
					
				if(TorF!=-1){
					while(1){
						index = rand()%4;
						if(a[index]!=0){
							R_breed(R[rabbitn],R[Rabbit::num],a[index]);
							br++;
							break;	
						}
					}
					Rabbit::num++;
					rabbitb = 1;
				}
			}
			
			if(fie==-1) rabbitn++;
		}
		
		for(int rn = 0;rn<Rabbit::num;rn++){
			int ren = -1;
			if(R[rn].get_x() < 0 || R[rn].get_y() < 0){
				for(int n=rn;n<Rabbit::num;n++){
					R[n] = R[n+1];
				}
				Rabbit::num--;
				ren = 1;
			}
			
			if(ren==-1){
				if(R[rn].get_x() > 20 || R[rn].get_y() > 20){
					for(int n=rn;n<Rabbit::num;n++){
						R[n] = R[n+1];
					}
					Rabbit::num--;
					ren = 1;
				}
			}
		}
		if(Rabbit::num%2!=0 && rabbitb==1){
			Rabbit::num--;
		}
		time++;
		system("cls");
	}
}


