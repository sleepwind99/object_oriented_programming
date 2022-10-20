#include<iostream>
#include<string>
#include<cstring>
using namespace std;


struct ordered{
	int MenuName;
	int num;
};


class MDS{
	public:
		static int MDS_num;
		int n=0;
		MDS(int pw,int bg){
			password = pw;
			charge = bg;
			MDS_num++;
		}
		MDS(){
			password = 0;
			charge = 0;
		}
		
		void set_ID(char id[]){
			ID = id;
		}
		void set_MDS(int bg,int pw){
			password = pw;
			charge = bg;
			MDS_num++;
		}
		
		void set_bg_bl(int bg, int bl){
			charge = bg;
			balance = bl;
		}
		
		void del_menu(int index){
			for(index;index<n;index++){
				menu[index-1].MenuName = menu[index].MenuName;
				menu[index-1].num = menu[index].num;
			}
			n--;
		}
		
		void set_menu(int MN, int mn){
			menu[n].MenuName = MN;
			menu[n].num = mn;
			n++;
		}
		
		int Get_charge(){return charge;}
		int Get_password(){return password;}
		int Get_balance(){return balance;}
		int Get_menu_name(int n){return menu[n].MenuName;}
		int Get_menu_num(int n){return menu[n].num;}
		char* Get_ID(){return ID;}
		
		static int Get_num(){ return MDS_num;}
		
	private:
		char* ID;
		int password;
		int charge;
		ordered menu[100];
		int balance;
		
};
int MDS::MDS_num =0;

void sign_up(MDS user[]);
void order(MDS user[]);
void order_condition(MDS user[]);
void refund(MDS user[]);
int login(MDS user[]);

void show_menu(){
	cout << "----------Mcdonalds Menu ----------" <<endl;
	cout << "1. Hamburger                 - 1000" <<endl;
	cout << "2. Cheeseburger              - 1500" <<endl;
	cout << "3. Big Mac                   - 3000" <<endl;
	cout << "4. Double Quarter Cheese     - 5000" <<endl;
	cout << "5. Fries                     - 1500" <<endl;
	cout << "6. Chicken McNuggets         - 2000" <<endl;
	cout << "7. Quarter Pounder Cheese    - 4000" <<endl;
	cout << "8. Coke                      - 1500" <<endl;
}

void MainMenu(){
	cout << "-----------------------------------" <<endl;
	cout << "-----Mcdonalds Delivery System-----" <<endl;
	cout << "-----------------------------------" <<endl;
	cout << "\n";
	cout << "1. Sign up" <<endl;
	cout << "2. Show Menu" <<endl;
	cout << "3. Order" <<endl;
	cout << "4. Order condition" <<endl;
	cout << "5. Refund" <<endl;
	cout << "0. Exit" <<endl;
	cout << "Select -> ";
}

int main(){
	MDS user[100];
	while(true){
		int menu;
		MainMenu();
		cin >> menu;
		if(menu == 6){
			cout << "End the program";
			break;
		}
		switch(menu){
			case 1: 
				sign_up(user);
				break;
			case 2:
				show_menu();
				break;
			case 3:
				order(user);
				break;
			case 4:
				order_condition(user);
				break;
			case 5:
				refund(user);
				break;
			default:
				cout << "Wrong Input"<<endl;
		}
	}
}

void sign_up(MDS user[]){
	char a[10];
	int TorF;
	int pw, bg;
	while(true){
		TorF = 0;
		cout << "Input your ID(0-to main menu) : ";
		cin >> a; 
		if(MDS::Get_num() != 0){
			for(int i=0;i<MDS::Get_num();i++){
				cout << user[i].Get_ID() << endl;
				if(strcmp(user[i].Get_ID(),a) == 0){
					cout << "Duplicated user" << endl;
					TorF = 1;
				}
			}
		}
		if(TorF == 0){
		user[MDS::Get_num()].set_ID(a);
		cout << "Input your password : ";
		cin >> pw;
		cout << "Input your Initial Money: ";
		cin >> bg;
		user[MDS::Get_num()].set_MDS(bg,pw);
		cout << "Welcome, "<< a <<endl;
		break;
		}
	}

}

int login(MDS user[]){
	char a[10];
	int index, pw;
	cout << "Input your ID(0-to main menu) : ";
	cin >> a;
	
	for(int i=0;i < MDS::Get_num();i++){
		if(strcmp(user[i].Get_ID(),a)==0){
			index = i;
		}
	}
	
	cout << "Input your password : ";
	cin >> pw;
	if(user[index].Get_password() == pw){
		return index;
	}
	else cout << "The password is incorrect." <<endl;
}

string menu_name(int a){
	switch(a){
		case 1:
			return "Hamburger";
			break;
		case 2:
			return "Cheeseburger";
			break;
		case 3:
			return "Big Mac";
			break;
		case 4:
			return "Double Quarter Cheese";
			break;
		case 5:
			return "Fries";
			break;
		case 6:
			return "Chicken McNuggets";
			break;
		case 7:
			return "Quarter Pounder Cheese";
			break;
		case 8:
			return "Coke";
			break;
		default:
			cout << "Wrong Input"<<endl;
			break;
	}
}

int menu_cost(int a){
	switch(a){
		case 1:
			return 1000;
			break;
		case 2:
			return 1500;
			break;
		case 3:
			return 3000;
			break;
		case 4:
			return 5000;
			break;
		case 5:
			return 1500;
			break;
		case 6:
			return 2000;
			break;
		case 7:
			return 4000;
			break;
		case 8:
			return 1500;
			break;
		default:
			cout << "Wrong Input"<<endl;
			break;
	}
}

void order(MDS user[]){
	int index, OrderNum, num, balance = 0, total;
	index = login(user);
	total = user[index].Get_charge();
	while(true){
		
		cout << "\nSelect menu number(0-to main menu) : ";
		cin >> OrderNum;
		
		if(OrderNum != 0){
			cout << "How many '"<<menu_name(OrderNum)<<"' do you want : ";
			cin >> num;
		}
		else{
			for(int j=0;j<user[index].n;j++){
				cout << j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j) << endl;
				if(total < menu_cost(user[index].Get_menu_name(j))*user[index].Get_menu_num(j)){
					cout << "Over budget"<<endl;
				}
				else{
					total -= menu_cost(user[index].Get_menu_name(j)) * user[index].Get_menu_num(j);
					balance += menu_cost(user[index].Get_menu_name(j)) * user[index].Get_menu_num(j);
				}
				
			}
			cout << "\nYour total purchase amount is "<<total<<endl;
			cout << "The balance is "<<balance <<endl;
			cout << "Thanks"<<endl;
			user[index].set_bg_bl(total,balance);
			break;
			
		}
		user[index].set_menu(OrderNum,num);
	
	}
}

void order_condition(MDS user[]){
	int index;
	index = login(user);
	
	for(int j=0;j<user[index].n;j++){
		cout << "\n"<< j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j);
	}
	cout << "\n\nYour total purchase amount is "<<user[index].Get_charge()<<endl;
	cout << "The balance is "<<user[index].Get_balance() <<endl;
	cout << "Thanks"<<endl;
}

void refund(MDS user[]){
	int index, balance, total, demenu;
	index = login(user);
	total = user[index].Get_charge();
	balance = user[index].Get_balance();
	
	for(int j=0;j<user[index].n;j++){
		cout << j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j) << endl;
	}
	cout << "\nYour total purchase amount is "<<total<<endl;
	cout << "The balance is "<<balance <<endl;
	while(true){
		cout << "\nChoose number(0 - to main menu) : ";
		cin >> demenu;
		if(demenu == 0) break;
		else{

			if(demenu <= user[index].n && demenu > 0){
				total += menu_cost(user[index].Get_menu_name(demenu))*user[index].Get_menu_num(demenu);
				balance -= menu_cost(user[index].Get_menu_name(demenu))*user[index].Get_menu_num(demenu);
				user[index].del_menu(demenu);
			
				cout << "Successfully refunded"<<endl;
				
				for(int j=0;j<user[index].n;j++){
					cout <<"\n"<< j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j);
				}
				cout << "\n\nYour total purchase amount is "<<total<<endl;
				cout << "The balance is "<<balance;
			}
			else cout << "Wrong Input!"<<endl;
		}
	}
}