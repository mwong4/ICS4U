/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Feb 24, 2020
Purpose: test methods for rectangle exercise
Type: Main
*/

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    //initialize
    Rectangle *pointRect = new Rectangle();
    Rectangle normRect(4, 3);

    //Testing object
    cout << "//Displaying Dimensions for Normal//" << endl;
    normRect.displayDimensions();

    cout << "//Display Area for Normal//" << endl;
    cout << normRect.determineArea() << endl;

    cout << "//Display Perimeter for Normal//" << endl;
    cout << normRect.determinePerimeter() << endl << endl;


    //Testing pointer
    cout << "//Displaying Dimensions for Pointer//" << endl;
    (*pointRect).displayDimensions();

    cout << "//Display Area for Pointer//" << endl;
    cout << (*pointRect).determineArea() << endl;

    cout << "//Display Perimeter for Pointer//" << endl;
    cout << (*pointRect).determinePerimeter() << endl;

    return 0;
}
