/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 9, 2021
Purpose: Final project for ICS4U
Type: Main

Sources
-"https://theasciicode.com.ar/" for ASCII character chart
-"https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c" for color
-"http://www.cplusplus.com/forum/beginner/9503/" For WASD input system

Credit to Mr. Maloley for teaching CS
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
#include "Portal.h" //include portal class

using namespace std;

void play(Map*, Interactable*, string); //Used to play game, contains game loop

int main()
{
    //Pointers for map, initialize variables
    Interactable *wall = new Wall(178, 15); //Initialize wall;
    Interactable *emty = new Space(0, 15); //Initialize space;
    Crumb crumbObj(42, 15); //Initialize crumb

    ///Map 1 Stuff
    Interactable *ext1 = new Exit(69, 15, false, 11, 1); //Initilaize exit
    Interactable *ply1 = new Player(129, 15, 3, 4, false, nullptr, &crumbObj); //Initialize Player
    //Electronics
    Interactable *gat1 = new Gate(177, 15, false, 6, 0);
    Interactable *wir1 = new Wire(35, 15, false, gat1, 6);
    Interactable *tog1 = new Toggle(91, 15, false, wir1, nullptr, 6, 93);

    Interactable* mapOne[121] = //initialize array of interactables for map
    {
        wall, emty, emty, emty, wall, emty, wall, emty, wall, wall, ext1,
        wall, emty, wall, emty, wall, emty, emty, emty, wall, wall, emty,
        emty, emty, emty, emty, wall, wall, emty, wall, emty, emty, gat1,
        emty, wall, ply1, wall, wall, wall, emty, emty, emty, wall, wir1,
        emty, emty, emty, emty, wall, wall, emty, wall, emty, wall, wir1,
        wall, wall, wall, emty, wall, wall, emty, wall, emty, wall, wir1,
        emty, emty, emty, emty, emty, wall, emty, emty, emty, wall, wir1,
        emty, wall, emty, wall, emty, wall, emty, wall, wall, wall, wir1,
        emty, emty, emty, wall, emty, emty, emty, tog1, wir1, wir1, wir1,
        wall, wall, wall, wall, wall, emty, wall, wall, wall, wall, wall,
        wall, wall, emty, emty, emty, emty, emty, emty, wall, wall, wall
    };

    Map myMapOne(11, 11, mapOne, ext1, ply1, emty, emty); //initiaize map object
    (*ply1).setMap(&myMapOne); //Set map for player

    ///Map 2 Stuff
    Interactable *ext2 = new Exit(69, 15, false, 2, 2); //Initilaize exit
    Interactable *ply2 = new Player(129, 15, 2, 11, false, nullptr, &crumbObj); //Initialize Player
    //Electronics
    Interactable *gat2 = new Gate(177, 6, true, 15, 0); //Initilaize doors
    Interactable *gat3 = new Gate(177, 15, false, 2, 0);
    Interactable *gat4 = new Gate(177, 15, false, 1, 0);
    Interactable *gat5 = new Gate(177, 15, false, 1, 0);

    Interactable *ptl1 = new Portal(64, 15, false, nullptr, 6, 6, 9, 11, 4); //initialize portals
    Interactable *ptl2 = new Portal(64, 15, false, ptl1, 6, 11, 4, 6, 9);

    Interactable *wir3 = new Wire(35, 15, false, gat3, 2); //initialize wire
    Interactable *wir4 = new Wire(35, 15, false, gat4, 1); //initialize wire

    Interactable *tog2 = new Toggle(91, 15, false, gat2, ptl1, 6, 93); //initialize toggles
    Interactable *tog3 = new Toggle(91, 15, false, wir3, nullptr, 2, 93);
    Interactable *tog4 = new Toggle(91, 15, false, wir4, gat5, 1, 93);
    (*ptl1).setNext(ptl2); //Set next for portal 1

    Interactable* mapTwo[144] = //initialize array of interactables for map
    {
        wall, wall, wall, wall, wir4, wir4, wir4, wir4, wir4, wir4, wir4, wall,
        wall, ext2, emty, emty, gat4, emty, wall, emty, emty, emty, tog4, wall,
        wall, emty, emty, emty, wall, emty, wall, emty, emty, emty, emty, wall,
        wall, emty, emty, emty, wall, emty, wall, emty, emty, emty, ptl2, wall,
        wall, wall, wall, wall, wall, gat3, wir3, wir3, wir3, wall, wall, wall,
        wall, emty, emty, emty, emty, emty, wall, wall, tog3, wall, wall, wall,
        wall, emty, emty, emty, emty, gat5, wall, emty, emty, emty, emty, wall,
        wall, emty, emty, emty, emty, tog2, wall, emty, emty, emty, emty, wall,
        wall, emty, emty, emty, emty, ptl1, wall, emty, emty, emty, emty, wall,
        wall, emty, emty, emty, emty, emty, gat2, emty, emty, emty, emty, wall,
        wall, ply2, emty, emty, emty, emty, wall, emty, emty, emty, emty, wall,
        wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall
    };

    Map myMapTwo(12, 12, mapTwo, ext2, ply2, emty, emty); //initiaize map object
    (*ply2).setMap(&myMapTwo); //Set map for player

    ////////////////////////////////////////////////////////////////////////////////////////////

    string input; //Input from user

    cout << "Press [1] for auto-solver, [2] for manual controls" << endl;
    cin >> input;
    if(input == "1") //Get user choice on auto vs manual
    {
        (*ply1).toggleAutoSolver(); //toggle auto solvers
        (*ply2).toggleAutoSolver();
    }

    play(&myMapOne, ply1, input); //Call function to play map 1
    play(&myMapTwo, ply2, input); //Call function to play map 2

    cout << "You Win!" << endl;
    cout << endl << "End Program" << endl;
    system("PAUSE");
    return 0;
}

//Used to play game, contains game loop
void play(Map* _map, Interactable* _player, string _controls)
{

    //Gameloop for level 1, keep running until player reaches exit
    while(!(*_map).checkWin())
    {
        if(_controls != "1") //if manual, display instructions
        {
            cout << "WASD keys to move" << endl;
        }
        (*_player).nextTurn(); //Call function to get next turn, encapsulated
        system("CLS"); //Clear console
        (*_map).printMap(); //Print map
    }
}
