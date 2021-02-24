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


    //Addition
    cout << "//Add//" << endl;
    output.add(&fracOne, &fracTwo); //Call method to add
    fracOne.displayFraction(); //Display
    cout << " + ";
    fracTwo.displayFraction();
    cout << " = ";
    output.displayFraction();

    //Subtraction
    cout << endl << "//Subtract//" << endl;
    output.sub(&fracOne, &fracTwo); //Call method to subtract
    output.displayFraction();

    //Multiplication
    cout << endl << "//Multiply//" << endl;
    output.mul(&fracOne, &fracTwo); //Call method to multiply
    output.displayFraction();

    //Division
    cout << endl << "//Division//" << endl;
    output.div(&fracOne, &fracTwo); //Call method to division
    output.displayFraction();

    return 0;
}
