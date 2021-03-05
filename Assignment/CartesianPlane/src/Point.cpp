/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Mar 4, 2020
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
Line Point::determineEquation(const Point* _point, const Line* _line)
{
    Line output = *(_line); //Copy _line into output

    if(xCoord == (*_point).getX()) //If x coords are the same
    {
        output.setVert(true); //Eanble vert
        output.setSlope(1);
        output.setIntercept(xCoord); //Set x=??? value to y-intercept
    }
    else if(yCoord == (*_point).getY()) //else if y coords are the same
    {
        output.setVert(false); //Dusable vert
        output.setSlope(0);
        output.setIntercept(yCoord); //Set y constant to y-intercept
    }
    else
    {
        output.setVert(false); //Disable vert
        output.setSlope((yCoord-(*_point).getY())/(xCoord-(*_point).getX())); //Calculate slope
        output.setIntercept(yCoord - (output.getSlope()*xCoord)); //Calculate y intercept
    }
    return output;
}

//To display the point
void Point::display()
{
    cout << "(" << xCoord << "," << yCoord << ")" << endl;
    return;
}

//Getters and Setters
float Point::getX() const
{
    return xCoord;
}

float Point::getY() const
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


