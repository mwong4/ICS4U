/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Mar 26, 2021
Purpose: Header file for Exit class
Type: Header
*/

#ifndef EXIT_H
#define EXIT_H
#include "Interactable.h"

class Map;

class Exit : public Interactable
{
    public:
        Exit();
        Exit(int, int, bool, Map*, int, int); //Custom constructor
        virtual ~Exit();

        bool checkSolid(); //Returns if solid or not

        //Getters/Setters
        Map* getNextMap() const;
        int getX() const;
        int getY() const;
        bool getHidden() const;
        void setHidden(bool);

    protected:

    private:
        bool hidden; //stores if exit is hidden or not
        Map* ptr_next; //Stores the next map
        int xCoord; //Stores position of exit
        int yCoord;
};

#endif // EXIT_H
