/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 5, 2021
Purpose: Final project for ICS4U
Type: Main

TODO
-Toggle

-Set up main
-Button Toggle
-Portal

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
    Exit exitObj(64, 15, false, nullptr, 10, 2); //Initilaize exit
    Crumb crumbObj(42, 15); //Initialize crumb
    Player playerObj(168, 15, 3, 4, false, nullptr, &crumbObj); //Initialize Player

    Interactable *wall = &wallObj;
    Interactable *emty = &spaceObj;
    Interactable *exit = &exitObj;
    Interactable *plyr = &playerObj;

    Interactable* mapOne[100] = //initialize array of interactables for map
    {
        wall, emty, emty, emty, wall, emty, wall, wall, wall, wall,
        wall, emty, wall, emty, wall, emty, emty, emty, emty, exit,
        emty, emty, emty, emty, wall, wall, emty, wall, wall, wall,
        emty, wall, plyr, wall, wall, wall, emty, emty, emty, wall,
        emty, emty, emty, emty, wall, wall, emty, wall, emty, wall,
        wall, wall, wall, emty, wall, wall, emty, wall, emty, wall,
        emty, emty, emty, emty, emty, wall, emty, emty, emty, wall,
        emty, wall, emty, wall, emty, wall, emty, wall, wall, wall,
        emty, emty, emty, wall, emty, emty, emty, wall, wall, wall,
        wall, wall, wall, wall, wall, wall, wall, wall, wall, wall
    };

    Map myMap(10, 10, mapOne, exit, plyr, emty); //initiaize map object
    playerObj.setMap(&myMap); //Set map for player

    ////////////////////////////////////////////////////////////////////////////////////////////

    string input; //Input from user

    cout << "Press [1] for auto-solver, [2] for manual controls" << endl;
    cin >> input;
    if(input == "1") //Get user choice on auto vs manual
    {
        playerObj.toggleAutoSolver();
    }

    //Gameloop, kepp running until player reaches exit
    while(!myMap.checkWin())
    {
        if(input != "1") //if manual, display instructions
        {
            cout << "WASD or Arrow keys to move" << endl;
        }
        playerObj.nextTurn(); //Call function to get next turn, encapsulated
        myMap.printMap(); //Print map

        system("PAUSE"); //Get any input before clearing screen
        system("CLS");
    }

    cout << "You Win!" << endl;
    cout << endl << "End Program" << endl;
    return 0;
}
