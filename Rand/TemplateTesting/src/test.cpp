/*
Author: Max Wong
Date Created: Mar 10, 2021
Date Edited: Mar 10, 2021
Purpose: Source file for test class
Type: Source
*/

#include "Test.h"
#include <iostream>

template <class conType>
Test<conType>::Test()
{
    //ctor

}

template <class conType>
Test<conType>::~Test()
{
    //dtor
}

template <class conType>
void Test<conType>::displayContent()
{
    cout << content << endl;
}
