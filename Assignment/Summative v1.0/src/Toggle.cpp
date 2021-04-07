/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 7, 2021
Purpose: Source file for toggle class
Type: Source
*/

#include "Toggle.h"

Toggle::Toggle() : Electronic()
{
    //ctor
    alternateSymbol = 0;
}

//Custom constructor
Toggle::Toggle(int _symbol, int _colour, bool _powered, Interactable* _next, int _altColour, int _altSymbol) : Electronic(_symbol, _colour, _powered, _next, _altColour)
{
    alternateSymbol = _altSymbol;
}

Toggle::~Toggle()
{
    //dtor
}

//Returns solidity status, based on if powered
bool Toggle::checkSolid()
{
    return false;
}

//Toggles power and other stuff
void Toggle::togglePower()
{
    char tempSymbol; //Used for swapping symbols
    int tempInt; //Used for swapping colours

    //Swap symbol
    tempSymbol = alternateSymbol; //Save alternate colour
    alternateSymbol = getSymbol(); //Save current colour into alt
    setSymbol(tempSymbol); //Set as as colour

    //Swap colours
    tempInt = altColour; //Save alternate colour
    altColour = getColour(); //Save current colour into alt
    setColour(tempInt); //Set as as colour

    //Toggle bool
    powered = !powered;

    //If next object exists, set it to powered
    if(ptr_next != nullptr)
    {
        (*ptr_next).togglePower();
    }

    return;
}
