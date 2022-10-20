#include<iostream>
#include<cmath>

using namespace std;

int BinaryToDecimal(char user_input[],int bnl,char eoro,int count); //Create a function that converts binary numbers to decimal numbers.

int main(){
	char user_input[105], eoro; //Declare the maximum number of arrays the user can enter
	int count=0, bnl, decimal;
	
	cin >> user_input; //Get user input
	
	while(1){ //Count the number of arrays user has inputed.
		if(user_input[count] == NULL) break; 
		else count++;
	}
	
	if(count<13) { //When the number of binary digits is less than 10
		bnl = user_input[0]-48;
		eoro = user_input[count-1];
		decimal = BinaryToDecimal(user_input, bnl, eoro, count);
		cout << decimal << endl;
	}
	else { //When the number of binary numbers is 10 or more
		bnl = (user_input[0]-48)*10+(user_input[1]-48);
		eoro = user_input[count-1];
		decimal = BinaryToDecimal(user_input, bnl, eoro, count);
		cout << decimal << endl;
	}
		
}

int BinaryToDecimal(char user_input[],int bnl,char eoro,int count){
	/*It is converted to decimal number by information of binary number 
	and binary number entered by the user and returned */
	int a=1,num = count-bnl, result=0; 
	while(count > num){
		if(user_input[count-2] == 49 ) result += pow(2,a);
		a++;
		count--;
	}
	if(eoro == 101) result++;
	return result;
}




