/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Mar 2, 2020
Purpose: To perform multiple operations on the cartesian plane using objects
Type: Main
*/

#include <iostream>
#include "Line.h"
#include "Point.h"

using namespace std;

int main()
{
    //Maloley Test Cases
    Point point1(1, 2); //1, 2
    Point point2(1, 3); //1, 3
    Point point3(4, 3); //4, 3
    Point point4;
    Point point5(2,5); //2, 5
    Point point6(6,7); //6, 7

    Line line1, line2, line3;

    //Test case 1:
    line1 = *(point1.determineEquation(&point2, &line1));
    line1.display();
    line2 = *(point2.determineEquation(&point3, &line2));
    line2.display();
    if(line1.determineInterception(&line2, &point4))
    {
        point4.display();
    }

    //Test Case 2:
    line1 = *(point1.determineEquation(&point2, &line1));
    line1.display();
    line2 = *(point2.determineEquation(&point5, &line2));
    line2.display();
    if(line1.determineInterception(&line2, &point4))
    {
        point4.display();
    }

    //Test Case 3:
    line1 = *(point3.determineEquation(&point6, &line1));
    line1.display();
    line2 = *(point2.determineEquation(&point5, &line2));
    line2.display();
    if(line1.determineInterception(&line2, &point4))
    {
        point4.display();
    }

    return 0;
}
