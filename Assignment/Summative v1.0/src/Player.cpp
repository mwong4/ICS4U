/*
Author: Max Wong
Date Created: Mar 28, 2021
Date Updated: Apr 7, 2021
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
    HANDLE hstdin; //handle variables
    DWORD mode; //input mode
    int input; //input from user

    hstdin = GetStdHandle( STD_INPUT_HANDLE ); //Set up handle stuff
    GetConsoleMode( hstdin, &mode ); //get console mode settings
    SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT ); //set to unbuffered mode

    input = cin.get(); //get input

    if(input == 119) //Check for WASD key input, return approrpriate direction/int
    {
        return 0; //W -> U
    }
    else if(input == 115)
    {
        return 2; //S -> D
    }
    else if(input == 97)
    {
        return 1; //A -> L
    }
    else if(input == 100)
    {
        return 3; //D -> R
    }
    return 10; //return null if no valid input
}

//Checks to see if inputed move is legal and if good, Updates position of player
bool Player::updatePosition(int _direction, bool _backTracking)
{
    int xShift = 0; //The shift in X or Y
    int yShift = 0;
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
    else //If some rand or null value, return false
    {
        return false;
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
    else if((*(*ptr_map).getInteractable((xCoord + xShift), (yCoord + yShift))).getSymbol() == '*' && !_backTracking) //If next position has crumb and player is not backtracking
    {
        return false;
    }
    else //otherwise all good, update position and map
    {
        if((*(*ptr_map).getContainer()).getSymbol() == emptySymbol) //If container value was "space"
        {
            if((*(*ptr_map).getContainer()).getType() == "Gate") //If that blak symbol is a "space"
            {
                (*(*ptr_map).getContainer()).setSymbol('*'); //Set container symbol as crumb

            }
            else //otherwise, it is a gate, replace gate blank symbol * symbol
            {
                (*ptr_map).setContainer(ptr_crumb); //Set container as a crumb
            }
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

//For teleporting player
void Player::teleport()
{
    int portalX = (*(*ptr_map).getContainer()).getX(); //set x and y of portal's linked portal
    int portalY = (*(*ptr_map).getContainer()).getY();

    (*ptr_map).swapInteractable((*ptr_map).getContainerP(), (*ptr_map).getInteractableP(xCoord, yCoord)); //swap container and player
    xCoord = portalX; //update player coordinates
    yCoord = portalY;
    (*ptr_map).swapInteractable((*ptr_map).getContainerP(), (*ptr_map).getInteractableP(portalX, portalY)); //swap container and new position

    return;
}

//The encapsulated master control for player
void Player::nextTurn()
{
    char containerChar; //for detecting switch or portal

    if(autoSolve) //If auto solve is toggled
    {
        system("PAUSE");
        autoSolver(); //Use auto solver
    }
    else //else, manually get input and update positions
    {
        updatePosition(getInput(), true);
    }

    containerChar = (*(*ptr_map).getContainer()).getSymbol(); //Get symbol of container

    //If player is on the switch or portal
    if(containerChar == '[' || containerChar == ']' || containerChar == '@')
    {
        if(containerChar != '@') //If specifically on portal, teleport
        {
            (*(*ptr_map).getContainer()).togglePower(true); //use switch
        }
        else
        {
            teleport();
        }
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
