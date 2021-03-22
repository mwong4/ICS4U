/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 17, 2021
Purpose: Header file for triangle class
Type: Header
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h" //includepolyon class

using namespace std;

class Triangle: public Polygon
{
    public:
        Triangle();
        Triangle(float[], int); //Custom constructor
        virtual ~Triangle();

        //general functions
        float determineArea(); //To determine area
        float determineHeight(); //To determine height

        //getters/setters

    protected:

    private:

};

#endif // TRIANGLE_H
