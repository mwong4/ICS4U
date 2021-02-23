/*
Author: Max Wong
Date Created:Feb 23, 2021
Date Updated:Feb 23, 2021
Purpose: Standard functions for all projects

Source
From ICS3U projects by Max Wong
*/
#include <iostream>
#include <limits>        //For error trapping
#include <windows.h>     //For system command

using namespace std;

struct Fraction
{
    int numerator;
    int denominator;
};

//Function for adding
Fraction operator+(Fraction _fracOne, Fraction _fracTwo)
{
    Fraction output; //Temporary fraction to be returned
    output.numerator = ((_fracOne).numerator * (_fracTwo).denominator) + ((_fracTwo).numerator * (_fracOne).denominator);
    output.denominator = (( _fracOne).denominator) * (( _fracTwo).denominator);
    return output;
}

//Function for subtracting
Fraction operator - (Fraction _fracOne, Fraction _fracTwo)
{
    Fraction output; //Temporary fraction to be returned
    output.numerator = ((_fracOne).numerator * (_fracTwo).denominator) - ((_fracTwo).numerator * (_fracOne).denominator);
    output.denominator = (( _fracOne).denominator) * (( _fracTwo).denominator);
    return output;
}

//Function for multiplying
Fraction operator * (Fraction _fracOne, Fraction _fracTwo)
{
    Fraction output; //Temporary fraction to be returned
    output.numerator = (( _fracOne).numerator) * (( _fracTwo).numerator);
    output.denominator = (( _fracOne).denominator) * (( _fracTwo).denominator);
    return output;
}

//Function for dividing
Fraction operator / (Fraction _fracOne, Fraction _fracTwo)
{
    Fraction output; //Temporary fraction to be returned
    output.numerator = (( _fracOne).numerator) * (( _fracTwo).denominator);
    output.denominator = (( _fracOne).denominator) * (( _fracTwo).numerator);
    return output;
}

//Used to display the fraction
ostream& operator << (ostream& _stream, Fraction *_frac)
{
    _stream << (*_frac).numerator << "/" << (*_frac).denominator;
    return _stream;
}

//Used to reset the fraction
void resetFractions(Fraction *_frac)
{
    (*_frac).numerator = 1+ rand() % 10;
    (*_frac).denominator = 1 + rand() % 10;
    return;
}

//Error trapping funcion that only accepts integers
int inputInt (int _maxLimit, int _minLimit)
{
    int playerInput; //This variable is used to get the player's input
    bool findingInput = true; //This bool determines if the loop continues running
    do
    {
        cout << "    >- Your input: "; //Get player input
        cin >> playerInput;
        if(cin.fail())//Check to see if player entered a "bad" input type
        {
            cin.clear(); //Clear all flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore incorrect symbols
            cout << " >- Please enter an integer (non decimal number)" << endl;
        }
        else if(playerInput > _maxLimit || playerInput < _minLimit ) //Otherwise, print an error message
        {
            cout << "  >- Please enter a number between " << _minLimit << " and " << _maxLimit << " (inclusive)" << endl;
        }
        else
        {
            findingInput = false; //Otherwise, if input is all good, exit loop
        }
    }
    while(findingInput);

    return playerInput;//return input
}

//Function used to output options to user and get input
int menu(string _title, string _options[], int _size)
{
    int input; //Input from user

    cout << "///// " << _title << " /////" << endl;
    for(int i = 0; i < _size; i++) //Print out all options
    {
        cout << " >- [" << i+1 << "] " << _options[i] << endl;
    }
    cout << " >- [" << _size+1 << "] Quit" << endl;

    input = inputInt(_size+1, 1);

    //If user chooses quit, default to 0
    if(input == _size+1)
    {
        return 0;
    }
    return input; //Otherwise, return
}

int main()
{
    Fraction fractionOne, fractionTwo, output; //Initialize containers for fractions including input and output
    int input = 0; //An input from the user
    string options[4] = {"Add", "Subtract", "Multiply", "Divide"}; //Options for the menu

    do
    {
        resetFractions(&fractionOne); //Call functions to randomize and display the fractions
        resetFractions(&fractionTwo);
        cout << "Fraction 1: " << &fractionOne << " Fraction 2: " << &fractionTwo << endl;

        input = menu("Fraction Exercise", options, 4); //Call function to display options and get user input

        if(input == 1)
        {
            output = fractionOne + fractionTwo;
        }
        else if(input == 2)
        {
            output = fractionOne - fractionTwo;
        }
        else if(input == 3)
        {
            output = fractionOne * fractionTwo;
        }
        else if(input == 4)
        {
            output = fractionOne / fractionTwo;
        }

        if(input != 0)
        {
            cout << " >- Result: " << &output << endl; //Output result
        }

        system("PAUSE"); //Wait for user input before wiping console
        system("CLS");
    }while(input != 0); //If user chooses quit, exit loop

    return 0;
}
