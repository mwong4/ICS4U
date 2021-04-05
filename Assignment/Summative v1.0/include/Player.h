/*
Author: Max Wong
Date Created: Mar 28, 2020
Date Updated: Apr 5, 2020
Purpose: Header file for Player class
Type: Header
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Stack.h" //Include stack class
#include "Interactable.h" //include interactable class
#include "Map.h" //Include map class
#include "Crumb.h" //Include crumb class

using namespace std;


class Player : public Interactable
{
    public:
        Player();
        Player(int, int, int, int, bool, Map*, Crumb*); //Custom constructor
        virtual ~Player();

        void toggleAutoSolver(); //Used to toggle auto solver

        int getInput(); //Get's input from user when manually controlling
        bool checkSolid(); //Returns if solid or not
        bool updatePosition(int, bool); //Checks to see if inputed move is legal and if good, Updates position of player
        void loadStack(int); //Loads stack exlucing char inputted
        int getOpposite(int); //Returns the opposite direction of input char
        void autoSolver(); //Remote control for user, called on each step aotu-taken by algorithm

        //getters/setters
        int getX() const;
        int getY() const;
        void setMap(Map*);

    protected:

    private:
        int xCoord; //Tracks player location
        int yCoord;
        Stack *directions; //Tracks the stack of directions
        bool autoSolve; //Toggle false for manual control
        Map* ptr_map; //Pointer to map for accessing map info for movement
        Crumb* ptr_crumb; //Pointer to crumb
};

#endif // PLAYER_H
