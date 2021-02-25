/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: Holds all data and methods for Point class
Type: Source
*/

#include "Point.h"
#include "Line.h"
#include <iostream>
#include <tgmath.h> //For squrt()

Point::Point()
{
    //ctor
    xCoord = 0;
    yCoord = 0;
}

//Custom constructor
Point::Point(float _x, float _y)
{
    xCoord = _x;
    yCoord = _y;
    return;
}

Point::~Point()
{
    //dtor
}

//To calculate distance from another point
float Point::distanceFromPoint(Point* _point)
{
    return sqrt(((xCoord - (*_point).getX())*(xCoord - (*_point).getX())) + ((yCoord - (*_point).getY())*(yCoord - (*_point).getY())));
}

//To determine the equation given another point
bool Point::determineEquation(Point* _point, Line* _line)
{
    if(xCoord == (*_point).getX()) //If x coords are the same
    {
        cout << ">- Error, vertical line at x = " << xCoord << endl;
        return false;
    }
    else if(yCoord == (*_point).getY()) //else if y coords are the same
    {
        (*_line).setSlope(0);
        (*_line).setIntercept(yCoord);
        return true;
    }
    else
    {
        (*_line).setSlope((yCoord-(*_point).getY())/(xCoord-(*_point).getX())); //Calculate slope
        (*_line).setIntercept(yCoord - ((*_line).getSlope()*xCoord)); //Calculate y intercept
        return true;
    }
}

//To display the point
void Point::displayPoint()
{
    cout << "(" << xCoord << "," << yCoord << ")" << endl;
    return;
}

//Getters and Setters
float Point::getX()
{
    return xCoord;
}

float Point::getY()
{
    return yCoord;
}

void Point::setX(float _input)
{
    xCoord = _input;
    return;
}

void Point::setY(float _input)
{
    yCoord = _input;
    return;
}


