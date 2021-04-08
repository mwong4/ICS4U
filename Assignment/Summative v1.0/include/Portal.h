/*
Author: Max Wong
Date Created: Apr 7, 2021
Date Updated: Apr 7, 2021
Purpose: Header file for portal class
Type: Header
*/

#ifndef PORTAL_H
#define PORTAL_H
#include <iostream>

#include "Electronic.h" //include electronic class

using namespace std;

class Portal : public Electronic
{
    public:
        Portal();
        Portal(int, int, bool, Interactable*, int, int, int, int, int); //Custom constructor
        virtual ~Portal();

        bool checkSolid(); //Returns solidity status
        void togglePower(bool); //Toggles power and other stuff

        //getters/setters
        int getX() const;
        int getY() const;

    protected:

    private:
        int xCoord; //stores portal position
        int yCoord;
        int opX; //linked portal position
        int opY;
};

#endif // PORTAL_H
