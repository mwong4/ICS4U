/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Mar 2, 2020
Purpose: Header file for fraction class
Type: Header
*/

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using namespace std;

class Fraction
{
    public:
        Fraction();
        Fraction(int, int);
        virtual ~Fraction();

        //Standard Fractions
        void displayFraction();
        Fraction add(Fraction*);
        Fraction sub(Fraction*);
        Fraction* mul(Fraction*, Fraction*);
        Fraction* div(Fraction*, Fraction*);

        //Variables
        int numerator;
        int denominator;

    protected:

    private:
};

#endif // FRACTION_H
