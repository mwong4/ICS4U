/*
Author: Max Wong
Date Created: Mar 28, 2020
Date Updated: Mar 30, 2020
Purpose: Header file for Player class
Type: Header
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Stack.h" //Include stack class
#include "Interactable.h" //include interactable class
#include "Map.h" //Include map class

using namespace std;


class Player : public Interactable
{
    public:
        Player();
        Player(int, int, bool, Map*, int, int); //Custom constructor
        virtual ~Player();

        void toggleAutoSolver(); //Used to toggle auto solver
        char getInput(); //Get's input from user when manually controlling

        bool checkSolid(); //Returns if solid or not

        //getters/setters
        int getX() const;
        int getY() const;

    protected:

    private:
        int xCoord; //Tracks player location
        int yCoord;
        Stack *directions; //Tracks the stack of directions
        bool autoSolve; //Toggle false for manual control
        Map* ptr_map; //Pointer to map for accessing map info for movement

        bool updatePosition(char); //Checks to see if inputed move is legal and if good, Updates position of player

};

#endif // PLAYER_H
