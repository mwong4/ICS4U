/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Feb 24, 2020
Purpose: header file for rectangle exercise
Type: Main
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

using namespace std;

class Rectangle
{
    public:
        Rectangle();
        Rectangle(int, int); //Custom constructor
        virtual ~Rectangle();

        //Required functions
        int determineArea();
        int determinePerimeter();
        void displayDimensions();

        //getters and setters
        int getWidth();
        int getLength();
        void setWidth(int);
        void setLength(int);

    protected:

    private:
        int width; //The dimensions of the rectangle
        int length;
};

#endif // RECTANGLE_H
