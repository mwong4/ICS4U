/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 5, 2021
Purpose: Source File for Stack, for auto-solver
Type: Source
*/

#include "Stack.h"

Stack::Stack()
{
    //ctor
    count = 0;
    ptr_top = nullptr;
}

//Custom Constructor
Stack::Stack(int _count)
{
    count = _count;
    ptr_top = nullptr;
}

Stack::~Stack()
{
    //dtor
}

//general functions
//Push to top of stack (0U, 1L, 2D, 3R, 30B)
void Stack::push(int _direction)
{
    //initialize with direction and next being current top
    Node *tempNode = new Node(_direction, ptr_top); //new node to be pushed onto stack
    ptr_top = tempNode; //Set back to new node
    count ++; //Increase count by 1
    return;
}

//Pop top and return content (0U, 1L, 2D, 3R)
int Stack::pop()
{
    int tempDirection = 0; //Used to store direction

    if(count > 0) //if top exists
    {
        tempDirection = (*ptr_top).direction; //Set to current top content
        Node *target = ptr_top; //A pointer to the node to be destroyed, set to current top

        ptr_top = (*ptr_top).ptr_next; //set new top
        (*target).ptr_next = nullptr; // disconnect target
        delete target; //delete target
        count --;
    }

    return tempDirection; //return direction
}

//Clear whole chain
void Stack::clear()
{
    delete ptr_top;
    count = 0; //Reset all variables
    ptr_top = nullptr;
}

//Return value at top
int Stack::peak() const
{
    return (*ptr_top).direction;
}

//display whole chain
void Stack::display() const
{
    cout << ">- ";
    if(count > 0) //If not empty
    {
        (*ptr_top).display();
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
    cout << endl;
    return;
}

