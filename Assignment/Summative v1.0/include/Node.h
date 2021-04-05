/*
Author: Max Wong
Date Created: Mar 23, 2021
Date Updated: Apr 5, 2021
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
        Node(const int, Node*); //Custom constructor
        virtual ~Node();

        void display() const;

    protected:
        Node* ptr_next; //Next element
        int direction; //content of the node, (0U, 1L, 2D, 3R, 30B)

    private:

};

#endif // NODE_H
