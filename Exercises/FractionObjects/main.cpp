/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Mar 2, 2020
Purpose: Main file for fraction exercise
Type: Main
*/

#include <iostream>
#include "Fraction.h" //Include fraction object

using namespace std;

int main()
{
    Fraction fracOne(7, 8); //Instantiate fraction 1 and 2
    Fraction fracTwo(3, 4);
    Fraction output; //Output fraction


    //Addition
    cout << "//Add//" << endl;
    output = fracOne.add(&fracTwo); //Call method to add
    fracOne.displayFraction(); //Display
    cout << " + ";
    fracTwo.displayFraction();
    cout << " = ";
    output.displayFraction();

    //Subtraction
    cout << endl << "//Subtract//" << endl;
    output = fracOne.sub(&fracTwo); //Call method to add
    output.displayFraction();

    //Multiplication
    cout << endl << "//Multiply//" << endl;
    output = *(fracOne.mul(&fracTwo, &output)); //Call method to add
    output.displayFraction();

    //Division
    cout << endl << "//Division//" << endl;
    output = *(fracOne.div(&fracTwo, &output)); //Call method to add
    output.displayFraction();

    return 0;
}
