/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 25, 2020
Purpose: Source file for student class
Type: Source
*/

#include "Student.h"
#include "Course.h"

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
Student::Student(string _name, long int _phone, int _age, int _grade) : Person(_name, _phone)
{
    for(int i = 0; i < 4; i++)
    {
        courses[i] = nullptr;
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
        cout << " classes: ";
        for(int i = 0; i < 4; i++) //Run while loop to display all classes
        {
            if(courses[i] != nullptr)
            {
                (*courses[i]).display(false); //Call basic display function in course
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
    for(int i = 0; i < 4; i++)
    {
        if(courses[i] == nullptr)
        {
            courses[i] = _course; //Set course in student's list
            (*_course).assignStudent(this); //Call course method to add to class
            return; //Return
        }
    }

    cout << "Sorry, student is exceeding 4 classes" << endl; //Otherwise course selection is full, print warning to user
    return;
}

//Removing course to person
void Student::removeCourse(Course* _course)
{
    for(int i = 0; i < 4; i++)
    {
        if(courses[i] == _course)
        {
            courses[i] = nullptr; //Remove course from student's list
            (*_course).removeStudent(this); //Call course method to remove from class
            return; //Return
        }
    }

    cout << "Sorry, class not found" << endl; //Otherwise course not found, print warning to user
    return;
}

