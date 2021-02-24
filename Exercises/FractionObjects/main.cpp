/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Feb 24, 2020
Purpose: test methods for rectangle exercise
Type: Main
*/

#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction fracOne(7, 8);
    Fraction fracTwo(3, 4);
    Fraction output;

    output.add(&fracOne, &fracTwo);

    fracOne.displayFraction();
    cout << " + ";
    fracTwo.displayFraction();
    cout << " = ";
    output.displayFraction();


    return 0;
}
