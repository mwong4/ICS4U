/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: Holds all data and methods for Line class
Type: Source
*/

#include "Line.h"
#include <iostream>

Line::Line()
{
    //ctor
    slope = 1;
    yIntercept = 0;
}

//Custom Constructor
Line::Line(float _slope, float _yIntercept)
{
    slope = _slope;
    yIntercept = _yIntercept;
    return;
}

Line::~Line()
{
    //dtor
}

//To determine the point of an intersection with another line
Point Line::determineInterception(Line* _line)
{
    Point tempPoint; //Point to be returned

    if(isParallel(_line)) //First make sure lines are not parallel
    {
        cout << " >- Cannot compute, lines are parallel" << endl;
    }
    else
    {
        //( / yIntercept)*((*_line).getSlope()/slope)
        tempPoint.setX(((*_line).getIntercept()-yIntercept)/(slope-(*_line).getSlope()));
        tempPoint.setY((slope*tempPoint.getX())+yIntercept);
        return tempPoint; //Return point
    }
}

//To determine if another line is parallel
bool Line::isParallel(Line* _line)
{
    if(slope == (*_line).getSlope()) //If slopes are the same, return true
    {
        return true;
    }
    return false; //else return false
}

//To determine perpundicular line through certain point
Line Line::determinePerpundicular(Point* _point)
{
    Line tempLine;//Temporary line to be returned

    if(slope == 0)
    {
        cout << ">- Cannot Compute Further, Vertical Line at x=" << (*_point).getX() << endl; //Avoid 1/0 values
    }
    else
    {
        tempLine.slope = (1/slope); //Calculate new slope
        tempLine.yIntercept = ((*_point).getY()) - (tempLine.slope*(*_point).getX()); //Calculate new y intercept
        return tempLine; //return line
    }
}

//To display line
void Line::displayLine()
{
    cout << "y=" << slope << "x+" << yIntercept << endl; //Print out equation
    return;
}

//Getters and Setters
float Line::getSlope()
{
    return slope;
}

float Line::getIntercept()
{
    return yIntercept;
}

void Line::setSlope(float _slope)
{
    slope = _slope;
}

void Line::setIntercept(float _intercept)
{
    yIntercept = _intercept;
}


