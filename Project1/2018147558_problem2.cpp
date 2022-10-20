#include<iostream>

using namespace std;

int main(){
	int a, n=1, c=1, b=0, w=1;
	
	cin >> a; //Get value form user
	
	while(c<a){ //Calculate the number of sides of the square 
		b = b+(w*2);
		w = (2*n)+1;
		c = b+w;
		n++;
	}
	
	int i = (w+1)/2, j = (w+1)/2, m = w, r = w, k = w/2;
	int p = i+1, q = i-1;
	while(j>0){
		r = w;
		while(r>0){
			if(q<r&&r<p) cout << "*"; //Arrange the upper side with respect to the center of the rhombus.
			else cout << "#";
			r--;
		}
		q--;
		p++;
		cout << "\n";
		j--;
	}
	q += 2;
	p -= 2;
	while(k>0){
		m = w;
		while(m>0){
			if(q<m&&m<p) cout << "*"; //Arrange the lower side with respect to the center of the rhombus.
			else cout << "#";
			m--;
		}
		q++;
		p--;
		cout << "\n";
		k--;
	}
	
	
}
