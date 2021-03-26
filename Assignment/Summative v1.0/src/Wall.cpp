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
