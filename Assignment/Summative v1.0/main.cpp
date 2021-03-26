/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Mar 26, 2020
Purpose: Final project for ICS4U
Type: Main
*/

#include <iostream>
#include "Map.h" //include map class
#include "Interactable.h" //include interactable class

using namespace std;

int main()
{
    Interactable *wall = new Interactable(178); //Initialize wall
    Interactable *emty = new Interactable(0); //Initialize wall

    Interactable* mapOne[100] = //initialize array of interactables for map
    {
        wall, wall, wall, wall, wall, wall, emty, wall, wall, wall,
        wall, emty, wall, wall, wall, emty, emty, emty, wall, wall,
        wall, emty, emty, emty, emty, emty, wall, emty, wall, wall,
        wall, emty, wall, emty, wall, wall, wall, emty, wall, wall,
        wall, emty, wall, emty, emty, emty, emty, emty, wall, wall,
        emty, emty, wall, wall, emty, wall, wall, emty, wall, wall,
        wall, emty, emty, wall, emty, wall, wall, emty, emty, wall,
        wall, wall, emty, emty, emty, wall, wall, wall, emty, wall,
        wall, emty, emty, wall, wall, wall, wall, wall, emty, emty,
        wall, emty, wall, wall, wall, wall, wall, wall, wall, wall
    };

    Map myMap(10, 10, mapOne); //initiaize map object

    myMap.printMap(); //Print map


    cout << "End Program" << endl;
    return 0;
}
