/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: Header file for Line class
Type: Header
*/

#ifndef LINE_H
#define LINE_H
#include "Point.h" //Include point class

using namespace std;

class Line
{
    public:
        Line();
        Line(float, float); //Custom Constructor
        virtual ~Line();

        Point determineInterception(Line*); //To determine the point of an intersection with another line
        bool isParallel(Line*); //To determine if another line is parallel
        Line determinePerpundicular(Point*); //To determine perpundicular line through certain point
        void displayLine(); //To display line

        //Getters and Setter
        float getSlope();
        float getIntercept();
        void setSlope(float);
        void setIntercept(float);

    protected:

    private:
        float slope;
        float yIntercept;
};

#endif // LINE_H
