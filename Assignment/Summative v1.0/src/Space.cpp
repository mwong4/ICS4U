/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Source file for Space class
Type: Source
*/

#include "Space.h"
#include "Interactable.h" //Include parent class

Space::Space() : Interactable()
{
    //ctor
}

//Custom constructor
Space::Space(int _asciiCode, int _colour) : Interactable(_asciiCode, _colour)
{

}

Space::~Space()
{
    //dtor
}

bool Space::checkSolid()
{
    return false;
}
