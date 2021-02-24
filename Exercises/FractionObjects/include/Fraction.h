/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Feb 24, 2020
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
        void add(Fraction*, Fraction*);
        void sub(Fraction*, Fraction*);
        void mul(Fraction*, Fraction*);
        void div(Fraction*, Fraction*);

    protected:

    private:
        int numerator;
        int denominator;
};

#endif // FRACTION_H
