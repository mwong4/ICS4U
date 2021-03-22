/*
Author: Max Wong
Date Created: Mar 20, 2021
Date Updated: Mar 20, 2021
Purpose: Header file for Term Class
Type: Header
*/

#ifndef TERM_H
#define TERM_H
#include <iostream>

using namespace std;

class Term
{
    public:
        Term();
        Term(Term*, Term*, int, int); //Custom constructor
        virtual ~Term();

        void display() const; //Displays the content of the node

        //geters/seters
        Node* getNext() const;
        int getExponent() const;
        int getConstant() const;
        void setNext(Node*);
        void setExponent(int);
        void setConstant(int);

    protected:

    private:
        Term* ptr_next;
        Term* ptr_previous;
        int exponent;
        int constant;
};

#endif // TERM_H
