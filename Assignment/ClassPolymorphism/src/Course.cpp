/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Source file for course class
Type: Source
*/

#include "Course.h"

Course::Course()
{
    //ctor
    courseCode = "null"; //Set everything to a null value
    courseName = "null";
    for(int i = 0; i < 30; i++)
    {
       studentList[i] = nullptr;
    }
    instructor = nullptr;
}

//custom constructor
Course::Course(string _code, string _name, Student* _list[], Teacher* _instructor)
{
    courseCode = _code; //Set everything to a function conditions
    courseName = _name;
    for(int i = 0; i < 30; i++)
    {
       studentList[i] = _list[i];
    }
    instructor = _instructor;
}

Course::~Course()
{
    //dtor
}

//For assigning teacher
void Course::assignTeacher(const Teacher*)
{
    return;
}

//For assgining student
void Course::assignStudent(const Student*)
{
    return;
}

//For removing teacher
void Course::removeTeacher(const Teacher*)
{
    return;
}

//For removing student
void Course::removeStudent(const Student*)
{
    return;
}


//To display class
const void Course::display(bool _displayExtra)
{
    cout << courseName << "<" << courseCode << ">"; //Print out basic information

    if(_displayExtra) //If displaying extra info
    {
        cout << endl;
        if(instructor != nullptr) //If teacher is not null
        {
            cout << "- ";
            (*instructor).display(false); //Call function for a basic display
        }

        for(int i = 0; i < 30; i++) //Go through class list
        {
            if(studentList[i] != nullptr) //if not null, display
            {
                cout << "- ";
                (*studentList[i]).display(false);
            }
        }
    }
    return;
}

