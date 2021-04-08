/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 7, 2021
Purpose: Source file for wire class
Type: Source
*/

#include "Wire.h"

Wire::Wire() : Electronic()
{
    //ctor
}

//Custom constructor
Wire::Wire(int _symbol, int _colour, bool _powered, Interactable* _next, int _altColour) : Electronic(_symbol, _colour, _powered, _next, _altColour)
{

}

Wire::~Wire()
{
    //dtor
}

//Returns solidity status
bool Wire::checkSolid()
{
    return true;
}

//Toggles power and other stuff
void Wire::togglePower(bool _portal)
{
    altColour = swapColour(altColour);//Swap colours
    Electronic::togglePower(true); //Toggle bool

    //If next object exists, set it to powered
    if(ptr_next != nullptr)
    {
        (*ptr_next).togglePower(true);
    }
    return;
}
