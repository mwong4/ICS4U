/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 9, 2021
Purpose: Header file for gate class
Type: Header
*/

#ifndef GATE_H
#define GATE_H

#include "Electronic.h" //include electronic class

using namespace std;

class Gate : public Electronic
{
    public:
        Gate();
        Gate(int, int, bool, int, int); //Custom constructor
        virtual ~Gate();

        bool checkSolid(); //Returns solidity status
        void togglePower(bool); //Toggles power and other stuff
        string getType(); //returns if space or gate
        void setAltSym(char); //set's alt symbol

    protected:

    private:
        char alternateSymbol;
};

#endif // GATE_H
