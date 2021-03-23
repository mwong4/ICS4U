/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: Source file for building class
Type: Source
*/

#include "Building.h"

Building::Building()
{
    //ctor
    address = "null";
    squareFootage = 0;
}

//Custom constructor
Building::Building(string _address, int _size)
{
    address = _address;
    squareFootage = _size;
}

Building::~Building()
{
    //dtor
}

//Display function
void Building::display()
{
    return;
}
