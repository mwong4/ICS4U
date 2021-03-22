/*
Author: Max Wong
Date Created: Mar 20, 2021
Date Updated: Mar 20, 2021
Purpose: Source file for Function class
Type: Source
*/


#include "Function.h"
#include "Term.h"

Function::Function()
{
    //ctor
    ptr_front = nullptr;
    size = 0;
}

//Custom constructor
Function::Function(Term* _front, int _size)
{
    ptr_front = _front;
    size = _size;
}

Function::~Function()
{
    //dtor
}
