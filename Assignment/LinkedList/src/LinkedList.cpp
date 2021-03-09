/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 9, 2020
Purpose: Source file for Linked List class
Type: Source

////TODO////
A search function returns whether a given value is in the list
An index function that returns the nth value in the list.
An findIndex function that returns the position where a specified value is stored.
An insertion function that inserts a given node after another specified node in a list.
An insert function that inserts a value into this list after another specified value in the list. (Look it's encapsulation!)
A remove function that removes a node from the list. This function may or may not return the value stored in that node.
A remove function that removes the nth node from the list.
A remove function that removes the first occurrence of a specified value from the list.
*/

#include "LinkedList.h"

#include<iostream>

LinkedList::LinkedList()
{
    //ctor
    ptr_front = nullptr; //Set to friendly null values
    ptr_back = nullptr;
    count = 0;
}

//Custom constructor
LinkedList::LinkedList(Node *_front, Node *_back, const int _count)
{
    ptr_front = _front; //Set all values
    ptr_back = _back;
    count = _count;
    return;
}

LinkedList::~LinkedList()
{
    //dtor
}

//All general functions

 //display all the contents of the list
void LinkedList::display() const
{
    Node* ptr_target = ptr_front; //Stores target, set initially to front

    cout << "List (f->b): ";
    while(ptr_target != nullptr)//If target is not null
    {
        (*ptr_target).display(); //Call target to display itself
        ptr_target = (*ptr_target).getNext(); //Assign target to next item in list
        cout << ", ";
    }
    cout << endl;
}

bool search(Node*) const; //Returns if node is in list
int index(int) const; //Returns value of nth position
int findIndex(int) const; //Finds the nth position of the first occurance of a given value
void insert(Node*, Node*); //Inserts a node after a given node
void insert(int, int); //Inserts a value after the first occurance of a certain value
int remove(Node*); //Removes specific node and returns value
int removeSpot(int); //Removes the specific nth spot
int removeOccurance(int); //Removes the first occurance of a value
void clear(); //Resets whole list

//geters/seters
Node* LinkedList::getFront() const
{
    return ptr_front;
}

Node* LinkedList::getBack() const
{
    return ptr_back;
}

int LinkedList::getCount() const
{
    return count;
}

void LinkedList::setFront(Node* _front)
{
    ptr_front = _front;
    return;
}

void LinkedList::setBack(Node* _back)
{
    ptr_back = _back;
    return;
}

void LinkedList::setCount(int _count)
{
    count = _count;
    return;
}

