/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Header file for Interactable class
Type: Header
*/

#ifndef INTERACTABLE_H
#define INTERACTABLE_H


class Interactable
{
    public:
        Interactable();
        Interactable(int, int); //Custom constructor
        virtual ~Interactable();

        //getters/setters
        char getSymbol() const;
        int getColour() const;

    protected:

    private:
        char symbol; //symbol representing object
        int colour; //represents color of object when printed
};

#endif // INTERACTABLE_H
