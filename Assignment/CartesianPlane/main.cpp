/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Mar 4, 2020
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
    Point *point1 = new Point(1, 2); //1, 2
    Point *point2 = new Point(1, 3); //1, 3
    Point *point3 = new Point(4, 3); //4, 3
    Point *point4 = new Point;
    Point *point5 = new Point(2,5); //2, 5
    Point *point6 = new Point(6,7); //6, 7

    Line *line1 = new Line;
    Line *line2 = new Line;
    Line *line3 = new Line;

    //Test case 1:
    *line1 = (*point1).determineEquation(point2, line1);
    (*line1).display();
    *line2 = (*point2).determineEquation(point3, line2);
    (*line2).display();
    *point4 = (*line1).determineInterception(line2, point4);
    if(!(*line1).isParallel(line2)) //Check to make sure not parallel
    {
        (*point4).display();
    }

    //Test Case 2:
    *line1 = (*point1).determineEquation(point2, line1);
    (*line1).display();
    *line2 = (*point2).determineEquation(point5, line2);
    (*line2).display();
    *point4 = (*line1).determineInterception(line2, point4);
    if(!(*line1).isParallel(line2)) //Check to make sure not parallel
    {
        (*point4).display();
    }

    //Test Case 3:
    *line1 = (*point3).determineEquation(point6, line1);
    (*line1).display();
    *line2 = (*point2).determineEquation(point5, line2);
    (*line2).display();
    *point4 = (*line1).determineInterception(line2, point4);
    if(!(*line1).isParallel(line2))
    {
        (*point4).display();
    }

    return 0;
}
