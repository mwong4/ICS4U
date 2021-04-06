/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 6, 2021
Purpose: Final project for ICS4U
Type: Main

TODO
-Buggy Movement
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
#include "Wire.h" //include wire class
#include "Gate.h" //include gate class
#include "Toggle.h" //include toggle class

using namespace std;

int main()
{
    //Basic Objects
    Wall wallObj(178, 15); //Initialize wall
    Space spaceObj(0, 15); //Initialize space
    Exit exitObj(69, 15, false, nullptr, 11, 1); //Initilaize exit
    Crumb crumbObj(42, 15); //Initialize crumb
    Player playerObj(129, 15, 3, 4, false, nullptr, &crumbObj); //Initialize Player

    //Electronics
    Gate gateObj(177, 15, false, 6, 0);
    Wire wireObj(35, 15, false, &gateObj, 6);
    Toggle toggleObj(91, 15, false, &wireObj, 6, 93);


    //Pointers for map
    Interactable *wall = &wallObj;
    Interactable *emty = &spaceObj;
    Interactable *exit = &exitObj;
    Interactable *plyr = &playerObj;
    Interactable *tog1 = &toggleObj;
    Interactable *wir1 = &wireObj;
    Interactable *gat1 = &gateObj;

    Interactable* mapOne[121] = //initialize array of interactables for map
    {
        wall, emty, emty, emty, wall, emty, wall, emty, wall, wall, exit,
        wall, emty, wall, emty, wall, emty, emty, emty, wall, wall, emty,
        emty, emty, emty, emty, wall, wall, emty, wall, emty, emty, gat1,
        emty, wall, plyr, wall, wall, wall, emty, emty, emty, wall, wir1,
        emty, emty, emty, emty, wall, wall, emty, wall, emty, wall, wir1,
        wall, wall, wall, emty, wall, wall, emty, wall, emty, wall, wir1,
        emty, emty, emty, emty, emty, wall, emty, emty, emty, wall, wir1,
        emty, wall, emty, wall, emty, wall, emty, wall, wall, wall, wir1,
        emty, emty, emty, wall, emty, emty, emty, tog1, wir1, wir1, wir1,
        wall, wall, wall, wall, wall, emty, wall, wall, wall, wall, wall,
        wall, wall, emty, emty, emty, emty, emty, emty, wall, wall, wall
    };

    Map myMap(11, 11, mapOne, exit, plyr, emty, emty); //initiaize map object
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
