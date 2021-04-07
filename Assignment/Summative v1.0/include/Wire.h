/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 5, 2021
Purpose: Header file for wire class
Type: Header
*/

#ifndef WIRE_H
#define WIRE_H

#include "Electronic.h" //include electronic class

using namespace std;

class Wire : public Electronic
{
    public:
        Wire();
        Wire(int, int, bool, Interactable*, int); //Custom constructor
        virtual ~Wire();

        bool checkSolid(); //Returns solidity status
        void togglePower(); //Toggles power and other stuff

    protected:

    private:
};

#endif // WIRE_H
