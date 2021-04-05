/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Mar 29, 2021
Purpose: Source file for Interactable class
Type: Source
*/

#include "Interactable.h"
#include "Map.h"; //include map class

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

void Interactable::setColour(int _colour)
{
    colour = _colour;
    return;
}

bool Interactable::getHidden() const
{
    return true;
}

void Interactable::setHidden(bool _hidden)
{
    return;
}

int Interactable::getX() const
{
    return 0;
}

int Interactable::getY() const
{
    return 0;
}

void Interactable::setMap(Map *_map)
{
    return;
}

