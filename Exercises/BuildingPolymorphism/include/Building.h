/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: Header file for building class
Type: Header
*/

#ifndef BUILDING_H
#define BUILDING_H
#include<iostream>

using namespace std;


class Building
{
    public:
        Building();
        Building(string, int); //Custom constructor
        virtual ~Building();
        virtual void display(); //Display function

    protected:
        string address;
        int squareFootage;


    private:
};

#endif // BUILDING_H
