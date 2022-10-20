#include<iostream>
#include<cmath>
using namespace std;
float max(float user_input[]); //Function declaration that calculates the maximum number received
float min(float user_input[]); //Function declaration that calculates the minimum number received
float avg(float user_input[]); //Function declaration that calculates the average number received
float sum(float user_input[]); //Function declaration that calculates the sum number received

int main(){
	float user_input[10]; //Declare an array to receive 10 numbers for user input
	for(int a=0;a<10;a++) cin >>user_input[a]; //Get user input

	cout << "min: "<< min(user_input) <<endl;
	cout << "max: "<< max(user_input) <<endl;
	cout << "avg: "<< avg(user_input) <<endl;
	cout << "sum: "<< sum(user_input) <<endl;
	
	return 0;
}

float max(float user_input[]){ //Maximum output from user input
	float max = user_input[0];
	for(int a=0;a<10;a++){
		if(user_input[a]>max) max = user_input[a];
	}
	return round(max*100)/100;
}

float min(float user_input[]){ //Minimum output from user input
	float min = user_input[0];
	for(int a=0;a<10;a++){
		if(user_input[a]<min) min = user_input[a];
	}
	return round(min*100)/100;
}

float avg(float user_input[]){ //Average output from user input
	float sum = 0, avg;
	for(int a=0;a<10;a++){
		sum += user_input[a];
	}
	avg = sum/10;
	return round(avg*100)/100;
}

float sum(float user_input[]){ //Sum output from user input
	float sum = 0;
	for(int a=0;a<10;a++){
		sum += user_input[a];
	}
	return round(sum*100)/100;
}
