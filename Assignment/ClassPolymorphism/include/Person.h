/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Header file for Person class
Type: Header
*/

#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Course; //Empty class course, circular dependencies

class Person
{
    public:
        Person();
        Person(string, long int); //custom constructor
        virtual ~Person();

        //General Functions

        virtual const void display(bool); //For displaying person
        virtual void addToCourse(Course*); //Adding course to person
        virtual void removeCourse(Course*); //Removing course to person

    protected:
        string name;
        long int phoneNumber;

    private:
};

#endif // PERSON_H
