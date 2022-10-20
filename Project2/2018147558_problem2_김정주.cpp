#include <iostream>
#include <string>
using namespace std;
void print_seat_state(int first,int business,int economy){ //Display the number and alignment of the digits on the screen
	cout << "##########current vacant seats#########"<<endl;
	cout << "first class: "<<5-first<<"/5"<<endl;
	cout << "business class: "<<25-business<<"/25"<<endl;
	cout << "economy class: "<<50-economy<<"/50"<<endl;
	cout << "#############first class##############"<<endl;
	for(int a=1;a<6;a++){ //Number of seats in the first class
		if(first>0) cout<<"X";
		else cout<<"O";
		first--;
	}
	cout<<"\n";
	
	cout << "#############business class###########"<<endl;
	for(int a=1;a<26;a++){//Number of places in business class
		if(business>0 && a%5!=0) cout<<"X";
		else if(business<=0 && a%5 !=0) cout<<"O";
		else if(business>0 && a%5 == 0) cout<<"X\n";
		else if(business<=0 && a%5 == 0) cout<<"O\n";
		business--;
	}
	
	cout << "#############economy class############"<<endl;
	for(int a=1;a<51;a++){//Number of places in economy class
		if(economy>0 && a%5!=0) cout<<"X";
		else if(economy<=0 && a%5 !=0) cout<<"O";
		else if(economy>0 && a%5 == 0) cout<<"X\n";
		else if(economy<=0 && a%5 == 0) cout<<"O\n";
		economy--;
	}
	
}

void add_passenger(int& first,int& business,int& economy){ //Functions when adding passengers
	int passenger; 
	char demenu;//Detail menu
	cout << "Which type seat do you want add?";
	cout << "(first class: 1, business_class: 2, economy_class: 3):";
	cin >> demenu; 
	
	switch(demenu){
		case '1': //Whem first class
			cout << "How many passenger would you like to add?:";
			cin >> passenger;
			if(first+passenger<=5){
				first += passenger;
				cout << "Add Complete!"<<endl;
			}
			else cout << "full seat!" <<endl; //Outputs when the user's input exceeds the maximum seat
			break;
		case '2': // When business class
			cout << "How many passenger would you like to add?:";
			cin >> passenger;
			if(business+passenger<=25){
				business += passenger;
				cout << "Add Complete!"<<endl;
			}
			else cout << "full seat!" <<endl; //Outputs when the user's input exceeds the maximum seat
			break;
		case '3': // When economy class
			cout << "How many passenger would you like to add?:";
			cin >> passenger;
			if(economy+passenger<=50){
				economy += passenger;
				cout << "Add Complete!"<<endl; 
			}
			else cout << "full seat!" <<endl; //Outputs when the user's input exceeds the maximum seat
			break;
		default:
				cout<<"Wrong Input!"<<endl;
	}
}

void delete_passenger(int& first,int& business,int& economy){ //Functions for deleting passengers
	int passenger;
	char demenu; // Detail menu
	cout << "Which type seat do you want delete?";
	cout << "(first class: 1, business_class: 2, economy_class: 3):";
	cin >> demenu;
	
	switch(demenu){
		case '1': //Whem first class
			cout << "How many passenger would you like to delete?:";
			cin >> passenger;
			if(first-passenger>=0){
				first -= passenger;
				cout << "Delete Complete!"<<endl;
			}
			else cout << "Wrong Input!" <<endl; //Error output when user input exceeds maximum value
			break;
		case '2': // When business class
			cout << "How many passenger would you like to delete?:";
			cin >> passenger;
			if(business-passenger>=0){
				business -= passenger;
				cout << "Delete Complete!"<<endl;
			}
			else cout << "Wrong Input!" <<endl; //Error output when user input exceeds maximum value
			break;
		case '3': // When economy class
			cout << "How many passenger would you like to delete?:";
			cin >> passenger;
			if(economy-passenger>=0){
				economy -= passenger;
				cout << "Delete Complete!"<<endl;
			}
			else cout << "Wrong Input!" <<endl; //Error output when user input exceeds maximum value
			break;
		default:
				cout<<"Wrong Input!"<<endl;
	}
}


void welcome(){ //Specify information for users to use the program
cout <<"#######################################" <<endl;
cout <<"#######Flight Reservation System#######" <<endl;
cout <<"#######################################" <<endl;
cout <<"#########1. add passenger##############" <<endl;
cout <<"#########2. delete passenger###########" <<endl;
cout <<"#########3. print seat state###########" <<endl;
cout <<"#########4. exit#######################" <<endl;
cout <<"#######################################" <<endl;
}

int main(){ //main function

	int first_class = 0;
	int business_class = 0; 
	int economy_class = 0; 

	while(true){
		welcome();
		char menu;
		cin >> menu; // Set the menu as described above
		switch(menu){
			case '1':
				add_passenger(first_class, business_class, economy_class);
				break;
			case '2':
				delete_passenger(first_class, business_class, economy_class);
				break;
			case '3':
				print_seat_state(first_class, business_class, economy_class);
				break;
			case '4':
				cout<< "end the program"<<endl;
				return 0;
			default:
				cout<<"Wrong Input!"<<endl;
		}
	}
}
