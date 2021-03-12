/*
Author: Max Wong
Date Created: Mar 12, 2021
Date Updated: Mar 12, 2021
Purpose: Header file for polygon class
Type: Header
*/

#ifndef POLYGON_H
#define POLYGON_H

using namespace std;

class Polygon
{
    public:
        Polygon();
        Polygon(float[], int); //custom constructor
        virtual ~Polygon();

        //general functions
        float determinePerimeter(); //Returns perimeter
        void display(); //To display values

        //getters and setters
        float getLength(int); //Returns length at given position
        void setSides(float[]);
        void setSize(int);

    protected:

    private:
        float sideLengths[4]; //To track all side lengths
        int numberOfSides; //# of sides

};

#endif // POLYGON_H
