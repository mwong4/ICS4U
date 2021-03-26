/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Header file for Map class
Type: Header
*/

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <windows.h> //For Colour

#include "Interactable.h" //include interchangable class

using namespace std;


class Map
{
    public:
        Map();
        Map(int, int, Interactable*[]); //Custom constructor
        virtual ~Map();

        //General Functions
        void printMap() const; //For printing out map
        Interactable* getInteractable(const int, const int) const; //To get the interactable on a certain spot

    protected:

    private:
        int width; //represents width of array
        int height; //represents height of array
        Interactable *mapArray[100]; //double array containing whole map

};

#endif // MAP_H
