/*
Author: Max Wong
Date Created: Mar 26, 2020
Date Updated: Mar 26, 2020
Purpose: Source file for Map class
Type: Source
*/

#include "Map.h"

Map::Map()
{
    //ctor
    width = 10;
    height = 10;
    mazeExit = nullptr;
    for(int i = 0; i < 100; i++) //Set whole map to null by default
    {
        mapArray[i] = nullptr;
    }
}

//Custom constructor
Map::Map(int _width, int _height, Interactable *_map[], Interactable* _exit)
{
    width = _width;
    height = _height;
    mazeExit = _exit;

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
        if(mapArray[i-1] == mazeExit) //Check if pointer is exit
        {
            if((*mazeExit).getHidden()) //If is exit and check if hidden is false
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
    return new Interactable;
}

//In charge of swapping two values in the map
void swapInteractable(Interactable* _ptrOne, Interactable* _ptrTwo)
{
    Interactable* tempPtr; //temporary spot for swapping
    tempPtr = _ptrOne; //Swap values
    _ptrOne = _ptrTwo;
    _ptrTwo = tempPtr;
    return; //return void
}
