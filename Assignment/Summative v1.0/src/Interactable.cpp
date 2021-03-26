#include "Interactable.h"

Interactable::Interactable()
{
    //ctor
    symbol = 0;
}

//Custom constructor
Interactable::Interactable(int _asciiCode)
{
    symbol = _asciiCode;
}

Interactable::~Interactable()
{
    //dtor
}

char Interactable::getSymbol() const
{
    return symbol;
}
