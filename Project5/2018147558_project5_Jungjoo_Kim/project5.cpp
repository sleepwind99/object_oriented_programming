#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include "critter.h"
#include "grass.h"
#include "hunter.h"
#include "pit.h"
#include "rabbit.h"
#include "tiger.h"

using namespace std;

int CharToInt(){ //get string and return integer
	char c[4];
	cin >> c;
	int arr_num = 0, int_num = 0, square = 0;

	for (int i = 0; i < 3; i++) {
		if (c[i] < 48 || c[i]>57) {
			if (c[i] > 0 && c[i] < 48) return -1;
			else if (c[i] > 57) return -1;
		}
		else arr_num++;
	}
	for (int i = arr_num - 1; i >= 0; i--) {
		int_num += (c[i] - 48)*pow(10, square);
		square++;
	}
	return int_num;
}

bool operator ==(const Hunter* H,const Tiger& T){return H->get_x()==T.get_x() && H->get_y()==T.get_y();} 	//bool overloading
bool operator ==(const Hunter* H,const Rabbit& R){return H->get_x()==R.get_x() && H->get_y()==R.get_y();} 	//
bool operator ==(const Tiger& T,const Rabbit& R){return T.get_x()==R.get_x() && T.get_y()==R.get_y();}		//
bool operator ==(const Rabbit& R,const Grass& G){return R.get_x()==G.get_x() && R.get_y()==G.get_y();}		//
bool operator ==(const Hunter* H,const Grass& G){return H->get_x()==G.get_x() && H->get_y()==G.get_y();}	//
bool operator ==(const Tiger& T,const Grass& G){return T.get_x()==G.get_x() && T.get_y()==G.get_y();}		//
bool operator ==(const Pit& P,const Grass& G){return P.get_x()==G.get_x() && P.get_y() ==G.get_y();}		//
bool operator ==(const Hunter* H,const Pit& P){return H->get_x()==P.get_x() && H->get_y()==P.get_y();}		//
bool operator ==(const Rabbit& R,const Pit& P){return R.get_x()==P.get_x() && R.get_y()==P.get_y();}		//
bool operator ==(const Tiger& T,const Pit& P){return T.get_x()==P.get_x() && T.get_y()==P.get_y();}			//

void R_breed(Rabbit& PR,Rabbit& CR,int a){ //Rabbit breed function
	if(a==1) CR = Rabbit(PR.get_x(),PR.get_y()-1);
	else if(a==2) CR = Rabbit(PR.get_x()+1,PR.get_y());
	else if(a==3) CR = Rabbit(PR.get_x(),PR.get_y()+1);
	else CR = Rabbit(PR.get_x()-1,PR.get_y());
	CR.set_lifetime(0);
}

void T_breed(Tiger& PT,Tiger& CT,int a){ //Tiger breed function 
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
	char demention[10][10];
	while(1){
		while(1){
			cout << "Enter initial number of rabbits : ";
			r = CharToInt(); //get rabbits number
			if(r!=-1) break;
		}
		while(1){
			cout << "Enter initial number of tigers : ";
			t = CharToInt(); //get tigers number
			if(t!=-1) break;
		}
		while(1){
			cout << "Enter initial number of grasses : ";
			g = CharToInt(); //get grasses number
			if(g!=-1) break;
		}
		while(1){
			cout << "Enter initial number of pits : ";
			h = CharToInt(); //get pits number
			if(h!=-1) break;
		}
		while(1){
			cout << "Enter initial number of potions : ";
			p = CharToInt(); //get potions number
			if(p!=-1) break;
		}
		total = r+t+h+g+1;
		if(total > 100) cout << "Total input over the maximun(400)!" <<endl; //error message
		else break;
	}
	R = new Rabbit[r * 2];
	Rabbit::num /= 2;
	T = new Tiger[t * 2];
	Tiger::num /= 2;
	G = new Grass[g];
	P = new Pit[h];
	user = new Hunter;
	user->set_potion(p);
	x = new int[total];
	y = new int[total];
	srand(time(0));
	
	for(int i=0;i<total;i++){ //Random Number Generation
		x[i]=rand()%10;
		y[i]=rand()%10;
	}

	TorF = -1;
	while(TorF == -1){ //Processing of overlapping numbers coordinates
		TorF = 0;
		for(int i=0;i<total;i++){
			for(int j=i+1;j<total;j++){
				if(x[i]==x[j] && y[i]==y[j]){
					x[j] = rand()%10;
					y[j] = rand()%10;
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
	
	while(1){ //the main body of a game
		//information or hunter prints
		cout << "Time step: " << time <<endl;
		cout << "<Score:" <<user->get_score()<<", HP:"<<user->get_life()<<", Potions:"<<user->get_potion() <<">"<<endl<<endl;
		//Print board
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
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
		
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cout <<demention[j][i]<<" ";
			}
			cout << "\n";
		}
		//Printing information about game progress
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
		user->move(); //hunter move
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
					else if(T[i].get_x()+1 ==10) a[1] = 0;
					
					if(T[i].get_y()+1==T[j].get_y() && T[i].get_x() == T[j].get_x()) a[2] = 0;
					else if(T[i].get_y()+1==user->get_y() && T[i].get_x() == user->get_x()) a[2] = 0;
					else if(T[i].get_y()+1==10) a[2] = 0;
					
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
			if(T[tigern].get_lifetime()%4 == 0 && T[tigern].get_lifetime() != 0){
					int TorF = -1;
					int index;
					int a[4]={1,2,3,4};
			
				for(int j=0;j<Tiger::num;j++){
					if(T[tigern].get_y()-1==T[j].get_y() && T[tigern].get_x() == T[j].get_x()) a[0] = 0;
					else if(T[tigern].get_y()-1==user->get_y() && T[tigern].get_x() == user->get_x()) a[0] = 0;
					else if(T[tigern].get_y()-1<0) a[0] = 0;
						
					if(T[tigern].get_y()==T[j].get_y() && T[tigern].get_x()+1 == T[j].get_x()) a[1] = 0;
					else if(T[tigern].get_y()==user->get_y() && T[tigern].get_x()+1 == user->get_x()) a[1] = 0;
					else if(T[tigern].get_x()+1==10) a[1] = 0;
						
					if(T[tigern].get_y()+1==T[j].get_y() && T[tigern].get_x() == T[j].get_x()) a[2] = 0;
					else if(T[tigern].get_y()+1==user->get_y() && T[tigern].get_x() == user->get_x()) a[2] = 0;
					else if(T[tigern].get_y()+1==10) a[2] = 0;
						
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
				}
			}
			if(fie == -1) tigern++;
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
					else if(R[i].get_x()+1 ==10) a[1] = 0;
					
					if(R[i].get_y()+1==R[j].get_y() && R[i].get_x() == R[j].get_x()) a[2] = 0;
					else if(R[i].get_y()+1==user->get_y() && R[i].get_x() == user->get_x()) a[2] = 0;
					else if(R[i].get_y()+1==10) a[2] = 0;
					
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
						G[i].set_pos(rand()%10,rand()%10);
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
			if(R[rabbitn].get_lifetime()%3==0 && R[rabbitn].get_lifetime()!=0){
				int TorF = -1;
				int index;
				int a[4]={1,2,3,4};
				for(int j=0;j<Rabbit::num;j++){
					if(R[rabbitn].get_y()-1==R[j].get_y() && R[rabbitn].get_x() == R[j].get_x()) a[0] = 0;
					else if(R[rabbitn].get_y()-1==user->get_y() && R[rabbitn].get_x() == user->get_x()) a[0] = 0;
					else if(R[rabbitn].get_y()-1 < 0) a[0] = 0;
						
					if(R[rabbitn].get_y()==R[j].get_y() && R[rabbitn].get_x()+1 == R[j].get_x()) a[1] = 0;
					else if(R[rabbitn].get_y()==user->get_y() && R[rabbitn].get_x()+1 == user->get_x()) a[1] = 0;
					else if(R[rabbitn].get_x()+1 ==10) a[1] = 0;
						
					if(R[rabbitn].get_y()+1==R[j].get_y() && R[rabbitn].get_x() == R[j].get_x()) a[2] = 0;
					else if(R[rabbitn].get_y()+1==user->get_y() && R[rabbitn].get_x() == user->get_x()) a[2] = 0;
					else if(R[rabbitn].get_y()+1==10) a[2] = 0;
						
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
					
				if(TorF==1){
					while(1){
						index = rand()%4;
						if(a[index]!=0){
							R_breed(R[rabbitn],R[Rabbit::num],a[index]);
							br++;
							break;	
						}
					}
				}
			}
			if(fie==-1) rabbitn++;
		}
		
		time++; //Number of games increased
		system("cls"); // Erase Board
	}
}
