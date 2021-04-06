/*
Author: Max Wong
Date Created: Mar 28, 2021
Date Updated: Apr 6, 2021
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
    loadStack(10); //Load stack
    ptr_crumb = nullptr;
}

//Custom constructor
Player::Player(int _symbol, int _colour, int _x, int _y, bool _auto, Map *_map, Crumb *_crumb) : Interactable(_symbol, _colour)
{
    xCoord = _x;
    yCoord = _y;
    autoSolve = _auto;
    directions = new Stack();
    loadStack(10); //Load stack
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
    autoSolve = !autoSolve; //Flip value
    cout << ">- Auto Toggled" << endl;
    return;
}

//Get's input from user when manually controlling (0U, 1L, 2D, 3R, 30B)
int Player::getInput()
{
    if((GetKeyState('W') & 0x8000) || (GetKeyState(VK_UP) & 0x8000)) //Check for escape and WASD or arrow key input, return approrpriate direction/code
    {
        return 0;
    }
    else if((GetKeyState('S') & 0x8000) || (GetKeyState(VK_DOWN) & 0x8000))
    {
        return 2;
    }
    else if((GetKeyState('A') & 0x8000) || (GetKeyState(VK_LEFT) & 0x8000))
    {
        return 1;
    }
    else if((GetKeyState('D') & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000))
    {
        return 3;
    }
    return 10; //return null if no valid input
}

//Checks to see if inputed move is legal and if good, Updates position of player
bool Player::updatePosition(int _direction, bool _backTracking)
{
    int xShift = 0; //The shift in X or Y
    int yShift = 0;
    //Interactable **ptr_tempContainer;
    //Interactable **ptr_tempObject;
    char emptySymbol = 0; //Used to compare and check container value

    //Convert direction into shift (0U, 1L, 2D, 3R, 30B)
    if(_direction == 0) //U
    {
        yShift = -1;
    }
    else if(_direction == 2) //D
    {
        yShift = 1;
    }
    else if(_direction == 1) // L
    {
        xShift = -1;
    }
    else if(_direction == 3) // R
    {
        xShift = 1;
    }

    //Check validity of shift, if outside map size
    if((xCoord + xShift) < 1 || (xCoord + xShift) > (*ptr_map).getWidth() || (yCoord + yShift) < 1 || (yCoord + yShift) > (*ptr_map).getHeight())
    {
        //cout << "[ERROR] direction " << _direction << " outside map" << endl;
        return false;
    }
    else if((*(*ptr_map).getInteractable((xCoord + xShift), (yCoord + yShift))).checkSolid()) //If new spot chosen is solid
    {
        //cout << "[ERROR] direction " << _direction << " is solid" << endl;
        return false;
    }
    else if((*(*ptr_map).getInteractable((xCoord + xShift), (yCoord + yShift))).getSymbol() == '*' && !_backTracking) //If next position has crumb and player is not backtracking
    {
        //cout << "[ERROR] direction " << _direction << " is illegal backtrack" << endl;
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
    return false;
}

//Returns true
bool Player::checkSolid()
{
    return true;
}

//Loads stack exlucing char inputted (0U, 1L, 2D, 3R, 30B)
void Player::loadStack(int _exclude)
{
    if(_exclude != 3) //If exclude char is not right, push right
    {
        (*directions).push(3);
    }
    if(_exclude != 2) //If exclude char is not left, push left
    {
        (*directions).push(2);
    }
    if(_exclude != 1) //If exclude char is not down, push down
    {
        (*directions).push(1);
    }
    if(_exclude != 0) //If exclude char is not up, push up
    {
        (*directions).push(0);
    }
    return;
}

//Returns the opposite direction of input char (0U, 1L, 2D, 3R, 30B)
int Player::getOpposite(int _input)
{
    return (_input+2)%4;
}

//Remote control for user, called on each step aotu-taken by algorithm (0U, 1L, 2D, 3R, 30B)
void Player::autoSolver()
{
    int current; //Current direction described by stack
    bool finishedMove = false; //Turned true when position is successfully updated
    bool backTracking = false;

    while(!finishedMove)
    {
        if((*directions).peak() == 30) //if current top is a backtrack
        {
            cout << "Backtracking!" << endl;
            (*directions).pop(); //pop marker
            backTracking = true; //Set backtracking to true
        }
        else
        {
            current = (*directions).pop(); //get and pop top
            if(updatePosition(current, backTracking)) //Try and update position, if success
            {
                finishedMove = true; //close down loop
                if(!backTracking) //If this step is not backtracking
                {
                    (*directions).push(getOpposite(current)); //push opposite direction
                    (*directions).push(30); //push backtrack marker
                }
                loadStack(getOpposite(current)); //Reload stack
            }
        }
    }
    return;
}

//The encapsulated master control for player
void Player::nextTurn()
{
    cout << autoSolve << endl;
    if(autoSolve) //If auto solve is toggled
    {
        autoSolver(); //Use auto solver
    }
    else //else, manually get input and update positions
    {
        updatePosition(getInput(), true);
    }

    //If player is on the switch
    if((*(*ptr_map).getContainer()).getSymbol() == '[' || (*(*ptr_map).getContainer()).getSymbol() == ']')
    {
        (*(*ptr_map).getContainer()).togglePower(); //use switch
        (*ptr_map).clearCrumbs(); //Clear crumbs
        (*directions).clear(); //Clear stack
        loadStack(' '); //Reload stack
    }
    return;
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
