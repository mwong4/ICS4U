/*
Author: Max Wong
Date Created: Feb 26, 2020
Date Updated: Feb 26, 2020
Purpose: Header file for owner class
Type: Header
*/

#ifndef OWNER_H
#define OWNER_H
#include "Pet.h" //Include pet header file
#include <iostream> //For strings

using namespace std;

class Owner
{
    public:
        Owner();
        Owner(string, Pet*); //Custom constructor
        virtual ~Owner();

        //General Methods
        void displayOwner(); //For displaying owner data

        //getters and setters
        void setPet(Pet*);

    protected:

    private:
        string name; //Name of owner
        Pet *pet; //Pet of owner
};

#endif // OWNER_H
