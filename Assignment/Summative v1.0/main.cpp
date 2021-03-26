/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Mar 26, 2020
Purpose: Final project for ICS4U
Type: Main

TODO
-Set up exit
-Set up player (Manual)
-Set up crumb
-Set up auto-solver

-Set up basic electronics
-Set up main
-Set up advanced electronics

Sources
-"https://theasciicode.com.ar/" for ASCII character chart
-"https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c" for color
*/

//Included libraries
#include <iostream>

#include "Map.h" //include map class
#include "Interactable.h" //include interactable class
#include "Wall.h" //include wall class
#include "Space.h" //include space class

using namespace std;

int main()
{
    Interactable *wall = new Wall(178, 15); //Initialize wall
    Interactable *emty = new Space(0, 15); //Initialize wall

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


    cout << endl << "End Program" << endl;
    return 0;
}
