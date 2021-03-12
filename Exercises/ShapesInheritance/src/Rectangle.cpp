/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 12, 2021
Purpose: Source file for rectangle class
Type: Source
*/

#include "Rectangle.h"

Rectangle::Rectangle()
{
    //ctor
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
