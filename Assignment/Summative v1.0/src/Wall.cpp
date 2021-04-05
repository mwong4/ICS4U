/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Mar 26, 2021
Purpose: Source file for Wall class
Type: Source
*/

#include "Wall.h"
#include "Interactable.h" //Include parent class

Wall::Wall() : Interactable()
{
    //ctor
}

//Custom constructor
Wall::Wall(int _asciiCode, int _colour) : Interactable(_asciiCode, _colour)
{

}

Wall::~Wall()
{
    //dtor
}

bool Wall::checkSolid()
{
    return true;
}
