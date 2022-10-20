#include "Student.hpp"

Student::Student(string nameval, string idval, int limitval){ //Constructor for all variable
	name = nameval;
	id = idval;
	limit = limitval;
	list = new Cls*[limitval];
	count = 0;
}

string Student::Get_id(){return id;} //return id
string Student::Get_name(){return name;} //return name
int Student::Get_limit(){return limit;} //return limit number
int Student::Get_count(){return count;} //return counting number
void Student::increase(){count++;} //increase count
void Student::decrease(){count--;} //decrease count

void Student::Register(Cls* cls){ //register function
	int dt = -1;
	for(int i=0;i<count;i++){
		if(list[i]->Get_name().compare(cls->Get_name())==0){
			cout << "[Failed] " << this->name << " has already registered " << cls->Get_name() << endl; //print error message when student already registered this class
			dt = 0;
		}
	}
	if(dt==-1){
		if(count<limit && cls->Get_count() < cls->Get_limit()){ //register
			list[count] = cls;
			cls->append(this);
			increase();
		}
		else if(count>=limit) cout << "[Failed] " << this->name << " can't take more class" << endl; //print error message When the student exceeds the number of classes that can be applied
		else if(cls->Get_count() >= cls->Get_limit()) cout << "[Failed] " << cls->Get_name() << " has already been full!" << endl; //print error message When the number of students in class is full
	} 
}

void Student::Withdraw(Cls* cls){ //Withdraw function
	int dt = -1;
	for(int i=0;i<this->count;i++){
		if(list[i]->Get_name().compare(cls->Get_name())==0){ //Make sure that the student has applied for the class.
			cls->decrease();
			decrease();
			dt = 0;
		}
	}
	if(dt==-1) cout << "[Failed] " << this->name <<" didn't registered " << cls->Get_name() << endl; //print error message When a student is not in class
}

void Student::append(Cls* cls){ //append function
	list[count] = cls;
	increase();
}

void Student::Display(){ //Display
    cout << "-----------------------------------------------" << endl;
    cout << "Name : " << this->name << "\t" <<"Student# : " << this->id << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total number of lectures : " << this->count << endl << endl;
    for(int i=0; i<this->count; i++){
        cout << list[i]->Get_name()
        << "\t" << list[i]->Get_instructor()
        << endl;
    }
    cout << endl << endl;
}
