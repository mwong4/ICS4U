/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: Source file for commercial building class
Type: Source
*/

#include "Commercial.h"

Commercial::Commercial()
{
    //ctor
}

//Custom constructor
Commercial::Commercial(string _address, int _size, int _loadingDocks, bool _water) : Building(_address, _size)
{
    loadingDock = _loadingDocks;
    accessToWater = _water;
}


Commercial::~Commercial()
{
    //dtor
}

//Display function
void Commercial::display()
{
    Building::display(); //call parent display
    cout << "loading docks: " << loadingDock;

    if(accessToWater) //if access to water, display
    {
        cout << " with access to water!!!";
    }

    cout << endl;
    return;
}
