/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 9, 2021
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
Electronic::Electronic(int _symbol, int _colour, bool _powered, Interactable* _next, int _altColour) : Interactable(_symbol, _colour)
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
void Electronic::togglePower(bool _portal)
{
    powered = !powered; //toggle power
    return;
}

//For swapping colour
int Electronic::swapColour(int _altColour)
{
    int tempInt; //Used for swapping colours
    //Swap colours
    tempInt = _altColour; //Save alternate colour
    _altColour = getColour(); //Save current colour into alt
    setColour(tempInt); //Set as as colour

    return _altColour;
}

//For swapping symbol
char Electronic::swapSymbol(char _alternateSymbol)
{
    char tempSymbol; //Used for swapping symbols
    //Swap symbol
    tempSymbol = _alternateSymbol; //Save alternate symbol
    _alternateSymbol = getSymbol(); //Save current symbol into alt
    setSymbol(tempSymbol); //Set as as symbol

    return _alternateSymbol;
}

//getters/setters
void Electronic::setNext(Interactable* _next)
{
    ptr_next = _next;
    return;
}

int Electronic::getX() const
{
    return 111;
}

int Electronic::getY() const
{
    return 111;
}

string Electronic::getType() //returns if space or gate
{
    return " ";
}

void Electronic::setAltSym(char) //set's alt symbol
{
    return;
}
