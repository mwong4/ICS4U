/*
Author: Max Wong
Date Created: Mar 28, 2020
Date Updated: Apr 4, 2020
Purpose: Source file for Player class
Type: Source
*/

#include "Player.h"
#include "Interactable.h" //include interactable class
#include "Map.h" //Inclduing map class
#include "Crumb.h" //Include crumb class

Player::Player()
{
    //ctor
    xCoord = 0;
    yCoord = 0;
    autoSolve = true;
    directions = new Stack();
    ptr_crumb = nullptr;
}

//Custom constructor
Player::Player(int _symbol, int _colour, int _x, int _y, bool _auto, Map *_map, Crumb *_crumb) : Interactable(_symbol, _colour)
{
    xCoord = _x;
    yCoord = _y;
    autoSolve = _auto;
    directions = new Stack();
    ptr_crumb = _crumb;
}

Player::~Player()
{
    //dtor
    (*directions).clear();
}

//General Functions
//Used to toggle auto solver
void Player::toggleAutoSolver()
{
    autoSolve != autoSolve; //Flip value
    cout << ">- Auto Toggled" << endl;
    return;
}

//Get's input from user when manually controlling
char Player::getInput()
{
    if((GetKeyState('W') & 0x8000) || (GetKeyState(VK_UP) & 0x8000)) //Check for escape and WASD or arrow key input, return approrpriate direction/code
    {
        return 'U';
    }
    else if((GetKeyState('S') & 0x8000) || (GetKeyState(VK_DOWN) & 0x8000))
    {
        return 'D';
    }
    else if((GetKeyState('A') & 0x8000) || (GetKeyState(VK_LEFT) & 0x8000))
    {
        return 'L';
    }
    else if((GetKeyState('D') & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000))
    {
        return 'R';
    }
    else if(GetKeyState(VK_ESCAPE) & 0x8000)
    {
        return 'E';
    }
    return ' '; //return null if no valid input
}

//Checks to see if inputed move is legal and if good, Updates position of player
bool Player::updatePosition(char _direction)
{
    int xShift = 0; //The shift in X or Y
    int yShift = 0;
    //Interactable **ptr_tempContainer;
    //Interactable **ptr_tempObject;
    char emptySymbol = 0; //Used to compare and check container value

    if(_direction == 'U') //Convert direction into shift
    {
        yShift = -1;
    }
    else if(_direction == 'D')
    {
        yShift = 1;
    }
    else if(_direction == 'L')
    {
        xShift = -1;
    }
    else if(_direction == 'R')
    {
        xShift = 1;
    }

    //Check validity of shift, if outside map size
    if((xCoord + xShift) < 1 || (xCoord + xShift) > (*ptr_map).getWidth() || (yCoord + yShift) < 1 || (yCoord + yShift) > (*ptr_map).getHeight())
    {
        return false;
    }
    else if((*(*ptr_map).getInteractable((xCoord + xShift), (yCoord + yShift))).checkSolid()) //If new spot chosen is solid
    {
        return false;
    }
    else //otherwise all good, update position and map
    {
        if((*(*ptr_map).getContainer()).getSymbol() == emptySymbol) //If container value was "space"
        {
            (*ptr_map).setContainer(ptr_crumb); //Set container as a crumb
        }

        (*ptr_map).swapInteractable((*ptr_map).getContainerP(), (*ptr_map).getInteractableP(xCoord, yCoord)); //swap container and player
        xCoord += xShift; //update coordinats
        yCoord += yShift;
        (*ptr_map).swapInteractable((*ptr_map).getContainerP(), (*ptr_map).getInteractableP(xCoord, yCoord)); //swap container and new position
        return true;
    }
}

bool Player::checkSolid()
{
    return true;
}

//getters/setters
int Player::getX() const
{
    return xCoord;
}

int Player::getY() const
{
    return yCoord;
}

void Player::setMap(Map *_map)
{
    ptr_map = _map;
    return;
}
