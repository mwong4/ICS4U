/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Source file for teacher class
Type: Source
*/

#include "Teacher.h"
#include "Course.h"

Teacher::Teacher()
{
    //ctor
    for(int i = 0; i < 4; i++)
    {
        courses[i] = nullptr;
    }
    speciality = "null";
}

//custom constructor
Teacher::Teacher(string _name, long int _phone, string _specialty) : Person(_name, _phone)
{
    for(int i = 0; i < 4; i++)
    {
        courses[i] = nullptr;
    }
    speciality = _specialty;
}

Teacher::~Teacher()
{
    //dtor
}


//For displaying person
const void Teacher::display(bool _displayExtra)
{
    Person::display(false); //Call person display method
    cout << " (specialty: " << speciality << ")";

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
}

//Adding course to person
void Teacher::addToCourse(Course* _course)
{
    for(int i = 0; i < 4; i++)
    {
        if(courses[i] == nullptr)
        {
            courses[i] = _course; //Set course in instructors's list
            (*_course).assignTeacher(this); //Call course method to add to class
            return; //Return
        }
    }

    cout << "Sorry, teacher is exceeding 4 classes" << endl; //Otherwise course selection is full, print warning to user
    return;
}

//Removing course to person
void Teacher::removeCourse(Course* _course)
{
    for(int i = 0; i < 4; i++)
    {
        if(courses[i] == _course)
        {
            courses[i] = nullptr; //Remove course from teacher's list
            (*_course).removeTeacher(this); //Call course method to remove from class
            return; //Return
        }
    }

    cout << "Sorry, class not found" << endl; //Otherwise course not found, print warning to user
    return;
}

