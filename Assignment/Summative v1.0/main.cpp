/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Mar 30, 2020
Purpose: Final project for ICS4U
Type: Main

TODO
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
#include "Exit.h" //include exit class
#include "Player.h" //include player class

using namespace std;

int main()
{
    Interactable *wall = new Wall(178, 15); //Initialize wall
    Interactable *emty = new Space(0, 15); //Initialize space
    Interactable *exit = new Exit(64, 15, false, nullptr, 10, 10); //Initilaize exit
    Interactable *plyr = new Player(2, 2, false, nullptr, 169, 15); //Initialize Player

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
        wall, emty, emty, wall, wall, wall, wall, wall, emty, exit,
        wall, emty, wall, wall, wall, wall, wall, wall, wall, wall
    };

    Map myMap(10, 10, mapOne, exit, plyr, emty); //initiaize map object
    (*plyr).setMap(&myMap); //Set map for player

    while(true)
    {
        myMap.printMap(); //Print map
        cout << "Container: " << (*myMap.getContainer()).getSymbol() << endl;
        //(*plyr).updatePosition((*plyr).getInput());

    }


    cout << endl << "End Program" << endl;
    return 0;
}
