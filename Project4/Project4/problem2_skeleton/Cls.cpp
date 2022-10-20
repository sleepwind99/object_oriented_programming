#include "Cls.hpp"

Cls::Cls(string nameval, string instructorval, int limitval){ //Constructor for all variable
	name = nameval;
	instructor = instructorval;
	limit = limitval;
	list = new Student*[limitval];
	count = 0;
}

string Cls::Get_instructor(){return instructor;} //return instructor
string Cls::Get_name(){return name;} //return name
int Cls::Get_limit(){return limit;} //return limit number
int Cls::Get_count(){return count;} //return counting number
void Cls::increase(){count++;} //increase count
void Cls::decrease(){count--;} //decrease count

void Cls::Register(Student* student){  //register function
	int dt = -1; //distinction number
	for(int i=0;i<count;i++){
		if(list[i]->Get_name().compare(student->Get_name())==0){
			cout << "[Failed] " << student->Get_name() << " has already registered " << this->name << endl; //print error message when student already registered this class
			dt = 0;
		}
	}
	if(dt==-1){
		if(count<limit && student->Get_count()<student->Get_limit()){
			list[count] = student;
			student->append(this);
			increase();
		}
		else if(count>=limit) cout << "[Failed] " << this->name << " has already been full!" << endl; //print error message When the student exceeds the number of classes that can be applied
		else if(student->Get_count()>=student->Get_limit()) cout << "[Failed] " << student->Get_name() << " can't take more class" << endl; //print error message When the number of students in class is full
	}
}

void Cls::Withdraw(Student* student){ //Withdraw function
	int dt = -1;
	for(int i=0;i<count;i++){
		if(list[i]->Get_name().compare(student->Get_name())==0){
			student->decrease();
			decrease();
			dt = 0;
		}
	}
	if(dt==-1) cout << "[Failed] " << student->Get_name() <<"didn't registered " << this->name << endl; //print error message When a student is not in class
}

void Cls::append(Student* student){ //append function
	list[count] = student;
	increase();
}

void Cls::Display(){ //display
    cout << "-----------------------------------------------" << endl;
    cout << "Porf. : " << this->instructor << "\t" <<"Class Name : " << this->name << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total number of students : " << this->count << endl << endl;
    for(int i=0; i< this->count; i++){
        cout << list[i]->Get_name()
    	<< "\t" << list[i]->Get_id()
    	<< endl;
    }
    cout << endl << endl;
}
