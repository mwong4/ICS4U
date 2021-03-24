/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Source file for student class
Type: Source
*/

#include "Student.h"

Student::Student()
{
    //ctor
    for(int i = 0; i < 4; i++)
    {
        courses[i] = nullptr;
    }
    age = 0; //Set to null
    grade = 0;
}

//custom constructor
Student::Student(string _name, long int _phone, Course* _courses[], int _age, int _grade) : Person(_name, _phone)
{
    for(int i = 0; i < 4; i++) //Set all values to input conditions
    {
        courses[i] = _courses[i];
    }
    age = _age;
    grade = _grade;
}

Student::~Student()
{
    //dtor
}


//For displaying person
const void Student::display(bool _displayExtra)
{
    Person::display(false); //Call person display method
    cout << " (age: " << age << ", grade " << grade << ")";

    if(_displayExtra) //If told to display extra
    {
        cout << "classes: ";
        for(int i = 0; i < 4; i++) //Run while loop to display all classes
        {
            if(courses[i] != nullptr)
            {
                //(*courses[i]).display(false); //Call basic display function in course
                cout << ", ";
            }
        }
    }
    cout << endl; // print enter
    return;
}

//Adding course to person
void Student::addToCourse(Course* _course)
{
    return;
}

//Removing course to person
void Student::removeCourse(Course* _course)
{
    return;
}

