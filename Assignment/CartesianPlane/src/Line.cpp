/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 26, 2020
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
    vert = false;
}

//Custom Constructor
Line::Line(float _slope, float _yIntercept, bool _isVert)
{
    slope = _slope;
    yIntercept = _yIntercept;
    vert = _isVert;
    return;
}

Line::~Line()
{
    //dtor
}

//To determine the point of an intersection with another line
bool Line::determineInterception(Line* _line, Point *_point)
{
    if(isParallel(_line)) //First make sure lines are not parallel
    {
        cout << " >- Cannot compute, lines are parallel" << endl;
        return false;
    }
    else
    {
        if(vert) //If either equation is vertical line, save
        {
            (*_point).setX(yIntercept);
        }
        else if((*_line).getVert())
        {
            (*_point).setX((*_line).getIntercept());
        }
        else //All good, do calculations
        {
            (*_point).setX(((*_line).getIntercept()-yIntercept)/(slope-(*_line).getSlope()));
        }


        if(slope == 0) //If either equation is horizontal line, save
        {
            (*_point).setY(yIntercept);
        }
        else if((*_line).getSlope() == 0)
        {
            (*_point).setY((*_line).getIntercept());
        }
        else //All good, do calculations
        {
            if(vert) //Determine which equation is vertical before doing the calculations on real function
            {
                (*_point).setY(((*_line).getSlope()*((*_point).getX()))+(*_line).getIntercept());
            }
            else
            {
                (*_point).setY((slope*((*_point).getX()))+yIntercept);
            }
        }

        return true;
    }
}

//To determine if another line is parallel
bool Line::isParallel(Line* _line)
{
    if(slope == (*_line).getSlope() || (vert && (*_line).getVert())) //If slopes are the same, return true
    {
        return true;
    }
    return false; //else return false
}

//To determine perpundicular line through certain point
Line Line::determinePerpundicular(Point* _point)
{
    Line tempLine;//Temporary line to be returned

    if(slope == 0) //if horizontal line
    {
        tempLine.vert = true; //Set vert to false;
        tempLine.slope = 1;
        tempLine.yIntercept = (*_point).getX();
    }
    else if(vert) //If vertical line
    {
        tempLine.vert = false; //Set vert to false;
        tempLine.slope = 0;
        tempLine.yIntercept = (*_point).getY();
    }
    else //Otherwise
    {
        tempLine.slope = (1/slope); //Calculate new slope
        tempLine.yIntercept = ((*_point).getY()) - (tempLine.slope*(*_point).getX()); //Calculate new y intercept
        return tempLine; //return line
    }
}

//To display line
void Line::display()
{
    if(vert) //If vertical line
    {
        cout << "x = " << yIntercept << endl;
    }
    else //Otherwise print out equation
    {
        cout << "y = " << slope << "x + " << yIntercept << endl;
    }
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

bool Line::getVert()
{
    return vert;
}

void Line::setSlope(float _slope)
{
    slope = _slope;
}

void Line::setIntercept(float _intercept)
{
    yIntercept = _intercept;
}

void Line::setVert(bool _vert)
{
    vert = _vert;
    return;
}


