/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 7, 2021
Purpose: Final project for ICS4U
Type: Main

TODO
-Buggy Movement
-Multi Maps
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
    //Pointers for map, initialize variables
    Interactable *wal1 = new Wall(178, 15); //Initialize wall;
    Interactable *emt1 = new Space(0, 15); //Initialize space;
    Interactable *ext1 = new Exit(69, 15, false, nullptr, 11, 1); //Initilaize exit
    Crumb crumbObj(42, 15); //Initialize crumb
    Interactable *ply1 = new Player(129, 15, 3, 4, false, nullptr, &crumbObj); //Initialize Player
    //Electronics
    Interactable *gat1 = new Gate(177, 15, false, 6, 0);
    Interactable *wir1 = new Wire(35, 15, false, gat1, 6);
    Interactable *tog1 = new Toggle(91, 15, false, wir1, 6, 93);


    Interactable* mapOne[121] = //initialize array of interactables for map
    {
        wal1, emt1, emt1, emt1, wal1, emt1, wal1, emt1, wal1, wal1, ext1,
        wal1, emt1, wal1, emt1, wal1, emt1, emt1, emt1, wal1, wal1, emt1,
        emt1, emt1, emt1, emt1, wal1, wal1, emt1, wal1, emt1, emt1, gat1,
        emt1, wal1, ply1, wal1, wal1, wal1, emt1, emt1, emt1, wal1, wir1,
        emt1, emt1, emt1, emt1, wal1, wal1, emt1, wal1, emt1, wal1, wir1,
        wal1, wal1, wal1, emt1, wal1, wal1, emt1, wal1, emt1, wal1, wir1,
        emt1, emt1, emt1, emt1, emt1, wal1, emt1, emt1, emt1, wal1, wir1,
        emt1, wal1, emt1, wal1, emt1, wal1, emt1, wal1, wal1, wal1, wir1,
        emt1, emt1, emt1, wal1, emt1, emt1, emt1, tog1, wir1, wir1, wir1,
        wal1, wal1, wal1, wal1, wal1, emt1, wal1, wal1, wal1, wal1, wal1,
        wal1, wal1, emt1, emt1, emt1, emt1, emt1, emt1, wal1, wal1, wal1
    };

    Map myMapOne(11, 11, mapOne, ext1, ply1, emt1, emt1); //initiaize map object
    (*ply1).setMap(&myMapOne); //Set map for player

    ////////////////////////////////////////////////////////////////////////////////////////////

    string input; //Input from user

    cout << "Press [1] for auto-solver, [2] for manual controls" << endl;
    cin >> input;
    if(input == "1") //Get user choice on auto vs manual
    {
        (*ply1).toggleAutoSolver();
    }

    //Gameloop, kepp running until player reaches exit
    while(!myMapOne.checkWin())
    {
        if(input != "1") //if manual, display instructions
        {
            cout << "WASD or Arrow keys to move" << endl;
        }
        (*ply1).nextTurn(); //Call function to get next turn, encapsulated
        myMapOne.printMap(); //Print map

        system("PAUSE"); //Get any input before clearing screen
        system("CLS");
    }

    cout << "You Win!" << endl;
    cout << endl << "End Program" << endl;
    return 0;
}
