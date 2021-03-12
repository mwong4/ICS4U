/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 12, 2021
Purpose: To learn inheritence
Type: Main

Note: Sorry, could not figure out how to call constructors on polygon from main

Source: cplusplus - http://www.cplusplus.com/doc/tutorial/inheritance/
*/

#include <iostream>
#include "Triangle.h" //include triangle class
#include "Rectangle.h" //include rectangle class

using namespace std;

int main()
{
    float rectangleDimensions[4] = {3, 4, 3, 4};
    float triangleDimensions[3] = {3, 4, 5};

    Triangle myTri;
    Rectangle myRec;

    myTri.setSize(3); //Set Values
    myTri.setSides(triangleDimensions);
    myRec.setSize(4);
    myRec.setSides(rectangleDimensions);

    //Calculate for triangle
    cout << "//Shape 1//" << endl;
    myTri.display();
    cout << "Perimeter: " << myTri.determinePerimeter() << endl;
    cout << "Area: " << myTri.determineArea() << endl << endl;

    //Calculate for rectangle
    cout << "//Shape 2//" << endl;
    myRec.display();
    cout << "Perimeter: " << myRec.determinePerimeter() << endl;
    cout << "Area: " << myRec.determineArea() << endl;

    return 0;
}
