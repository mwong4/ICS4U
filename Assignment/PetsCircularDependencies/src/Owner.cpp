/*
Author: Max Wong
Date Created: Feb 26, 2020
Date Updated: Feb 26, 2020
Purpose: Source file for owner class
Type: Source
*/

#include "Owner.h"

Owner::Owner()
{
    //ctor
    name = "Unknown"; //Set name and pet to null values
    pet = nullptr;
}

//Custom constructor
Owner::Owner(string _name, Pet *_pet)
{
    name = _name; //Set name and pet pointer
    pet = _pet;

    return;
}

Owner::~Owner()
{
    //dtor
}

//For displaying owner data
void Owner::displayOwner()
{
    cout << "-" << name << endl;
    return;
}

//getters and setters
void Owner::setPet(Pet* _pet)
{
    pet = _pet;
    return;
}
