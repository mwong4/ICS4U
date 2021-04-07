/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 5, 2021
Purpose: Header file for toggle class
Type: Header
*/

#ifndef TOGGLE_H
#define TOGGLE_H

#include "Electronic.h" //include electronic class

using namespace std;

class Toggle : public Electronic
{
    public:
        Toggle();
        Toggle(int, int, bool, Interactable*, int, int); //Custom constructor
        virtual ~Toggle();

        bool checkSolid(); //Returns solidity status
        void togglePower(); //Toggles power and other stuff

    protected:

    private:
        char alternateSymbol;
};

#endif // TOGGLE_H
