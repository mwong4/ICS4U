/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 5, 2021
Purpose: Source file for Electronic class
Type: Source
*/

#include "Electronic.h"

Electronic::Electronic() : Interactable()
{
    //ctor
    powered = false;
    ptr_next = nullptr;
    altColour = 15;
}

//Custom constructor
Electronic::Electronic(int _symbol, int _colour, bool _powered, Electronic* _next, int _altColour) : Interactable(_symbol, _colour)
{
    powered = _powered;
    ptr_next = _next;
    altColour = _altColour;
}

Electronic::~Electronic()
{
    //dtor
}

//returns solidity
bool Electronic::checkSolid()
{
    return true;
}

//Used on all electronics to toggle power and extra stuff
void Electronic::togglePower()
{
    powered = !powered; //toggle power
    return;
}
