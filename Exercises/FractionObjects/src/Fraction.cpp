/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Feb 24, 2020
Purpose: Defining all methods
Type: Class
*/

#include "Fraction.h"

Fraction::Fraction()
{
    numerator = 1;
    denominator = 1;
    //ctor
}

Fraction::Fraction(int _num, int _den)
{
    numerator = _num;
    denominator = _den;
    return;
}

Fraction::~Fraction()
{
    //dtor
}

//Standard Fractions
void Fraction::displayFraction()
{
    cout << numerator << "/" << denominator;
}

void Fraction::add(Fraction *_fracOne, Fraction *_fracTwo)
{
    numerator = ((*_fracOne).numerator * (*_fracTwo).denominator) + ((*_fracTwo).numerator * (*_fracOne).denominator);
    denominator = ((* _fracOne).denominator) * ((*_fracTwo).denominator);
    return;
}

void Fraction::sub(Fraction *_fracOne, Fraction *_fracTwo)
{
    numerator = ((*_fracOne).numerator * (*_fracTwo).denominator) - ((*_fracTwo).numerator * (*_fracOne).denominator);
    denominator = ((* _fracOne).denominator) * ((*_fracTwo).denominator);
    return;
}

void Fraction::mul(Fraction *_fracOne, Fraction *_fracTwo)
{
    numerator = ((*_fracOne).numerator) * ((*_fracTwo).numerator);
    denominator = ((* _fracOne).denominator) * ((* _fracTwo).denominator);
    return;
}

void Fraction::div(Fraction *_fracOne, Fraction *_fracTwo)
{
    numerator = ((*_fracOne).numerator) * ((*_fracTwo).denominator);
    denominator = ((* _fracOne).denominator) * ((*_fracTwo).numerator);
    return;
}
