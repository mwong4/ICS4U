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
    for(int i = 0; i < 100; i++) //Set whole map to null by default
    {
        mapArray[i] = nullptr;
    }
}

//Custom constructor
Map::Map(int _width, int _height, Interactable *_map[])
{
    width = _width;
    height = _height;

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
        cout << (*mapArray[i-1]).getSymbol(); //print out each spot
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
