/*
Author: Max Wong
Date Created: Mar 26, 2021
Date Updated: Apr 6, 2021
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
    ptr_empty = nullptr;
    for(int i = 0; i < 100; i++) //Set whole map to null by default
    {
        mapArray[i] = nullptr;
    }
}

//Custom constructor
Map::Map(int _width, int _height, Interactable *_map[], Interactable* _exit, Interactable* _player, Interactable* _container, Interactable* _empty)
{
    width = _width;
    height = _height;
    ptr_mazeExit = _exit;
    ptr_player = _player;
    ptr_container = _container;
    ptr_empty = _empty;

    //set class var to input
    for(int i = 0; i < (_width*_height); i++) //go through whole 2d array
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

    for(int i = 1; i < width*height+1; i++) //go through whole 2d array
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
    Interactable* tempPtr; //temporary spot for swapping
    tempPtr = (*_ptrOne); //Swap values
    (*_ptrOne) = (*_ptrTwo);
    (*_ptrTwo) = tempPtr;
    return; //return void
}

//Used to set a certain spot
void Map::setSpot(Interactable* _input, int _index)
{
    mapArray[_index] = _input;
    return;
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

//Iterator for clearing all crumbs
void Map::clearCrumbs()
{
    for(int i = 0; i < width*height; i++) //Go through whole map
    {
        if((*mapArray[i]).getSymbol() == '*') //If crumb is found
        {
            setSpot(ptr_empty, i); //call setter to set spot to empty
        }
    }
    return;
}

//getters/setters
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

void Map::setContainer(Interactable* _obj)
{
    ptr_container = _obj;
    return;
}
