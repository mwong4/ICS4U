/*
Author: Max Wong
Date Created: Mar 11, 2020
Date Updated: Mar 11, 2020
Purpose: Source file for Node class
Type: Source
*/

#include "Node.h"

#include<iostream>

template <typename contentType>
Node<contentType>::Node()
{
    //ctor
    ptr_next = nullptr; //Set both pointers to null
    ptr_previous = nullptr;
}

template <typename contentType>
Node<contentType>::~Node()
{
    //dtor
    cout << "Deleting value " << content << endl;
    delete ptr_next;
}

//Displays the content of the node
template <typename contentType>
void Node<contentType>::display() const
{
    cout << content;
    return;
}

//geters/seters
template <typename contentType>
Node<contentType>* Node<contentType>::getNext() const
{
    return ptr_next;
}

template <typename contentType>
Node<contentType>* Node<contentType>::getPrevious() const
{
    return ptr_previous;
}

template <typename contentType>
contentType Node<contentType>::getContent() const
{
    return content;
}

template <typename contentType>
void Node<contentType>::setNext(Node* _next)
{
    ptr_next = _next;
    return;
}

template <typename contentType>
void Node<contentType>::setPrevious(Node* _previous)
{
    ptr_previous = _previous;
    return;
}

template <typename contentType>
void Node<contentType>::setContent(contentType _content)
{
    content = _content;
    return;
}
