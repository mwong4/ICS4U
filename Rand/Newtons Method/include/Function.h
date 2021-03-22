/*
Author: Max Wong
Date Created: Mar 20, 2021
Date Updated: Mar 20, 2021
Purpose: Header File for the Function class
Type: Header
*/


#ifndef FUNCTION_H
#define FUNCTION_H

#include "Term.h" //include term class
#include <iostream>

using namespace std;


class Function
{
    public:
        Function();
        Function(Term*, int); //Custom constructor
        virtual ~Function();



    protected:

    private:
        Term* ptr_front;
        int size;
};

#endif // FUNCTION_H
