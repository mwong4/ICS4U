/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Header file for teacher class
Type: Header
*/

#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "Person.h" //Include person class

using namespace std;

class Teacher: protected Person
{
    public:
        Teacher();
        Teacher(string, long int, Course*[], string); //custom constructor
        virtual ~Teacher();


        //General Functions
        const void display(bool); //For displaying person
        void addToCourse(Course*); //Adding course to person
        void removeCourse(Course*); //Removing course to person

    protected:

    private:
        Course* courses[4];
        string speciality;
};

#endif // TEACHER_H
