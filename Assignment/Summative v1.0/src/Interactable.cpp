/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Apr 9, 2021
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

void Interactable::setSymbol(char _symbol)
{
    symbol = _symbol;
    return;
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
    return 999;
}

int Interactable::getY() const
{
    return 999;
}

void Interactable::setMap(Map *_map)
{
    return;
}

void Interactable::toggleAutoSolver() //For player, auto solver
{
    return;
}

void Interactable::nextTurn()
{
    return;
}

void Interactable::togglePower(bool _portal) //Used on all electronics to toggle power and extra stuff
{
    return;
}

void Interactable::setNext(Interactable* _next) //set next for portal
{
    return;
}

string Interactable::getType() //returns if space or gate
{
    return " ";
}

void Interactable::setAltSym(char) //set's alt symbol
{
    return;
}


