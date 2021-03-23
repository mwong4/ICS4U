/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: Header file for commcercial building class
Type: Header
*/

#ifndef COMMERCIAL_H
#define COMMERCIAL_H
#include<iostream>
#include "Building.h"

using namespace std;

class Commercial : public Building
{
    public:
        Commercial();
        Commercial(string, int, int, bool); //Custom constructor
        virtual ~Commercial();

    protected:
        int loadingDock;
        bool accessToWater;
        void display(); //Display function

    private:
};

#endif // COMMERCIAL_H
