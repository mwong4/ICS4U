/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 9, 2021
Purpose: Source file for gate class
Type: Source
*/

#include "Gate.h"
#include <iostream>

Gate::Gate() : Electronic()
{
    //ctor
    alternateSymbol = 0;
}

//Custom constructor
Gate::Gate(int _symbol, int _colour, bool _powered, int _altColour, int _altSymbol) : Electronic(_symbol, _colour, _powered, nullptr, _altColour)
{
    alternateSymbol = _altSymbol;

    if(_powered) //if door starts powered, auto toggle
    {
        togglePower(true);
        powered = true;
    }
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
void Gate::togglePower(bool _portal)
{
    alternateSymbol = swapSymbol(alternateSymbol); //Swap symbol

    Electronic::togglePower(true); //Toggle bool

    return;
}

string Gate::getType()
{
    return "Gate";
}

void Gate::setAltSym(char _input)
{
    alternateSymbol = _input; //set input to alt char
    return;
}
