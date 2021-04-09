/*
Author: Max Wong
Date Created: Apr 4, 2021
Date Updated: Apr 9, 2021
Purpose: Source file for Crumb class
Type: Source
*/

#include "Crumb.h"

Crumb::Crumb()
{
    //ctor
}

//Custom constructor
Crumb::Crumb(int _symbol, int _colour) : Interactable(_symbol, _colour)
{

}

Crumb::~Crumb()
{
    //dtor
}

//Returns if solid or not
bool Crumb::checkSolid()
{
    return false;
}

string Crumb::getType()
{
    return "Space";
}
