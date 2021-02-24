/*
Example source file for classes
Date Created: Feb 24, 2021
*/

#include "Student.h"

//Constructor
Student::Student()
{
    //ctor
    name = "Bob";
}

Student::Student(string _name, int _age)
{
    name = _name;
    age = _age;
}

//Destructor
Student::~Student()
{
    //dtor
}

void Student::attendClass()
{
    cout << "Testing, " << name << "attending class" << endl; //name = this.name
    return;
}

string Student::getName()
{
    return name;
}

void Student::setName(string _name)
{
    name = _name;
    return;
}

int Student::getAge()
{
    return age;
}

void Student::setAge(int _age)
{
    age = _age;
    return;
}
