/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: To perform multiple operations on the cartesian plane using objects
Type: Main
*/

#include <iostream>
#include "Line.h"
#include "Point.h"

using namespace std;

int main()
{
    Line lineOne(2, 1), lineTwo(4, 2);
    Point pointOne(1, 5), pointTwo(3, 5);

    if(pointOne.determineEquation(&pointTwo, &lineOne))
    {
        lineOne.displayLine();
    }

    return 0;
}
