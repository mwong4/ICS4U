/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 17, 2021
Purpose: Header file for rectangle class
Type: Header
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Polygon.h" //include polygon class

using namespace std;

class Rectangle: public Polygon
{
    public:
        Rectangle();
        Rectangle(float[], int); //Custom constructor
        virtual ~Rectangle();

        //general functions
        float determineArea(); //To determine area

        //getters/setters

    protected:

    private:
};

#endif // RECTANGLE_H
