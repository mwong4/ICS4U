/*
Author: Max Wong
Date Created: Apr 5, 2021
Date Updated: Apr 5, 2021
Purpose: Header file for Electronic class
Type: Header
*/

#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include "Interactable.h" //Include interactable class

using namespace std;

class Electronic : public Interactable
{
    public:
        Electronic();
        Electronic(int, int, bool, Interactable*, int); //Custom constructor
        virtual ~Electronic();

        virtual bool checkSolid(); //returns solidity
        virtual void togglePower(); //Used on all electronics to toggle power and extra stuff

    protected:
        bool powered; //Store if component is powered
        int altColour; //Alternate colour when powered
        Interactable *ptr_next; //Connects all electronics to a switch

    private:

};

#endif // ELECTRONIC_H
