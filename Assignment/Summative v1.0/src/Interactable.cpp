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
    colour = 15; //set color to white
}

//Custom constructor
Interactable::Interactable(int _asciiCode, int _colour)
{
    symbol = _asciiCode;
    colour = _colour;
}

Interactable::~Interactable()
{
    //dtor
}

//General functions
//Will go to derived class and return if solid or not
bool Interactable::checkSolid()
{
    return true;
}

//getters/setters
char Interactable::getSymbol() const
{
    return symbol;
}

int Interactable::getColour() const
{
    return colour;
}
