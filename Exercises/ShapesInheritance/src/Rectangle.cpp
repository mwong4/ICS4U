/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 17, 2021
Purpose: Source file for rectangle class
Type: Source
*/

#include "Rectangle.h"

Rectangle::Rectangle()
{
    //ctor
}

//Custom constructor, calls superclass
Rectangle::Rectangle(float _sides[], int _size) : Polygon(_sides, _size)
{

}

Rectangle::~Rectangle()
{
    //dtor
}

//To determine area
float Rectangle::determineArea()
{
    return getLength(0) * getLength(1);
}
