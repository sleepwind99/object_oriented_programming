#include<iostream>
using namespace std;

int main(){
	int n, i=0, j=0, score_a = 0, score_b = 0;
	cin >> n;
	int user_a[n], user_b[n];
	for(int a=0; a<n;a++) cin >> user_a[a]; //Get user_a's number
	for(int a=0; a<n;a++) cin >> user_b[a]; //Get user_b's number
	while(i!=n && j!=n){
	
		if(user_a[i] > user_b[j]){ //When user_a wins
			score_a++;
			user_a[i] -= user_b[j];
			j++;
		}
		else if(user_a[i] == user_b[j]){ //If the numbers of user_a and user_b are the same
			i++;
			j++;
		}
		else{ //When user_b wins
			score_b++;
			user_b[j] -= user_a[i]; 
			i++;
		}
	}
	cout<< score_a <<" "<<score_b<<endl; //Output final score of user_a and user_b
}
