/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Source file for Interactable class
Type: Source
*/

#include "Interactable.h"

Interactable::Interactable()
{
    //ctor
    symbol = 0;
}

//Custom constructor
Interactable::Interactable(int _asciiCode)
{
    symbol = _asciiCode;
}

Interactable::~Interactable()
{
    //dtor
}

//getters/setters

char Interactable::getSymbol() const
{
    return symbol;
}
