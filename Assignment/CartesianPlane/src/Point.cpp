/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 26, 2020
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
void Point::determineEquation(Point* _point, Line* _line)
{
    if(xCoord == (*_point).getX()) //If x coords are the same
    {
        (*_line).setVert(true); //Eanble vert
        (*_line).setSlope(1);
        (*_line).setIntercept(xCoord); //Set x=??? value to y-intercept
    }
    else if(yCoord == (*_point).getY()) //else if y coords are the same
    {
        (*_line).setVert(false); //Dusable vert
        (*_line).setSlope(0);
        (*_line).setIntercept(yCoord); //Set y constant to y-intercept
    }
    else
    {
        (*_line).setVert(false); //Disable vert
        (*_line).setSlope((yCoord-(*_point).getY())/(xCoord-(*_point).getX())); //Calculate slope
        (*_line).setIntercept(yCoord - ((*_line).getSlope()*xCoord)); //Calculate y intercept
    }
    return;
}

//To display the point
void Point::display()
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


