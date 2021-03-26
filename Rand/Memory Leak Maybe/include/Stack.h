/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Mar 25, 2020
Purpose: Header File for Stack class, for auto-solver
Type: Header

peak
push
pop
clear
display
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
        void push(char); //Push to top of stack
        char pop(); //Pop top and return content
        void clear(); //Clear whole chain
        char peak() const; //Return value at top
        void display() const; //display whole chain

    protected:
        Node *ptr_top; //Points to back
        int count; //Size of stack

    private:
};

#endif // STACK_H
