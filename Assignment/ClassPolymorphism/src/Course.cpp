/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 25, 2020
Purpose: Source file for course class
Type: Source
*/

#include "Course.h"

Course::Course()
{
    //ctor
    courseCode = "null"; //Set everything to a null value
    courseName = "null";
    for(int i = 0; i < 30; i++) //Loop through whole class list and set to nullptr
    {
       studentList[i] = nullptr;
    }
    instructor = nullptr;
}

//custom constructor
Course::Course(string _code, string _name)
{
    courseCode = _code; //Set everything to a function conditions
    courseName = _name;
    for(int i = 0; i < 30; i++) //Loop through whole class list and set to nullptr
    {
       studentList[i] = nullptr;
    }
    instructor = nullptr;
}

Course::~Course()
{
    //dtor
}

//For assigning teacher
void Course::assignTeacher(Teacher* _teacher)
{
    if(instructor != nullptr)
    {
        cout << "REPLACING instructor" << endl;
        (*instructor).removeCourse(this); //If replacing teacher, remove class from teachers course list
    }
    instructor = _teacher; //St instructor as input teacher
    return;
}

//For assgining student
void Course::assignStudent(Student* _student)
{
    for(int i = 0; i <= 30; i++) //Go through whole class list and look for any empty spots
    {
        if(studentList[i] == nullptr) //if one is found, set spot and return
        {
            studentList[i] = _student;
            return;
        }
    }
    cout << "Sorry, your class has maxed out. No room left for this student" << endl; //otherwise, class list is maxed out. Return and print warning
    return;
}

//For removing teacher
void Course::removeTeacher(const Teacher* _teacher)
{
    instructor = nullptr; //Set instructor to null
    return;
}

//For removing student
void Course::removeStudent(const Student* _student)
{
    for(int i = 0; i <= 30; i++) //Go through whole class list and look for specific student
    {
        if(studentList[i] == _student) //if one is found, remove spot and return
        {
            studentList[i] = nullptr;
            return;
        }
    }
    cout << "Sorry, student was not found" << endl; //otherwise, student is not found. Return and print warning
    return;
}


//To display class
const void Course::display(bool _displayExtra)
{
    cout << courseName << " <" << courseCode << ">"; //Print out basic information

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

