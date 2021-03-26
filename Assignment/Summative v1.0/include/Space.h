/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Header file for Space class
Type: Header
*/

#ifndef SPACE_H
#define SPACE_H
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
