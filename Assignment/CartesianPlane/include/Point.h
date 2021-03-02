/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 26, 2020
Purpose: Header file for Point class
Type: Header
*/

#ifndef POINT_H
#define POINT_H

using namespace std;

class Line;

class Point
{
    public:
        Point();
        Point(float, float); //Custom constructor
        virtual ~Point();

        float distanceFromPoint(Point*); //To calculate distance from another point
        void determineEquation(Point*, Line*); //To determine the equation given another point
        void display(); //To display the point

        //Getters and Setters
        float getX();
        float getY();
        void setX(float);
        void setY(float);

    protected:

    private:
        float xCoord; //For retaining x and y component
        float yCoord;
};

#endif // POINT_H
