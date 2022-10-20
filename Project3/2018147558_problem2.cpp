#include<iostream>
#include<string>
using namespace std;

struct ordered{ int MenuName; int num;}; //Create a structure with the name and number of the menu.

class MDS{ //Create a class named MDS
	public:
		static int MDS_num; //Use static to count class number
		static int n;
		MDS(){ //Make constructer
			password = 0;
			charge = 0;
		}
		void set_MDS(int bg,int pw){ //Mutator
			password = pw;
			charge = bg;
			MDS_num++;
		}
		
		void set_bg_to(int bg, int to){ //Mutator
			charge = bg;
			total = to;
		}
		
		void del_menu(int index){ //Delete menu function
			for(index;index<n;index++){
				menu[index-1].MenuName = menu[index].MenuName;
				menu[index-1].num = menu[index].num;
			}
			n--;
		}
		
		void set_menu(int MN, int mn){ //Mutate menu
			menu[n].MenuName = MN;
			menu[n].num = mn;
			n++;
		}
		
		void set_num(int w,int mn){
			menu[w].num = mn;
		}
		
		int Get_charge(){return charge;}                     //Accessor 
		int Get_password(){return password;}                 //
		int Get_total(){return total;}                       //
		int Get_menu_name(int n){return menu[n].MenuName;}   //
		int Get_menu_num(int n){return menu[n].num;}         //
		
		static int Get_num(){ return MDS_num;}
		
	private:
		int password; //Password member variable
		int charge;   //Charge member variable
		ordered menu[100]; //Menu array variable
		int total; //total variable
};
int MDS::MDS_num =0;
int MDS::n = 0;

void sign_up(string name[],MDS user[]);            //Function declaration
void order(string name[],MDS user[]);			   //Function declaration
void order_condition(string name[],MDS user[]);	   //Function declaration
void refund(string name[],MDS user[]);			   //Function declaration
int login(string name[],MDS user[]);               //Function declaration

void show_menu(){ //Print menu function
	cout << "\n----------Mcdonalds Menu ----------" <<endl;
	cout << "1. Hamburger                 - 1000" <<endl;
	cout << "2. Cheeseburger              - 1500" <<endl;
	cout << "3. Big Mac                   - 3000" <<endl;
	cout << "4. Double Quarter Cheese     - 5000" <<endl;
	cout << "5. Fries                     - 1500" <<endl;
	cout << "6. Chicken McNuggets         - 2000" <<endl;
	cout << "7. Quarter Pounder Cheese    - 4000" <<endl;
	cout << "8. Coke                      - 1500" <<endl;
}
void MainMenu(){ //Print main menu function
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

int main(){ //main
	MDS user[100]; //Declare MDS classes for the maximum number of users.
	string name[100];
	
	while(true){
		string menu;
		MainMenu(); 
		cin >> menu;
		
		if(menu.compare("0") == 0){
			cout << "End the program";
			break;
		}
		else if(menu.compare("1")==0) sign_up(name,user);
		else if(menu.compare("2")==0) show_menu();
		else if(menu.compare("3")==0) order(name,user);
		else if(menu.compare("4")==0) order_condition(name,user);
		else if(menu.compare("5")==0) refund(name,user);
		else cout << "Wrong Input" <<endl;
	}
}

void sign_up(string name[],MDS user[]){ //Get ID, password and charge from user, then create class
	string a;
	int pw, bg, TorF;
	
	while(true){
		TorF = 0;
		cout << "Input your ID(0-to main menu) : "; //Get ID 
		cin >> a; 
		
		if(a.compare("0")==0) break;
		if(MDS::Get_num() != 0){  //Duplicate discrimination
			for(int i=0;i<MDS::Get_num();i++){
				if(name[i].compare(a) == 0){
					cout << "Duplicated user" << endl;
					TorF = 1;
				}
			}
		}
		
		if(TorF == 0){
			name[MDS::Get_num()] = a;
			cout << "Input your password : "; //Get password
			cin >> pw;
			cout << "Input your Initial Money: "; //Get charge
			cin >> bg;
			user[MDS::Get_num()].set_MDS(bg,pw);
			cout << "Welcome, "<< a <<endl; 
			break;
		}
	}
}

int login(string name[],MDS user[]){ //login function
	string a;
	int index, pw, TorF = 0;
	
	while(TorF == 0){
		TorF = 0;
		cout << "Input your ID(0-to main menu) : ";
		cin >> a;
		if(a.compare("0")==0) return -1; 
		else{
			for(int i=0;i < MDS::Get_num();i++){
				if(name[i].compare(a)==0){
					index = i;
					TorF = 1;
				}
			}
		}
		if(TorF == 0) cout << "Wrong Input"<<endl;
	}
	
	while(true){
		cout << "Input your password : ";
		cin >> pw;
		
		if(user[index].Get_password() == pw){
			return index;
			break;
		}
		else cout << "The password is incorrect." <<endl;
	}
}

string menu_name(int a){ //Get menu number and return menu name
	switch(a){
		case 1:
			return "Hamburger";
		case 2:
			return "Cheeseburger";
		case 3:
			return "Big Mac";
		case 4:
			return "Double Quarter Cheese";
		case 5:
			return "Fries";
		case 6:
			return "Chicken McNuggets";
		case 7:
			return "Quarter Pounder Cheese";
		case 8:
			return "Coke";
	}
}

int menu_cost(int a){ //Get menu number and return menu cost
	switch(a){
		case 1:
			return 1000;
		case 2:
			return 1500;
		case 3:
			return 3000;
		case 4:
			return 5000;
		case 5:
			return 1500;
		case 6:
			return 2000;
		case 7:
			return 4000;
		case 8:
			return 1500;
	}
}

void order(string name[],MDS user[]){ //Process user order
	int index, OrderNum, num, balance, total, a;
	
	index = login(name,user);			//Save user index
	if(index >= 0){
		balance = user[index].Get_charge(); //Get user balance from class data
		total = user[index].Get_total();	//Get user total from class data
		while(true){
			a=0;
			cout << "\nSelect menu number(0-to main menu) : "; //Get menu number from user
			cin >> OrderNum;
			
			if(OrderNum != 0 && OrderNum>0 && OrderNum <= 8){
				cout << "How many '"<<menu_name(OrderNum)<<"' do you want : ";
				cin >> num; //Get select menu number 
				
				for(int i=0;i<user[index].n;i++){
					if(user[index].Get_menu_name(i) == OrderNum){
						int b = user[index].Get_menu_num(i) + num;
						user[index].set_num(i,b);
						a=1;
					}
				}
				if(balance - menu_cost(OrderNum) * num < 0) cout <<"Over budget"; //Print error code when user overed budget
				else if(balance - menu_cost(OrderNum) * num > 0 && a==0){
				balance -= menu_cost(OrderNum) * num;
				total += menu_cost(OrderNum) * num;
				user[index].set_menu(OrderNum,num);
				}
			}
			else if(OrderNum ==0){ //Output user order history
				for(int j=0;j<user[index].n;j++){
					cout << j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j) << endl;
				}
				
				cout << "\nYour total purchase amount is "<< total <<endl;
				cout << "The balance is "<< balance <<endl;
				cout << "Thanks"<<endl;
				user[index].set_bg_to(balance,total);
				break;
			}
			else cout << "Wrong Input" <<endl;
		}
	}
}

void order_condition(string name[],MDS user[]){ //Output your order history
	int index;
	index = login(name,user);
	if(index >= 0){
		for(int j=0;j<user[index].n;j++){
			cout << "\n"<< j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j);
		}
		
		cout << "\n\nYour total purchase amount is "<<user[index].Get_total()<<endl;
		cout << "The balance is "<<user[index].Get_charge() <<endl;
		cout << "Thanks"<<endl;
	}
}

void refund(string name[],MDS user[]){ //Refund user order
	int index, balance, total, demenu;
	
	index = login(name,user); //login
	if(index >= 0){
		total = user[index].Get_total();
		balance = user[index].Get_charge();
		
		for(int j=0;j<user[index].n;j++){ //Output user current order history
			cout << j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j) << endl;
		}
		
		cout << "\nYour total purchase amount is "<<total<<endl;
		cout << "The balance is "<<balance <<endl;
		
		while(true){
			cout << "\nChoose number(0 - to main menu) : "; //Receive the menu number to delete.
			cin >> demenu;
			
			if(demenu == 0) break;
			else{
				if(demenu <= user[index].n && demenu > 0){
					total -= menu_cost(user[index].Get_menu_name(demenu-1))*user[index].Get_menu_num(demenu-1); //delete menu
					balance += menu_cost(user[index].Get_menu_name(demenu-1))*user[index].Get_menu_num(demenu-1);
					user[index].del_menu(demenu);
				
					cout << "Successfully refunded"<<endl;
					
					for(int j=0;j<user[index].n;j++){   //Print the order history after delete menu
						cout <<"\n"<< j+1 << ". '"<< menu_name(user[index].Get_menu_name(j)) <<"' : " << user[index].Get_menu_num(j);
					}
					cout << "\n\nYour total purchase amount is "<<total<<endl;
					cout << "The balance is "<<balance;     
				}
				else cout << "Wrong Input!"<<endl; //print error code
			}
		}
	}
}
