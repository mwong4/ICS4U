/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 9, 2020
Purpose: Source file for Node class
Type: Source
*/

#include "Node.h"

#include<iostream>

Node::Node()
{
    //ctor
    ptr_previous = nullptr; //Set to friendly null like values
    ptr_next = nullptr;
    content = 0;
}

//Custom constructor
Node::Node(Node *_next, Node *_previous, const int _content)
{
    ptr_next = _next; //Set all values
    ptr_previous = _previous;
    content = _content;
    return;
}

Node::~Node()
{
    //dtor
    cout << "Deleting value " << content << endl;
    delete ptr_next;
}

//Displays the content of the node
void Node::display() const
{
    cout << content;
    return;
}


//geters/seters
Node* Node::getNext() const
{
    return ptr_next;
}

Node* Node::getPrevious() const
{
    return ptr_previous;
}

int Node::getContent() const
{
    return content;
}

void Node::setNext(Node* _next)
{
    ptr_next = _next;
    return;
}

void Node::setPrevious(Node* _previous)
{
    ptr_previous = _previous;
    return;
}

void Node::setContent(int _content)
{
    content = _content;
    return;
}


