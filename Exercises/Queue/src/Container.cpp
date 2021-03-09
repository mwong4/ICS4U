/*
Author: Max Wong
Date Created: Mar 8, 2020
Date Updated: Mar 8, 2020
Purpose: Source file for container class
Type: Source
*/

#include <iostream>
#include "Container.h"


Container::Container()
{
    //ctor
    content = 0;
    ptr_next = nullptr;
}

//custom constructor
Container::Container(int _content, Container *_next)
{
    content = _content;
    ptr_next = _next;
    return;
}

Container::~Container()
{
    //dtor
    cout << "Deleting value with " << content << endl;
    delete ptr_next; //Delete next
}

void Container::display()
{
    cout << content;
}

//geters/seters
int Container::getContent()
{
    return content;
}

Container* Container::getNext()
{
    return ptr_next;
}

void Container::setContent(int _input)
{
    content = _input;
    return;
}

void Container::setNext(Container *_container)
{
    ptr_next = _container;
    return;
}
