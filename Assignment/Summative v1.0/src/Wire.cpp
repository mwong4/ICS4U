#include "Wire.h"

Wire::Wire() : Electronic()
{
    //ctor
}

//Custom constructor
Wire::Wire(int _symbol, int _colour, bool _powered, Electronic* _next, int _altColour) : Electronic(_symbol, _colour, _powered, _next, _altColour)
{

}

Wire::~Wire()
{
    //dtor
}

//Returns solidity status
bool Wire::checkSolid()
{
    return true;
}

//Toggles power and other stuff
void Wire::toggle()
{
    int tempInt; //Used for swapping colours

    //Swap colours
    tempInt = altColour; //Save alternate colour
    altColour = getColour(); //Save current colour into alt
    setColour(tempInt); //Set as as colour

    //Toggle bool
    powered = true;

    //If next object exists, set it to powered
    if(ptr_next != nullptr)
    {
        (*ptr_next).toggle();
    }


}
