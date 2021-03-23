/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: Header file for residential building class
Type: Header
*/

#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
#include<iostream>
#include "Building.h"

using namespace std;

class Residential : public Building
{
    public:
        Residential();
        Residential(string, int, int, int); //Custom constructor
        virtual ~Residential();

    protected:
        int numberOfBedrooms;
        int numberOfBathrooms;
        void display(); //Display function

    private:
};

#endif // RESIDENTIAL_H
