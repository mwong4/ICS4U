/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Apr 4, 2020
Purpose: Final project for ICS4U
Type: Main

TODO
-Set up auto-solver
-Implement backtracking
-Implement with crumbs

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
#include "Crumb.h" //include crumb class

using namespace std;

int main()
{
    Wall wallObj(178, 15); //Initialize wall
    Space spaceObj(0, 15); //Initialize space
    Exit exitObj(64, 15, false, nullptr, 10, 10); //Initilaize exit
    Crumb crumbObj(42, 15); //Initialize crumb
    Player playerObj(168, 15, 2, 2, false, nullptr, &crumbObj); //Initialize Player

    Interactable *wall = &wallObj;
    Interactable *emty = &spaceObj;
    Interactable *exit = &exitObj;
    Interactable *plyr = &playerObj;

    Interactable* mapOne[100] = //initialize array of interactables for map
    {
        wall, wall, wall, wall, wall, wall, emty, wall, wall, wall,
        wall, plyr, wall, wall, wall, emty, emty, emty, wall, wall,
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
    playerObj.setMap(&myMap); //Set map for player

    while(true)
    {
        //cout << "Is Solid: " << playerObj.updatePosition(playerObj.getInput()) << endl;
        playerObj.autoSolver();
        myMap.printMap(); //Print map
        cout << playerObj.getX() << "," << playerObj.getY() << endl;
        cout << "Container: " << (*myMap.getContainer()).getSymbol() << endl;
        system("PAUSE");
        system("CLS");
    }



    cout << endl << "End Program" << endl;
    return 0;
}
