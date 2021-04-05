/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Apr 5, 2020
Purpose: Header File for Stack class, for auto-solver
Type: Header
*/

#ifndef STACK_H
#define STACK_H
#include "Node.h" //Include node class

using namespace std;

class Stack
{
    public:
        Stack();
        Stack(int); //Custom Constructor
        virtual ~Stack();

        //general functions
        void push(int); //Push to top of stack
        int pop(); //Pop top and return content
        void clear(); //Clear whole chain
        int peak() const; //Return value at top
        void display() const; //display whole chain

    protected:
        Node *ptr_top; //Points to back
        int count; //Size of stack

    private:
};

#endif // STACK_H
