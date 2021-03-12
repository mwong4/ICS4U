/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 12, 2021
Purpose: Source file for triangle class
Type: Source
*/

#include "Triangle.h"
#include <math.h>

Triangle::Triangle()
{
    //ctor

}

Triangle::~Triangle()
{
    //dtor
}

//To determine area
float Triangle::determineArea()
{
    float height = determineHeight(); //Call function to get height

    return (height*getLength(1))/2; //Calculate and return area
}

//To determine height
float Triangle::determineHeight()
{
    return getLength(2)*sin(acos(((getLength(0)*getLength(0)) - (getLength(1)*getLength(1)) - (getLength(2)*getLength(2)))/(-2*(getLength(1)*getLength(2))))); //Caculate height using cosine law and return
}
