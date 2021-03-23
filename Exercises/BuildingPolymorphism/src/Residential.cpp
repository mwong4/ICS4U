/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: Source file for residential building class
Type: Source
*/


#include "Residential.h"

Residential::Residential()
{
    //ctor
}

//Custom constructor
Residential::Residential(string _address, int _size, int _bedrooms, int _bathrooms) : Building(_address, _size)
{
    numberOfBedrooms = _bedrooms;
    numberOfBathrooms = _bathrooms;
}

Residential::~Residential()
{
    //dtor
}

//Display function
void Residential::display()
{
    Building::display(); //call parent display
    cout << address << ", " << squareFootage << " meters squared || bedrooms: " << numberOfBedrooms << ", bathrooms: " << numberOfBathrooms << endl;
    return;
}
