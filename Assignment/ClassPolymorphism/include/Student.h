/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 25, 2020
Purpose: Header file for student class
Type: Header
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h" //Include person class


using namespace std;

class Student: public Person
{
    public:
        Student();
        Student(string, long int, int, int); //custom constructor
        virtual ~Student();

        //General Functions
        const void display(bool); //For displaying person
        void addToCourse(Course*); //Adding course to person
        void removeCourse(Course*); //Removing course to person

    protected:

    private:
        Course* courses[4];
        int age;
        int grade;
};

#endif // STUDENT_H
