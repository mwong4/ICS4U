/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Apr 9, 2021
Purpose: Header file for Space class
Type: Header
*/

#ifndef SPACE_H
#define SPACE_H
#include <iostream>

#include "Interactable.h" //Include parent class


class Space : public Interactable
{
    public:
        Space();
        Space(int, int); //Custom constructor
        virtual ~Space();

        bool checkSolid(); //Returns if solid or not

    protected:

    private:
};

#endif // SPACE_H
