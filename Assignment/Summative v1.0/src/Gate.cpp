/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 7, 2021
Purpose: Source file for gate class
Type: Source
*/

#include "Gate.h"

Gate::Gate() : Electronic()
{
    //ctor
    alternateSymbol = 0;
}

//Custom constructor
Gate::Gate(int _symbol, int _colour, bool _powered, int _altColour, int _altSymbol) : Electronic(_symbol, _colour, _powered, nullptr, _altColour)
{
    alternateSymbol = _altSymbol;
}

Gate::~Gate()
{
    //dtor
}

//Returns solidity status, based on if powered
bool Gate::checkSolid()
{
    return !powered;
}

//Toggles power and other stuff
void Gate::togglePower()
{
    char tempSymbol; //Used for swapping symbols

    //Swap symbol
    tempSymbol = alternateSymbol; //Save alternate colour
    alternateSymbol = getSymbol(); //Save current colour into alt
    setSymbol(tempSymbol); //Set as as colour

    //Toggle bool
    powered = !powered;

    return;
}
