/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 17, 2021
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

    Triangle myTri(triangleDimensions, 3); //Initialize polyons with their appropriate dimensions
    Rectangle myRec(rectangleDimensions, 4);

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
