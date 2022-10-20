#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int Oc = 0; //Distinguish Octal and Hexadecimal
const int He = 1; //

int convertor(char a){ //Converte Octal or Hexadecimal to decimal
	char taxt[17] = "0123456789ABCDEF"; //All hexadecimal and octal elements
	for(int i=0;i<17;i++){
		if(a == taxt[i]) return i; //return decimal number
	}
}

int decimal(char arr[],int type){ //Converte decimal to Octal or Hexadecimal
	int n =0, result =0,k;
	for(int i=0;i<5;i++){
		if(arr[i] != 111 && arr[i]!=0) n++; //Count number of array
	}
	k=n-1;
	if(type == Oc){ //Converte decimal to octal
		for(int i=0;i<n;i++){
			result += convertor(arr[i])*pow(8,k);
			k--;
		}
		return result;
	}
	else if(type == He){ //Converte decimal to hexadecimal
		for(int i=0;i<n;i++){
			result += convertor(arr[i])*pow(16,k);
			k--;
		}
		return result;
	}
}


class Calculator{ //Calculator class
public:
	Calculator();
	Calculator(char a[],char form);
	void setNum(char arr[], int size, char type);
	void output() const; //output num member variable
	friend const Calculator operator+(const Calculator& ref1, const Calculator& ref2);
	friend const Calculator operator-(const Calculator& ref1, const Calculator& ref2);
	friend const bool operator>(const Calculator& ref1, const Calculator& ref2);
	friend const bool operator<(const Calculator& ref1, const Calculator& ref2);
	friend const bool operator==(const Calculator& ref1, const Calculator& ref2);
	friend ostream& operator <<(ostream & outputStream, const Calculator& ref);
private:
	char num[10];
	char type; //composition type
};

Calculator::Calculator(){ //constructor
	for(int i=0;i<10;i++){ 
		num[i] = '0';
	}
	type = 'O';
}

Calculator::Calculator(char a[],char form){ //constructor
	for(int i=0;i<10;i++){
		num[i] = a[i];
	}
	type = form;
}

void Calculator::setNum(char arr[],int size, char form){ //mutator
	for(int i=0;i<size;i++){
		num[i] = arr[i];
	}
	type = form;
}

void Calculator::output() const{ //member variable num output function
	for(int i=0;i<10;i++){
		cout << num[i];
	}
	cout << "\n";
}

int menu(){
	while(true){
		string num;
		cout << "===============Menu===============\n" //output menu
		<<"1:Program start 0:program End\n"
		<<"Menu Option: ";
		cin >> num; //Get menu num
		if(num.compare("0")==0){ //exit program
			cout << "Exit the program" << endl;
			return -1;
		}
		else if(num.compare("1")==0){ //Run the rest of the program
			cout << "Welcome to Calculator!" <<endl;
			return 1;
		}
		cout << "Wrong Input!"<<endl; //output error messages
	}
}

void Octal(){
	char n1[6], n2[6]; //number's length
	int TrueOfFalse; //distinction integar
	while(true){
		TrueOfFalse = -1;
		cout << "Input num1: ";
		cin >> n1; //Get num1
		for(int i=0;i<6;i++){ 
			if(n1[i]<48 || n1[i]>=56){
				if(n1[i]!=0 && n1[i]!=111) TrueOfFalse =0; //It is determined according to given conditions.
			}
		}
		if(TrueOfFalse==-1) break;
		else cout << "Wrong Input!" <<endl; //output error messages
	}
	while(true){
		TrueOfFalse = -1;
		cout << "Input num2: ";
		cin >> n2; //Get num2
		for(int i=0;i<6;i++){
			if(n2[i]<48 || n2[i]>=56){
				if(n2[i]!=0 && n2[i]!=111) TrueOfFalse =0; //It is determined according to given conditions.
			}
		}
		if(TrueOfFalse==-1) break;
		else cout << "Wrong Input!" <<endl; //output error messages
	}
	Calculator num1(n1,'O'); //Declare a class called num1 whose type is octal.
	Calculator num2(n2,'O'); //Declare a class called num2 whose type is octal.
	cout << "1. num1 + num2 : ";
	(num1+num2).output(); //Executes and prints +operator overloading.
	cout << "2. num1 - num2 : ";
	(num1-num2).output(); //Executes and prints -operator overloading.
	cout << "3. num1 == num2 : "; //Executes and prints ==operator overloading.
	if(num1==num2) cout << "true" <<endl;
	else cout << "false" <<endl;
	cout << "4. num1 > num2 : "; //Executes and prints >operator overloading.
	if(num1>num2) cout << "true" <<endl;
	else cout << "false" <<endl;
	cout << "5. num1 < num2 : "; //Executes and prints <operator overloading.
	if(num1<num2) cout << "true" <<endl;
	else cout << "false" <<endl;
	cout << "6. num1: " << num1 <<" num2: " << num2 <<endl; //Executes and prints <<operator overloading.
}

void Hexadecimal(){
	char n1[6], n2[6]; //number's length
	int TrueOrFalse; //distinction integar
	while(true){
		TrueOrFalse = -1;
		cout << "Input num1: ";
		cin >> n1; //get num1
		for(int i=0;i<6;i++){
			if(n1[i]<48 || n1[i]>57){
				if(n1[i]<65 || n1[i]>70){
					if(n1[i]!=0) TrueOrFalse=0; //It is determined according to given conditions
				}
			}
		}
		if(TrueOrFalse==-1) break;
		else cout << "Wrong Input!" <<endl;
	}
	while(true){
		TrueOrFalse = -1;
		cout << "Input num2: ";
		cin >> n2; //get num2
		for(int i=0;i<6;i++){
			if(n2[i]<48 || n2[i]>57){
				if(n2[i]<65 || n2[i]>70){
					if(n2[i]!=0) TrueOrFalse=0; //It is determined according to given conditions.
				}
			}
		}
		if(TrueOrFalse==-1) break;
		else cout << "Wrong Input!" <<endl;
	}
	Calculator num1(n1,'H'); //Declare a class called num1 whose type is Hexadecimal.
	Calculator num2(n2,'H'); //Declare a class called num1 whose type is Hexadecimal.
	cout << "1. num1 + num2 : ";
	(num1+num2).output(); //Executes and prints +operator overloading.
	cout << "2. num1 - num2 : ";
	(num1-num2).output(); //Executes and prints -operator overloading.
	cout << "3. num1 == num2 : "; //Executes and prints ==operator overloading.
	if(num1==num2) cout << "true" <<endl; 
	else cout << "false" <<endl; 
	cout << "4. num1 > num2 : "; //Executes and prints >operator overloading.
	if(num1>num2) cout << "true" <<endl;
	else cout << "false" <<endl;
	cout << "5. num1 < num2 : "; //Executes and prints <operator overloading.
	if(num1<num2) cout << "true" <<endl;
	else cout << "false" <<endl;
	cout << "6. num1: " << num1 <<" num2: " << num2 <<endl; //Executes and prints <<operator overloading.
}

int main(){
	int mean; 
	while(true){
		mean=menu();
		if(mean==-1) break; //call a function that displays the menu.
		string OctalOrHexad; //string to distinguish between octal and hexadecimal
		while(true){
			cout << "Select the Calculator(Octal calculator(O) Hexadecimal calculator(H)) : ";
			cin >> OctalOrHexad;
			if(OctalOrHexad.compare("O")==0){
				Octal(); //call Octal function
				break;
			}
			else if(OctalOrHexad.compare("H")==0){
				Hexadecimal(); // call hexadecimal function
				break;
			}
			else cout << "Wrong Input!" <<endl; //output error messages
		}
	}
}

const Calculator operator+(const Calculator& num1, const Calculator& num2){  
	//Converts octal and hexadecimal characters to hexadecimal, 
	//adds them, and then converts them back to octal or hexadecimal.
	int i=0 ,k=0, dec_ref;
	char text[17] = "0123456789ABCDEF", result[10], arr_ref1[10], arr_ref2[10], con[10];
	
	for(int i=0;i<10;i++){ //copy array
		arr_ref1[i] = num1.num[i];
		arr_ref2[i] = num2.num[i];
	}
	
	if(num1.type =='O'){ //when type is octal
		dec_ref = decimal(arr_ref1,0)+decimal(arr_ref2,0);
		while(dec_ref!=0){
			con[i] = text[dec_ref%8];
			dec_ref /= 8;
			i++;
		}
		for(int j=i-1;j>=0;j--){
			result[k] = con[j];
			k++;
		}
		return Calculator(result,'O');
	}
	else{ //when type is hexadecibmal
		dec_ref = decimal(arr_ref1,1)+decimal(arr_ref2,1);
		while(dec_ref!=0){
			con[i] =text[dec_ref%16];
			dec_ref /= 16;
			i++;
		}
		for(int j=i-1;j>=0;j--){
			result[k] = con[j];
			k++;
		}
		return Calculator(result,'H');
	}
}

const Calculator operator-(const Calculator& num1, const Calculator& num2){
	//Converts octal and hexadecimal char to hexadecimal, 
	//subtracts them, and returns to octal or hexadecimal.
	int i=0 ,k=0, dec_ref;
	char text[17] = "0123456789ABCDEF", result[10], arr_ref1[10], arr_ref2[10], con[10];
	
	for(int i=0;i<10;i++){ //copy array
		arr_ref1[i] = num1.num[i];
		arr_ref2[i] = num2.num[i];
	}
	
	if(num1.type =='O'){ //when type is octal
		dec_ref = decimal(arr_ref1,0)-decimal(arr_ref2,0);
		if(dec_ref<0){ //When the value of subtraction is less than 0
			dec_ref += 262144; //The largest number of 6-digit octal numbers
		}
		while(dec_ref!=0){
			con[i] =text[dec_ref%8];
			dec_ref /= 8;
			i++;
		}
		for(int j=i-1;j>=0;j--){
			result[k] = con[j];
			k++;
		}
		return Calculator(result,'O');
	}
	else{ //when type is hexadecibmal
		dec_ref = decimal(arr_ref1,1)-decimal(arr_ref2,1);
		if(dec_ref<0){ //When the value of subtraction is less than 0
			dec_ref += 16777216; //The largest number of 6-digit hexadecimal numbers
		}
		while(dec_ref!=0){
			con[i] =text[dec_ref%16];
			dec_ref /= 16;
			i++;
		}
		for(int j=i-1;j>=0;j--){
			result[k] = con[j];
			k++;
		}
		return Calculator(result,'H');
	}
}

const bool operator>(const Calculator& num1, const Calculator& num2){
	//Check that ref1 is greater in ref1 and ref2.
	int dec_ref1, dec_ref2;
	char arr_ref1[10], arr_ref2[10];
	for(int i=0;i<10;i++){
		arr_ref1[i] = num1.num[i];
		arr_ref2[i] = num2.num[i];
	}
	if(num1.type == 'O'){
		dec_ref1 = decimal(arr_ref1,0);
		dec_ref2 = decimal(arr_ref2,0);
		return (dec_ref1 > dec_ref2);
	}
	else{
		dec_ref1 = decimal(arr_ref1,1);
		dec_ref2 = decimal(arr_ref2,1);
		return (dec_ref1 > dec_ref2);
	}
}

const bool operator<(const Calculator& num1, const Calculator& num2){
	//Check that ref2 is greater in ref1 and ref2.
	int dec_ref1, dec_ref2;
	char arr_ref1[10], arr_ref2[10];
	for(int i=0;i<10;i++){
		arr_ref1[i] = num1.num[i];
		arr_ref2[i] = num2.num[i];
	}
	if(num1.type == 'O'){
		dec_ref1 = decimal(arr_ref1,0);
		dec_ref2 = decimal(arr_ref2,0);
		return (dec_ref1 < dec_ref2);
	}
	else{
		dec_ref1 = decimal(arr_ref1,1);
		dec_ref2 = decimal(arr_ref2,1);
		return (dec_ref1 < dec_ref2);
	}
}

const bool operator==(const Calculator& num1, const Calculator& num2){
	//Convert octal and hexadecimal numbers to decimal numbers to see if they are the same
	int dec_ref1, dec_ref2;
	char arr_ref1[10], arr_ref2[10];
	for(int i=0;i<10;i++){
		arr_ref1[i] = num1.num[i];
		arr_ref2[i] = num2.num[i];
	}
	if(num1.type == 'O'){
		dec_ref1 = decimal(arr_ref1,0);
		dec_ref2 = decimal(arr_ref2,0);
		return (dec_ref1 == dec_ref2);
	}
	else{
		dec_ref1 = decimal(arr_ref1,1);
		dec_ref2 = decimal(arr_ref2,1);
		return (dec_ref1 == dec_ref2);
	}
}

ostream& operator <<(ostream & outputStream, const Calculator& figure){
	//Converts octal and hexadecimal numbers to decimal numbers and outputs them.
	char arr_ref[10];
	for(int i=0;i<10;i++){
		arr_ref[i] = figure.num[i];
	}
	if(figure.type == 'O') outputStream << decimal(arr_ref,0);
	else outputStream << decimal(arr_ref,1);
	return outputStream;
}
