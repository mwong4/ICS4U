/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 30, 2020
Purpose: Source file for Map class
Type: Source
*/

#include "Map.h"
#include "Interactable.h"

Map::Map()
{
    //ctor
    width = 10;
    height = 10;
    ptr_mazeExit = nullptr;
    ptr_player = nullptr;
    ptr_container = nullptr;
    for(int i = 0; i < 100; i++) //Set whole map to null by default
    {
        mapArray[i] = nullptr;
    }
}

//Custom constructor
Map::Map(int _width, int _height, Interactable *_map[], Interactable* _exit, Interactable* _player, Interactable* _container)
{
    width = _width;
    height = _height;
    ptr_mazeExit = _exit;
    ptr_player = _player;
    ptr_container = _container;

    //set class var to input
    for(int i = 0; i < 100; i++) //go through whole 2d array
    {
        mapArray[i] = _map[i]; //set each spot
    }
}

Map::~Map()
{
    //dtor
}

//For printing out map
void Map::printMap() const
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for(int i = 1; i < 101; i++) //go through whole 2d array
    {
         SetConsoleTextAttribute(hConsole, (*mapArray[i-1]).getColour()); //Set colour based on colour property
        if(mapArray[i-1] == ptr_mazeExit) //Check if pointer is exit
        {
            if((*ptr_mazeExit).getHidden()) //If is exit and check if hidden is false
            {
                cout << " ";
            }
            else
            {
                cout << (*mapArray[i-1]).getSymbol(); //print out each spot
            }
        }
        else
        {
            cout << (*mapArray[i-1]).getSymbol(); //print out each spot
        }

        if(i % width == 0) //For every new line, print enter character
        {
            cout << endl;
        }
    }
     SetConsoleTextAttribute(hConsole, 15);
    return;
}

//To get the interactable on a certain spot
Interactable* Map::getInteractable(const int _width, const int _height) const
{
    return mapArray[(width*(_height-1))+(_width-1)];
}

//Returns double pointer, same as above
Interactable** Map::getInteractableP(const int _width, const int _height)
{
    return &mapArray[(width*(_height-1))+(_width-1)];
}

//In charge of swapping two values in the map
void Map::swapInteractable(Interactable** _ptrOne, Interactable** _ptrTwo)
{
    cout << _ptrOne << "," << _ptrTwo << endl;
    Interactable** tempPtr; //temporary spot for swapping
    tempPtr = _ptrOne; //Swap values
    _ptrOne = _ptrTwo;
    _ptrTwo = tempPtr;
    cout << _ptrOne << "," << _ptrTwo << endl;
    return; //return void
}

//used to check and see if player is at exit
bool Map::checkWin() const
{
    if((*ptr_player).getX() == (*ptr_mazeExit).getX() && (*ptr_player).getY() == (*ptr_mazeExit).getY()) //If coords of exit and player are the same, return true
    {
        return true;
    }
    return false; //else return false
}

int Map::getWidth() const
{
    return width;
}

int Map::getHeight() const
{
    return height;
}

Interactable* Map::getContainer() const
{
    return ptr_container;
}

Interactable** Map::getContainerP()
{
    return &ptr_container;
}
