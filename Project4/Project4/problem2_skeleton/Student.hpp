#ifndef Student_hpp
#define Student_hpp

#include "Cls.hpp"
#include <iostream>
#include <string>

class Cls;

using namespace std;

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

#endif
