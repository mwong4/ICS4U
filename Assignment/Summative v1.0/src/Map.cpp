#include "Map.h"

Map::Map()
{
    //ctor
    width = 10;
    height = 10;
}

//Custom constructor
Map::Map(int _width, int _height, Interactable[10][10] _map)
{
    width = _width;
    height = _height;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Interactable[j][i] = _map[j][i];
        }
    }
}

Map::~Map()
{
    //dtor
}

//For printing out map
void printMap() const
{
    for(int i = 0; i < 10; i++) //go through whole 2d array
        for(int j = 0; j < 10; j++)
        {
            cout << (*Interactable[j][i]).getSymbol(); //print out each spot
        }
        cout << endl;
    }
}

//To get the interactable on a certain spot
void getInteractable(const int, const int) const
{

}
