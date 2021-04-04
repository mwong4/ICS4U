/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 30, 2020
Purpose: Header file for Map class
Type: Header
*/

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <windows.h> //For Colour

#include "Interactable.h" //include interactable class
#include "Exit.h" //include exit class

using namespace std;

class Map
{
    public:
        Map();
        Map(int, int, Interactable*[], Interactable*, Interactable*, Interactable*); //Custom constructor
        virtual ~Map();

        //General Functions
        void printMap() const; //For printing out map
        Interactable* getInteractable(const int, const int) const; //To get the interactable on a certain spot
        Interactable** getInteractableP(const int, const int); //Return double pointer
        void swapInteractable(Interactable**, Interactable**); //In charge of swapping two pointers of pointers in the map
        bool checkWin() const; //used to check and see if player is at exit

        //getters/setters
        int getWidth() const;
        int getHeight() const;
        Interactable* getContainer() const;
        Interactable** getContainerP();
        void setContainer(Interactable*);

    protected:

    private:
        int width; //represents width of array
        int height; //represents height of array
        Interactable *mapArray[100]; //double array containing whole map
        Interactable *ptr_mazeExit; //Pointer storing the exit
        Interactable *ptr_player; //Pointer storing the player
        Interactable *ptr_container; //When player is moving around, represents what is under player's feet
};

#endif // MAP_H
