/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Mar 26, 2021
Purpose: Header file for Wall class
Type: Header
*/

#ifndef WALL_H
#define WALL_H
#include "Interactable.h"


class Wall : public Interactable
{
    public:
        Wall();
        Wall(int, int); //Custom constructor
        virtual ~Wall();

        bool checkSolid(); //Returns if solid or not

    protected:

    private:
};

#endif // WALL_H
