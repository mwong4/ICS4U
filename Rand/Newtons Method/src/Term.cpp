/*
Author: Max Wong
Date Created: Mar 20, 2021
Date Updated: Mar 20, 2021
Purpose: Header file for Term Class
Type: Header
*/

#include "Term.h"

Term::Term()
{
    //ctor
    ptr_next = nullptr;
    ptr_previous = nullptr;
    exponent = 0;
    constant = 0;
}

//Custom constructor
Term::Term(Term* _next, Term* _previous, int _exponent, int _constant)
{
    ptr_next = _next;
    ptr_previous = _previous;
    exponent = _exponent;
    constant = _constant;
}

Term::~Term()
{
    //dtor
    cout << "Deleting term" << endl;
    delete _next;
}

//Displays the content of the node
void Term::display() const
{
    cout << constant << "x^" << exponent << endl;
}

//geters/seters
Term* Term::getNext() const;
{
    return ptr_next;
}

int Term::getExponent() const;
{
    return exponent;
}

int Term::getConstant() const;
{
    return constant;
}

void Term::setNext(Term* _next);
{
    ptr_next = _next;
    return;
}

void Term::setExponent(int _exponent);
{
    exponent = _exponent;
    return;
}

void Term::setConstant(int _constant);
{
    constant = _constant;
    return;
}

