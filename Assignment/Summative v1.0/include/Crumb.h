/*
Author: Max Wong
Date Created: Apr 4, 2021
Date Updated: Apr 9, 2021
Purpose: Header file for Crumb class
Type: Header
*/

#ifndef CRUMB_H
#define CRUMB_H

#include "Interactable.h" //include interactable class

using namespace std;

class Crumb : public Interactable
{
    public:
        Crumb();
        Crumb(int, int); //Custom constructor
        virtual ~Crumb();

        bool checkSolid(); //Returns if solid or not
        string getType(); //returns if space or gate

    protected:

    private:
};

#endif // CRUMB_H
