#include <iostream>
#include <string>
#include "Student.hpp"
#include "Cls.hpp"

using namespace std;

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

