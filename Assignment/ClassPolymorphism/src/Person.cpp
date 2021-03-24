/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Source file for person class
Type: Source
*/

#include "Person.h"

Person::Person()
{
    //ctor
    name = "null"; //Set to null values
    phoneNumber = 0;
}

//custom constructor
Person::Person(string _name, long int _phone)
{
    name = _name; //Setting all values from input conditions
    phoneNumber = _phone;
}

Person::~Person()
{
    //dtor
}


//For displaying person
const void Person::display(bool _displayExtra)
{
    cout << "|" << name << "| pn: " << phoneNumber;
    return;
}

//Adding course to person
void Person::addToCourse(Course* _course)
{
    return;
}

//Removing course to person
void Person::removeCourse(Course* _course)
{
    return;
}

