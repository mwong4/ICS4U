/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Mar 25, 2020
Purpose: Header File for Node class, for auto-solver
Type: Header
*/

#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
    friend class Stack;

    public:
        Node();
        Node(const char, Node*); //Custom constructor
        virtual ~Node();

        void display() const;

    protected:
        Node* ptr_next; //Next element
        char direction; //content of the node

    private:

};

#endif // NODE_H
