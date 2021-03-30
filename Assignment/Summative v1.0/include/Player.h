/*
Author: Max Wong
Date Created: Mar 28, 2020
Date Updated: Mar 29, 2020
Purpose: Header file for Player class
Type: Header
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Stack.h" //Include stack class
#include "Interactable.h" //include interactable class

using namespace std;


class Player : public Interactable
{
    public:
        Player();
        Player(int, int, bool); //Custom constructor
        virtual ~Player();

        void toggleAutoSolver(); //Used to toggle auto solver
        char getInput(); //Get's input from user when manually controlling

        //getters/setters
        int getX() const;
        int getY() const;

    protected:

    private:
        int xCoord; //Tracks player location
        int yCoord;
        Stack *directions; //Tracks the stack of directions
        bool autoSolve; //Toggle false for manual control

        bool checkValid() const; //Checks to see if inputed move is legal
        void updatePosition(); //Updates position of player

};

#endif // PLAYER_H
