/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Apr 7, 2021
Purpose: Header file for Interactable class
Type: Header
*/

#ifndef INTERACTABLE_H
#define INTERACTABLE_H

class Map;

using namespace std;

class Interactable
{
    public:
        Interactable();
        Interactable(int, int); //Custom constructor
        virtual ~Interactable();

        //General functions
        virtual bool checkSolid(); //Will go to derived class and return if solid or not

        //getters/setters
        char getSymbol() const;
        void setSymbol(char);
        int getColour() const;
        void setColour(int);

        //virtual functions for derived classes
        virtual bool getHidden() const;
        virtual void setHidden(bool);
        virtual int getX() const;
        virtual int getY() const;
        virtual void setMap(Map*);
        virtual void toggleAutoSolver(); //For player, auto solver
        virtual void nextTurn();
        virtual void togglePower(bool); //Used on all electronics to toggle power and extra stuff
        virtual void setNext(Interactable*); //set next for portal

    protected:


    private:
        char symbol; //symbol representing object
        int colour; //represents color of object when printed
};

#endif // INTERACTABLE_H
