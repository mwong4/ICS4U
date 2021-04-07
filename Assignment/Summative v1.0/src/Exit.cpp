/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Mar 26, 2021
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
}

//Custom constructor
Exit::Exit(int _asciiCode, int _colour, bool _hidden, int _xCoord, int _yCoord) : Interactable(_asciiCode, _colour)
{
    hidden = _hidden;
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
