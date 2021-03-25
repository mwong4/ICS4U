/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 25, 2020
Purpose: Coding classrooms using inheritence/polymorphism
Type: Main
*/

#include <iostream>
#include "Course.h"
#include "Person.h"

using namespace std;

int main()
{
    //Initialize variables
    Person *ptrPerson1 = new Teacher("Mr Maloley", 6132294567, "Computer Science, Math"); //Teachers
    Person *ptrPerson2 = new Teacher("Mr Blakely", 6131231234, "Math, Crows");
    Person *ptrPerson3 = new Student("Bob", 6134881234, 17, 12); //Students
    Person *ptrPerson4 = new Student("Joe", 42, 16, 11);
    Course *course1 = new Course("ICS4U", "Grade 12 University Computer Science"); //Classes
    Course *course2 = new Course("MCR4UR", "Grade 12 AP Calculus");

    //Add to class
    (*ptrPerson2).addToCourse(course1); //Set Blakely to ICS4U Teacher
    (*ptrPerson1).addToCourse(course1); //Replace Blakely with Maloley as ICS4U Teacher
    (*ptrPerson2).addToCourse(course2); //Set Blakely to MCR4UR Teacher
    (*ptrPerson3).addToCourse(course1); //Add Bob to ICS4U
    (*ptrPerson3).addToCourse(course2); //Add Joe to ICS4U
    (*ptrPerson4).addToCourse(course1); //Add Bob to MCR4UR

    //Display
    (*ptrPerson1).display(true); //Display Maloley
    cout << endl;
    (*ptrPerson2).display(true); //Display Blakely
    cout << endl;
    (*ptrPerson3).display(true); //Bob
    cout << endl;
    (*course1).display(true); //Display ICS4U
    cout << endl;
    (*course2).display(true); //Display MCR4UR


    //Remove from class (Optional)
    /*
    (*ptrPerson1).removeCourse(course1); //Remove Maloley from ICS4U
    (*ptrPerson3).removeCourse(course2); //Remove Bob from MCR4UR

    //Display
    cout << endl << "//Removed Maloley and Bob from ICS4U and MCR4UR, respectively//" << endl;
    (*ptrPerson1).display(true); //Display Maloley
    cout << endl;
    (*ptrPerson2).display(true); //Display Blakely
    cout << endl;
    (*ptrPerson3).display(true); //Bob
    cout << endl;
    (*course1).display(true); //Display ICS4U
    cout << endl;
    (*course2).display(true); //Display MCR4UR
    */


    cout << "End Program" << endl;
    return 0;
}
