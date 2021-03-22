/*
Author: Max Wong
Date Created: Mar 20, 2021
Date Updated: Mar 20, 2021
Purpose: Source file for Lines class
Type: Source
*/


#include "Lines.h"

Lines::Lines()
{
    //ctor
    slope = 0;
    intercept = 0;
}

//Custom constructor
Lines::Lines(float _slope, int _intercept)
{
    slope = _slope;
    intercept = _intercept;
}

Lines::~Lines()
{
    //dtor
}
