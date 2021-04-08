/*
Author: Max Wong
Date Created: Apr 7, 2021
Date Updated: Apr 7, 2021
Purpose: Source file for portal class
Type: Source
*/

#include "Portal.h"

Portal::Portal() : Electronic()
{
    //ctor
    xCoord = 0;
    yCoord = 0;
    opX = 0;
    opY = 0;
}

//Custom constructor
Portal::Portal(int _symbol, int _colour, bool _powered, Interactable* _next, int _altColour, int _x, int _y, int _opX, int _opY) : Electronic(_symbol, _colour, _powered, _next, _altColour)
{
    xCoord = _x;
    yCoord = _y;
    opX = _opX;
    opY = _opY;
}

Portal::~Portal()
{
    //dtor
}

//Returns solidity status
bool Portal::checkSolid()
{
    return !powered;
}

//Toggles power and other stuff
void Portal::togglePower(bool _portal)
{
    altColour = swapColour(altColour);//Swap colours
    Electronic::togglePower(true); //Toggle bool

    //If next object exists, set it to powered
    if(ptr_next != nullptr && _portal)
    {
        (*ptr_next).togglePower(false);
    }
}

//getters/setters
int Portal::getX() const
{
    return opX;
}

int Portal::getY() const
{
    return opY;
}

