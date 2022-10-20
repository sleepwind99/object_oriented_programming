#include<iostream>

using namespace std;

int main(){
	
	long long user_num; //Since the condition is 10 power 18, use a datatype greater than int
	int pl, re;
	cin >> user_num; //Get number from user 
	
	while( user_num != 0 ){ //Repeat for the number of digits entered
		pl = user_num%10; //Go sequentially from number of places of work sequentially
		re += pl;
		user_num /= 10;
	}
	cout << re << endl; //Output the result
}
