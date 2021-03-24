/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Source file for teacher class
Type: Source
*/

#include "Teacher.h"

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
Teacher::Teacher(string _name, long int _phone, Course* _courses[], string _specialty) : Person(_name, _phone)
{
    for(int i = 0; i < 4; i++) //Set all values to input conditions
    {
        courses[i] = _courses[i];
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
}

//Adding course to person
void Teacher::addToCourse(Course* _course)
{
    return;
}

//Removing course to person
void Teacher::removeCourse(Course* _course)
{
    return;
}

