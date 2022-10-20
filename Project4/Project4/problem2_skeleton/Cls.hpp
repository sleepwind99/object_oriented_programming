#ifndef Class_hpp
#define Class_hpp

#include "Student.hpp"
#include <iostream>
#include <string>

using namespace std;

class Student;

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

#endif
