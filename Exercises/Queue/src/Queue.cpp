/*
Author: Max Wong
Date Created: Mar 8, 2020
Date Updated: Mar 8, 2020
Purpose: Queue source file
Type: Source
*/

#include "Queue.h"
#include <iostream>


Queue::Queue()
{
    //ctor
    ptr_front = nullptr;
    ptr_back = nullptr;
}

//Custom constructor
Queue::Queue(Container *_front, Container *_back)
{
    ptr_front = _front;
    ptr_back = _back;
    return;
}

Queue::~Queue()
{
    //dtor
    //delete ptr_front;
}

//general functions
//For pushing value to back
void Queue::push(int _value)
{
    Container *ptr_tempContainer = new Container(); //Create temporary pointer to new container

    (*ptr_tempContainer).setContent(_value); //Set content and next for container
    (*ptr_tempContainer).setNext(nullptr);

    if(ptr_back != nullptr)
    {
        (*ptr_back).setNext(ptr_tempContainer); //Set next of previous element if back is not empty
    }

    if(ptr_front == nullptr) //Set properties of queue
    {
        ptr_front = ptr_tempContainer;
    }
    ptr_back = ptr_tempContainer;
    return;
}

//For extracting and destroying value on front
int Queue::pop()
{
    if(ptr_front != nullptr)
    {
        Container *ptr_tempContainer = ptr_front; //Temporary container
        int tempContent = (*ptr_front).getContent(); //temporary content int

        ptr_front = (*ptr_tempContainer).getNext(); //Reassign front and possibly back values
        if((*ptr_tempContainer).getNext() == nullptr)
        {
            ptr_back = nullptr;
        }

        (*ptr_tempContainer).setNext(nullptr); //Disconnecting from chain
        delete ptr_tempContainer; //Call destructor
        return tempContent; //return content
    }
    return -9999; //return null value
}

//For reading value at front
int Queue::peek()
{
    if(ptr_front != nullptr)
    {
        return (*ptr_front).getContent();
    }
    return -9999; //return null value
}

//For displaying all in queue
void Queue::displayQueue()
{
    Container* ptr_target = ptr_front; //temporary storage of the target container(s)

    cout << "Displaying whole queue: ";
    while(ptr_target != nullptr) //Go through whole queue
    {
        (*ptr_target).display(); //Print out target content
        cout << ", ";
        ptr_target = (*ptr_target).getNext(); //Reset to next in queue
    }
    cout << endl << endl;
    return;
}

//For destroying whole queue
void Queue::clear()
{
    delete ptr_front; //Delete all
    ptr_back = nullptr; //Clear back too
    ptr_front = nullptr;
    return;
}

//geters/seters
Container *Queue::getFront()
{
    return ptr_front;
}

Container *Queue::getBack()
{
    return ptr_back;
}

void Queue::setFront(Container* _front)
{
    ptr_front = _front;
    return;
}

void Queue::setBack(Container* _back)
{
    ptr_back = _back;
    return;
}
