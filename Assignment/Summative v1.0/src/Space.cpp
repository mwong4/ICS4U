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
