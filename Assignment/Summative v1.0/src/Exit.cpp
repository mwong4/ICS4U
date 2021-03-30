/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Source file for Exit class
Type: Source
*/

#include "Exit.h"
#include "Interactable.h"
#include "Map.h" //include map class

Exit::Exit() : Interactable()
{
    //ctor
    hidden = false;
    ptr_next = nullptr;
}

//Custom constructor
Exit::Exit(int _asciiCode, int _colour, bool _hidden, Map* _next, int _xCoord, int _yCoord) : Interactable(_asciiCode, _colour)
{
    hidden = _hidden;
    ptr_next = _next;
    xCoord = _xCoord;
    yCoord = _yCoord;
}

Exit::~Exit()
{
    //dtor
}

bool Exit::checkSolid()
{
    return false;
}

//Getters/Setters
Map* Exit::getNextMap() const
{
    return ptr_next;
}

int Exit::getX() const
{
    return xCoord;
}

int Exit::getY() const
{
    return yCoord;
}

bool Exit::getHidden() const
{
    return hidden;
}

void Exit::setHidden(bool _hidden)
{
    hidden = _hidden;
    return;
}
