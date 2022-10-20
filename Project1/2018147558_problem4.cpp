#include<iostream>

using namespace std;
int year, month, day;
int CountingDate(int year,int month,int day,int value,int *a,int *b,int *c);
//Declare to use the function created below.
//Use pointers to return multiple variables from a function.

int main(){
	int i, j, k, oneY,oneM,oneD,twoY,twoM,twoD,threeY,threeM,threeD; 
	//Declare variables to calculate 100 days, 200 days, and 300 days.
	cin >> i >> j >> k; //Get date from user
	CountingDate(i,j,k,100,&oneY,&oneM,&oneD); //Use the CountigDate function to get 100 days later.
	cout <<"100: "<< oneY<<" "; //Output the result according to the given condition.
	cout.width(2);
	cout.fill('0');
	cout << oneM;
	cout << " ";
	cout.width(2);
	cout.fill('0');
	cout << oneD << endl;
	
	CountingDate(i,j,k,200,&twoY,&twoM,&twoD); //Use the CountigDate function to get 200 days later.
	cout <<"200: "<< twoY <<" "; //Output the result according to the given condition.
	cout.width(2);
	cout.fill('0');
	cout << twoM;
	cout << " ";
	cout.width(2);
	cout.fill('0');
	cout <<twoD << endl;
	
	CountingDate(i,j,k,300,&threeY,&threeM,&threeD); //Use the CountigDate function to get 300 days later.
	cout <<"300: "<< threeY <<" "; //Output the result according to the given condition.
	cout.width(2); 
	cout.fill('0');
	cout << threeM;
	cout << " ";
	cout.width(2);
	cout.fill('0');
	cout << threeD << endl;
	
	return 0;
}

//Create a function that calculates the date.
CountingDate(int year,int month,int day,int value,int *a,int *b,int *c){
	int n = day + value - 1; //The entire date is called n.
	
	while(n>31){ 
		/*The maximum day of the month is 31 days 
		and the month and year are counted according to the day.*/
		if(month==1||month==3||month==5||month==7||month==8||month==10){
			n = n-31;
			month++;
		}
		else if(month==2 && year%4 != 0 && year%100 !=0){
			n = n-28;
			month++;
		}
		else if(month==2 && year%4 == 0 && year%100 ==0){
			n = n-28;
			month++;
		}
		else if(month==2 && year%4 == 0 && year%400 ==0 && year%100 !=0){
			n = n-29;
			month++;
		}
		else if(month==12){
			n = n-31;
			month = 1;
			year++;
		}
		else {
			n=n-30;
			month++;
		}
	}
	
	if(n==29){
		//Calculate exceptions when the date is 29 days.
		if(month==2 && year%4 ==0){
			n = n-28;
			month++;
		}
		else{
			*a = year;
			*b = month;
			*c = n;
		}
	}
	
	else if(n==30){
		//Calculate exceptions when the date is 30 days.
		if(month==2 && year%4 != 0){
			n = n-29;
			month++;
		}
		else if(month=2 && year%4 ==0){
			n = n-28;
			month++;
		}
		else {
			*a = year;
			*b = month;
			*c = n;
		}
	}
	
	else if(n==31){
		//Calculate exceptions when the date is 31 days.
		if(month==2 && year%4 != 0){
			n = n-29;
			month++;
		}
		else if(month==2 && year%4 ==0){
			n = n-28;
			month++;
		}
		else if(month==4||month==6||month==9||month==11){
			n = n-30;
			month++;
		}
		else {
			*a = year;
			*b = month;
			*c = n;
		}
	}
	
	else {
			//Calculate when the date of the exception is not.
			*a = year;
			*b = month;
			*c = n;
		}
	
	
}

