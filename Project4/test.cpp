#include <iostream>
#include <string>

using namespace std;

class Cls;

class Student{
public:
    Student();
    Student(string name, string id, int limit);
    void Display();
    void Register(Cls* cls);
    void Withdraw(Cls* cls);
    void append(Cls* cls);
    int Get_limit(); //Accessor
    int Get_count(); //Accessor
    string Get_name(); //Accessor
    string Get_id(); //Accessor
    void increase(); //increase count
    void decrease(); //decrease count
private:
    string name;
    string id;
    Cls** list;
    int limit; //The maximum number of classes a student can have 
    int count; //Current class count
};

class Cls{
public:
    Cls();
    Cls(string name, string instructor, int limit);
    void Register(Student* student);
    void Withdraw(Student* student);
    void append(Student* student);
    void Display(); 
    int Get_limit(); //Accessor
    int Get_count(); //Accessor
    string Get_name(); //Accessor
    string Get_instructor(); //Accessor
    void increase(); //increase count
    void decrease(); //decrease count
private:
    string name;
    string instructor;
    Student** list;
    int limit; //limit number of class
    int count; //Current class count
};

Cls::Cls(string nameval, string instructorval, int limitval){ 
	name = nameval;
	instructor = instructorval;
	limit = limitval;
	list = new Student*[limitval];
	count = 0;
}

string Cls::Get_instructor(){return instructor;} 
string Cls::Get_name(){return name;}
int Cls::Get_limit(){return limit;}
int Cls::Get_count(){return count;}
void Cls::increase(){count++;}
void Cls::decrease(){count--;}

void Cls::Register(Student* student){ 
	int dt = -1; //distinction number
	for(int i=0;i<count;i++){
		if(list[i]->Get_name().compare(student->Get_name())==0){
			cout << "[Failed] " << student->Get_name() << " has already registered " << this->name << endl;
			dt = 0;
		}
	}
	if(dt==-1){
		if(count<limit && student->Get_count()<student->Get_limit()){
			list[count] = student;
			student->append(this);
			increase();
		}
		else if(count>=limit) cout << "[Failed] " << this->name << " has already been full!" << endl;
		else if(student->Get_count()>=student->Get_limit()) cout << "[Failed] " << student->Get_name() << " can't take more class" << endl;
	}
}

void Cls::Withdraw(Student* student){
	int dt = -1;
	for(int i=0;i<count;i++){
		if(list[i]->Get_name().compare(student->Get_name())==0){
			student->decrease();
			decrease();
			dt = 0;
		}
	}
	if(dt==-1) cout << "[Failed] " << student->Get_name() <<"didn't registered " << this->name << endl;
}

void Cls::append(Student* student){
	list[count] = student;
	increase();
}

void Cls::Display(){
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

Student::Student(string nameval, string idval, int limitval){
	name = nameval;
	id = idval;
	limit = limitval;
	list = new Cls*[limitval];
	count = 0;
}



string Student::Get_id(){return id;}
string Student::Get_name(){return name;}
int Student::Get_limit(){return limit;}
int Student::Get_count(){return count;}
void Student::increase(){count++;}
void Student::decrease(){count--;}

void Student::Register(Cls* cls){
	int dt = -1;
	for(int i=0;i<count;i++){
		if(list[i]->Get_name().compare(cls->Get_name())==0){
			cout << "[Failed] " << this->name << " has already registered " << cls->Get_name() << endl;
			dt = 0;
		}
	}
	if(dt==-1){
		if(count<limit && cls->Get_count() < cls->Get_limit()){
			list[count] = cls;
			cls->append(this);
			increase();
		}
		else if(count>=limit) cout << "[Failed] " << this->name << " can't take more class" << endl;
		else if(cls->Get_count() >= cls->Get_limit()) cout << "[Failed] " << cls->Get_name() << " has already been full!" << endl;
	}
}

void Student::Withdraw(Cls* cls){
	int dt = -1;
	for(int i=0;i<this->count;i++){
		if(list[i]->Get_name().compare(cls->Get_name())==0){
			cls->decrease();
			decrease();
			dt = 0;
		}
	}
	if(dt==-1) cout << "[Failed] " << this->name <<" didn't registered " << cls->Get_name() << endl;
}

void Student::append(Cls* cls){
	list[count] = cls;
	increase();
}

void Student::Display(){
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

int main(int argc, const char * argv[]){
    // Classes
    Cls* OOP = new Cls("OOP", "Kim", 4);
    Cls* DS = new Cls("DS", "Yang", 2);
    Cls* AI = new Cls("AI", "Hwang", 5);
    
    // Students
    Student* A = new Student("A", "2018111111", 2);
    Student* B = new Student("B", "2018111112", 2);
    Student* C = new Student("C", "2018111113", 2);
    Student* D = new Student("D", "2018111114", 2);
    Student* E = new Student("E", "2018111115", 2);
    
    
    // OOP Registration
    OOP->Register(A); // A
    OOP->Register(B); // A B
    OOP->Register(C); // A B C
    OOP->Register(D); // A B C D
    OOP->Withdraw(C); // A B D
    OOP->Register(E); // A B D E
    // OOP -> A, B, D, E

    
    //DS Registration
    A->Register(DS); // A
    B->Register(DS); // A B
    DS->Register(E); // print error msg (class is full)
    E->Register(DS); // print error msg (class is full)
    B->Withdraw(DS); // A
    C->Register(DS); // A C
    // DS -> A, C
    
    
    // AI Registration
    A->Register(AI); // print error msg (can't take more class)
    AI->Register(A); // print error msg (can't take more class)
    AI->Register(C); // C
    C->Register(AI); // print error msg (can't take more class, by student side)
    AI->Register(C); // print error msg (already registered, by class side)
    AI->Register(D); // D
    E->Register(AI); // E
    A->Withdraw(AI); // print error msg (didn't registered)
    // AI -> C, D, E
    

    // Display Status of each
    A->Display();
    B->Display();
    C->Display();
    D->Display();
    E->Display();
    
    OOP->Display();
    DS->Display();
    AI->Display();
    //done

    return 0;
}
/*
 
######################   Sample I/O   ######################
 
 
 [Failed] DS has already been full!
 [Failed] DS has already been full!
 [Failed] A can't take more class
 [Failed] A can't take more class
 [Failed] C can't take more class
 [Failed] C has already registered AI
 [Failed] A didn't register AI!
 -----------------------------------------------
 Name : A    Student# : 2018111111
 -----------------------------------------------
 Total number of lectures : 2
 
 OOP    Kim
 DS    Yang
 
 
 -----------------------------------------------
 Name : B    Student# : 2018111112
 -----------------------------------------------
 Total number of lectures : 1
 
 OOP    Kim
 
 
 -----------------------------------------------
 Name : C    Student# : 2018111113
 -----------------------------------------------
 Total number of lectures : 2
 
 DS    Yang
 AI    Hwang
 
 
 -----------------------------------------------
 Name : D    Student# : 2018111114
 -----------------------------------------------
 Total number of lectures : 2
 
 OOP    Kim
 AI    Hwang
 
 
 -----------------------------------------------
 Name : E    Student# : 2018111115
 -----------------------------------------------
 Total number of lectures : 2
 
 OOP    Kim
 AI    Hwang
 
 
 -----------------------------------------------
 Porf. : Kim    Class Name : OOP
 -----------------------------------------------
 Total number of students : 4
 
 A    2018111111
 B    2018111112
 D    2018111114
 E    2018111115
 
 
 -----------------------------------------------
 Porf. : Yang    Class Name : DS
 -----------------------------------------------
 Total number of students : 2
 
 A    2018111111
 C    2018111113
 
 
 -----------------------------------------------
 Porf. : Hwang    Class Name : AI
 -----------------------------------------------
 Total number of students : 3
 
 C    2018111113
 D    2018111114
 E    2018111115
 
 
 
*/


/* error message example
 
 cout << "[Failed] " << this->name << " can't take more class" << endl;
 cout << "[Failed] " << this->name << " has already registered " << cls->getName() << endl;
 cout << "[Failed] " << this->name << " has already been full!" << endl;
 cout << "[Failed] " << student->getName() <<"didn't registered " << this->name << endl;
 
*/
