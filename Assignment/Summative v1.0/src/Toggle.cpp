/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 7, 2021
Purpose: Source file for toggle class
Type: Source
*/

#include "Toggle.h"

Toggle::Toggle() : Electronic()
{
    //ctor
    alternateSymbol = 0;
    ptr_secondElectronic = nullptr;
}

//Custom constructor
Toggle::Toggle(int _symbol, int _colour, bool _powered, Interactable* _next, Interactable* _nextTwo, int _altColour, int _altSymbol) : Electronic(_symbol, _colour, _powered, _next, _altColour)
{
    alternateSymbol = _altSymbol;
    ptr_secondElectronic = _nextTwo;
}

Toggle::~Toggle()
{
    //dtor
}

//Returns solidity status, based on if powered
bool Toggle::checkSolid()
{
    return false;
}

//Toggles power and other stuff
void Toggle::togglePower(bool _portal)
{
    alternateSymbol = swapSymbol(alternateSymbol); //Swap symbol
    altColour = swapColour(altColour);//Swap colours
    Electronic::togglePower(true); //Toggle bool

    //If next objects exists, set it to powered
    if(ptr_next != nullptr)
    {
        (*ptr_next).togglePower(true);
    }
    if(ptr_secondElectronic != nullptr)
    {
        (*ptr_secondElectronic).togglePower(true);
    }
    return;
}
