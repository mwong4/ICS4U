/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Feb 24, 2020
Purpose: define methods for rectangle class
Type: Main
*/

#include "Rectangle.h"

Rectangle::Rectangle()
{
    //ctor
    width = 1;
    length = 1;
}

Rectangle::Rectangle(int _width, int _length) //Custom constructor
{
    width = _width;
    length = _length;
    return;
}

Rectangle::~Rectangle()
{
    //dtor
}

//Required functions
int Rectangle::determineArea()
{
    return width*length;
}

int Rectangle::determinePerimeter()
{
    return (2*width) + (2*length);
}

void Rectangle::displayDimensions()
{
    cout << " >- " << width << "x" << length << " (WxL)" << endl;
    return;
}

//getters and setters
int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getLength()
{
    return length;
}

void Rectangle::setWidth(int _width)
{
    width = _width;
    return;
}

void Rectangle::setLength(int _length)
{
    length = _length;
    return;
}
