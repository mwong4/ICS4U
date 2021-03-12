/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 12, 2021
Purpose: Source file for polygon class
Type: Source
*/

#include "Polygon.h"
#include <iostream>

Polygon::Polygon()
{
    //ctor
    numberOfSides = 0;
}

//custom constructor
Polygon::Polygon(float _sides[], int _size)
{
    for(int i = 0; i < _size; i++) //Copy input array into side lengths array
    {
        sideLengths[i] = _sides[i];
    }
    numberOfSides = _size; //Save size
}

Polygon::~Polygon()
{
    //dtor
}

//Returns perimeter
float Polygon::determinePerimeter()
{
    float total = 0; //Temporary variable to store perimeter

    for(int i = 0; i < numberOfSides; i++) //Copy input array into side lengths array
    {
        total += sideLengths[i];
    }

    return total; //Return total amount
}

//To display polygon
void Polygon::display()
{
    cout << "Polygon sides: ";
    for(int i = 0; i < numberOfSides; i++) //Go through array and print out each side
    {
        cout << sideLengths[i] << ", ";
    }
    cout << endl;
}

//getters and setters

//Returns length at given position
float Polygon::getLength(int _position)
{
    return sideLengths[_position];
}

void Polygon::setSides(float _sides[])
{
    for(int i = 0; i < numberOfSides; i++) //Copy input array into side lengths array
    {
        sideLengths[i] = _sides[i];
    }
    return;
}

void Polygon::setSize(int _size)
{
    numberOfSides = _size;
    return;
}
