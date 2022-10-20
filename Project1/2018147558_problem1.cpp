#include<iostream>
#include<cmath>


using namespace std;


int ZeroRemove(double value); //Make function to count the decimal point

int main(){
	double a,b,c;
	cin >> a >> b >> c; //Input user data
	double root=(b*b)-(4*a*c); //Calculate the discriminant
	
	
	if(root<0){
		cout << "No real roots" <<endl; //Output result when no real root
	}
	else if(root==0){ 
		double result = -b/(2*a); //Calculate results when you are in the midpoint
		int find = ZeroRemove(result); //Count the decimal point of the result value
		cout << fixed; //Fix decimal point
		cout.precision(find);
		cout << result <<endl; //Output result
		
	}
	else{
		double result1 = (-b+sqrt(root))/(2*a); //Calculate the result when it is no midpoint
		double result2 = (-b-sqrt(root))/(2*a);
		int find1 = ZeroRemove(result1); //Count the decimal point 
		int find2 = ZeroRemove(result2);
		cout << fixed; //Fix decimal point
		if(result1 > result2){
			cout.precision(find1);
			cout << result2 <<", ";
			cout.precision(find2);
			cout << result1 <<endl; //Output result
		}
		else{
			cout.precision(find1);
			cout << result1 <<", ";
			cout.precision(find2);
			cout << result2 <<endl; //Output result
		}
	}
	return 0;
}

int ZeroRemove(double value){
	double first = value, second = value/0.1; //Calculation to Count Decimal Point
	int first1 = value, second1 = value/0.1;
	int x=0,y=1,z=2;
	if(first == first1){
	return x; //return 0
	}

	else{
		if(second == second1){
			return y; //return 1
		}
		else{
			return z; //return 2
		}
	}
}
	



