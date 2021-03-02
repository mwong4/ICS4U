/*
Author: Max Wong
Date Created: Feb 24, 2020
Date Updated: Mar 2, 2020
Purpose: Source file for fractions
Type: Source
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

Fraction Fraction::add(Fraction *_fracTwo)
{
    Fraction tempFraction; //Temporary fraction

    tempFraction.numerator = (numerator * (*_fracTwo).denominator) + ((*_fracTwo).numerator * denominator);
    tempFraction.denominator = (denominator) * ((*_fracTwo).denominator);
    return tempFraction;
}

Fraction Fraction::sub(Fraction *_fracTwo)
{
    Fraction tempFraction; //Temporary fraction

    tempFraction.numerator = (numerator * (*_fracTwo).denominator) - ((*_fracTwo).numerator * denominator);
    tempFraction.denominator = (denominator) * ((*_fracTwo).denominator);
    return tempFraction;
}

Fraction* Fraction::mul(Fraction *_fracTwo, Fraction *_output)
{
    (*_output).numerator = (numerator) * ((*_fracTwo).numerator);
    (*_output).denominator = (denominator) * ((* _fracTwo).denominator);
    return _output;
}

Fraction* Fraction::div(Fraction *_fracTwo, Fraction *_output)
{
    (*_output).numerator = (numerator) * ((*_fracTwo).denominator);
    (*_output).denominator = (denominator) * ((*_fracTwo).numerator);
    return _output;
}


