/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 5, 2021
Purpose: Source File for Node class, for auto-solver
Type: Source
*/

#include "Node.h"

Node::Node()
{
    //ctor
    direction = 0; //null
    ptr_next = nullptr;
}

//Custom constructor
Node::Node(const int _direction, Node *_next)
{
    direction = _direction; //set direction, next is null
    ptr_next = _next;
}

Node::~Node()
{
    //dtor
    delete ptr_next;
}

void Node::display() const
{
    cout << direction << ", ";
    if(ptr_next != nullptr) //if not null
    {
        (*ptr_next).display();
    }
    return;
}
