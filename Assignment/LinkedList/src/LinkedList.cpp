/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 9, 2020
Purpose: Source file for Linked List class
Type: Source
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

//Returns if node is in list
bool LinkedList::search(const Node* _target) const
{
    Node *ptr_current = ptr_front; //Temporary node which is the target

    while(ptr_current != nullptr) //Go through list until hit nullptr
    {
        if(_target == ptr_current) //If the pointers for the searched value and the current match, return true
        {
            return true;
        }
        ptr_current = (*ptr_current).getNext(); //Reset current to next node in line
    }
    return false; //Return false
}

//Returns value of nth position
int LinkedList::index(int _location) const
{
    Node *ptr_target = findNode( _location); //Call function to conver n value to node
    if(ptr_target != nullptr) //If the function did not return nullptr
    {
        return (*ptr_target).getContent();
    }
    return -9999; //else return null value
}

//Finds the nth position of the first occurance of a given value
int LinkedList::findIndex(int _value) const
{
    Node *ptr_current = ptr_front; //Temporary node which is the target
    int counter = 0; //Stores nth position

    while(ptr_current != nullptr) //Go through list until hit nullptr
    {
        if(_value == (*ptr_current).getContent()) //If the pointers for the searched value and the current match, return true
        {
            return counter;
        }
        ptr_current = (*ptr_current).getNext(); //Reset current to next node in line
        counter ++;
    }

    return -9999;
}

//Inserts node to front of list
void LinkedList::insertFront(Node* _inserting)
{
    if(count == 0) //If inserting to empty list
    {
        ptr_back = _inserting; //Set back if first node in list
    }
    else
    {
        (*ptr_front).setPrevious(_inserting); //set previous of old front
    }
    (*_inserting).setNext(ptr_front); //set next of new
    ptr_front = _inserting; //Set front
    count ++; //Increase count by 1

    return;
}

//Inserts a node after a given node
void LinkedList::insert(Node* _inserting, Node* _target)
{
    if(count == 1) //If adding to a single link, set to back
    {
        ptr_back = _inserting;
        (*(*_target).getNext()).setPrevious(_inserting); //Setting behind's previous to new link
    }

    (*_inserting).setNext((*_target).getNext()); //Setting new link's next to behind
    (*_target).setNext(_inserting); //Set forward's next to new link
    (*_inserting).setPrevious(_target); //Set new link's previous to forwards
    count ++; //Increase count

    return;
}

//Inserts a value after the first occurance of a certain value
void LinkedList::insertOn(const int _value, const int _target)
{
    int location = findIndex(_target); //int that stores index, call findIndex method to find it

    if(location != -9999) //Make sure value is not nullptr
    {
        Node *ptr_location = findNode(location); //Pointer to target node, call method to convert index to node
        Node *ptr_newNode = new Node; //Declare new node to be put into list

        (*ptr_newNode).setContent(_value); //Set value into node

        if(location == 0) //If at front
        {
            insertFront(ptr_newNode); //Call function to insert node into front
        }
        else
        {
            insert(ptr_newNode, ptr_location); //Call function to insert node into list
        }
    }
    else
    {
        cout << "Sorry, value cannot be found within list" << endl;
    }

    return;
}

//Inserts a value at the nth index
void LinkedList::insertAt(const int _value, const int _location)
{
    Node *ptr_newNode = new Node; //Make new node
    (*ptr_newNode).setContent(_value); //Load new node with content data

    if(_location == 0) //If inserting to front
    {
        insertFront(ptr_newNode); //Call method, insert to front
    }
    else if(_location < count)
    {
        insert(ptr_newNode, findNode(_location));
    }
    else
    {
        cout << "Sorry, location not in list" << endl;
    }

    return;
}

//Removes specific node and returns value
int LinkedList::remove(Node* _target)
{
    int tempContent; //Content that will be retained and returned
    if(_target != nullptr)
    {
        if((*_target).getPrevious() != nullptr) //Make sure previous node is not nullptr
        {
            (*(*_target).getPrevious()).setNext((*_target).getNext()); //Link previous node to next node
        }

        if((*_target).getNext() != nullptr) //Make sure bnext node is not nullptr
        {
            (*(*_target).getNext()).setPrevious((*_target).getPrevious()); //Link next node to previous node
        }

        (*_target).setNext(nullptr); //Set current target notes pointers all to null
        (*_target).setPrevious(nullptr);

        tempContent = (*_target).getContent(); //Extract content from target
        delete _target; //Destroy link
        return tempContent; //return contents
    }
    return -9999;
}

//Removes the specific nth spot
int LinkedList::removeSpot(int _location)
{
    if(0 <= _location && _location < count) //If location specified is in the list
    {
        Node *ptr_target = findNode(_location); //Find node pointer from n value using method
        return remove(ptr_target); //Call remove method to destroy node
    }

    cout << "Sorry, position in list does not exist" << endl;
    return -9999; //Otherwise print and return null
}

//Removes the first occurance of a value
int LinkedList::removeOccurance(int _value)
{
    int location = findIndex(_value); //Find n value from first occurance of value, calling findindex method

    if(location != -9999) //If no match was found
    {
        return removeSpot(location); //Call remove spot method and return output
    }
    cout << "Sorry, value was not found in list" << endl;
    return -9999;
}

//Resets whole list
void LinkedList::clear()
{
    delete ptr_front; //Delete whole list from front
    ptr_front = nullptr; //Reset all queue values to default
    ptr_back = nullptr;
    count = 0;
    return;
}

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

//Returns node pointer at nth term
Node* LinkedList::findNode(int _location) const
{
    Node *current = ptr_front; //Temporary node which is the target
    int counter = 0; //Temporary counter

    while(current != nullptr) //Go through list until hit nullptr
    {
        if(counter == _location) //If the pointers for the searched value and the current match, return true
        {
            return current;
        }
        current = (*current).getNext(); //Reset current to next node in line
        counter ++;
    }
    return nullptr; //Return false
}
