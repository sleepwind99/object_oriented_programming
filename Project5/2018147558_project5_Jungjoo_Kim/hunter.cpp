#include "hunter.h"
#include<string>
#include<iostream>
using namespace std;

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

void Hunter::use_potion(){ //use potion function
	string use;
	while(true){
		cout << "Are you going to use potion( Yes: 'y', No: 'n' ) : "; //get whether or not to be used
		cin >> use;
		if(use.compare("y")==0){
			if(potion==0) {
				cout << "You are consume all of the potion!" <<endl; //if potion not exists.
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
			cout << "Worng Input!"<<endl; //error message
		}
	}
}

void Hunter::move(){
	string moving;
	while(1){
		cout << "Input the moving direction( Up: 'w', Down: 's', Left: 'a', Right: 'd' ): "; //get direction from the user
		cin >> moving;
		if(moving.compare("w")==0){
			if(y_pos-1 < 0) cout << "You don't move that direction!" <<endl; //error message
			else{
				y_pos--;
				break;
			}
		}
		else if(moving.compare("d")==0){
			if(x_pos+1 > 19) cout << "You don't move that direction!" <<endl; //error message
			else{
				x_pos++;
				break;
			}
		}
		else if(moving.compare("s")==0){
			if(y_pos+1 > 19) cout << "You don't move that direction!" <<endl; //error message
			else{
				y_pos++;
				break;
			}
		}
		else if(moving.compare("a")==0){
			if(x_pos-1 < 0) cout << "You don't move that direction!" <<endl; //error message
			else{
				x_pos--;
				break;
			}
		}
		else if(moving.compare("wd")==0){
			if(y_pos-1 < 0 || x_pos+1 > 19) cout << "You don't move that direction!" <<endl; //error message
			else{
				y_pos-=1;
				x_pos+=1;
				break;
			}
		}
		else if(moving.compare("wa")==0){
			if(y_pos-1 < 0 || x_pos-1 < 0) cout << "You don't move that direction!" <<endl; //error message
			else{
				y_pos-=1;
				x_pos-=1;
				break;
			}
		}
		else if(moving.compare("sd")==0){
			if(y_pos+1 > 19 || x_pos+1 > 19) cout << "You don't move that direction!" <<endl; //error message
			else{
				y_pos+=1;
				x_pos+=1;
				break;
			}
		}
		else if(moving.compare("sa")==0){
			if(y_pos+1 > 19 || x_pos-1 < 0) cout << "You don't move that direction!" <<endl; //error message
			else{
				y_pos+=1;
				x_pos-=1;
				break;
			}
		}
		else cout << "Wrong Input" <<endl; //error message
	}
}
