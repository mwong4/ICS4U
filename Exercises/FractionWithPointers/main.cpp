/*
Author: Max Wong
Date Created:Feb 22, 2021
Date Updated:Feb 22, 2021
Purpose: Standard functions for all projects

Source
From ICS3U projects by Max Wong

TODO
-Add
-Subctract
-Multiply
-Divide
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
//Operations for the exercise
void add(Fraction*, Fraction*, Fraction*); //Function for adding
void sub(Fraction*, Fraction*, Fraction*); //Function for subtracting
void mul(Fraction*, Fraction*, Fraction*); //Function for multiplying
void div(Fraction*, Fraction*, Fraction*); //Function for dividing
void displayFractions(Fraction*, Fraction*); //Used to display the fraction
void resetFractions(Fraction*, Fraction*); //Used to reset the fraction

//General Functions
int menu(string, string[], int); //Function used to output options to user and get input
int inputInt(int, int); //Function used to get the players response as an integer (with error trapping)

int main()
{
    Fraction fractionOne, fractionTwo, output; //Initialize containers for fractions including input and output
    int input = 0; //An input from the user
    string options[4] = {"Add", "Subtract", "Multiply", "Divide"}; //Options for the menu

    do
    {
        resetFractions(&fractionOne, &fractionTwo); //Call functions to randomize and display the fraction
        displayFractions(&fractionOne, &fractionTwo);

        input = menu("Fraction Exercise", options, 4); //Call function to display options and get user input

        if(input == 1)
        {
            add(&fractionOne, &fractionTwo, &output);
        }
        else if(input == 2)
        {
            sub(&fractionOne, &fractionTwo, &output);
        }
        else if(input == 3)
        {
            mul(&fractionOne, &fractionTwo, &output);
        }
        else if(input == 4)
        {
            div(&fractionOne, &fractionTwo, &output);
        }
        cout << " >- Result: " << output.numerator << "/" << output.denominator << endl; //Output result


        system("PAUSE"); //Wait for user input before wiping console
        system("CLS");
    }while(input != 0); //If user chooses quit, exit loop

    return 0;
}

//Function for adding
void add(Fraction *_fracOne, Fraction *_fracTwo, Fraction *_output)
{
    (*_output).numerator = ((*_fracOne).numerator * (*_fracTwo).denominator) + ((*_fracTwo).numerator * (*_fracOne).denominator);
    (*_output).denominator = (( *_fracOne).denominator) * (( *_fracTwo).denominator);
    return;
}

//Function for subtracting
void sub(Fraction *_fracOne, Fraction *_fracTwo, Fraction *_output)
{
    (*_output).numerator = ((*_fracOne).numerator * (*_fracTwo).denominator) - ((*_fracTwo).numerator * (*_fracOne).denominator);
    (*_output).denominator = (( *_fracOne).denominator) * (( *_fracTwo).denominator);
    return;
}

//Function for multiplying
void mul(Fraction *_fracOne, Fraction *_fracTwo, Fraction *_output)
{
    (*_output).numerator = (( *_fracOne).numerator) * (( *_fracTwo).numerator);
    (*_output).denominator = (( *_fracOne).denominator) * (( *_fracTwo).denominator);
    return;
}

//Function for dividing
void div(Fraction *_fracOne, Fraction *_fracTwo, Fraction *_output)
{
    (*_output).numerator = (( *_fracOne).numerator) * (( *_fracTwo).denominator);
    (*_output).denominator = (( *_fracOne).denominator) * (( *_fracTwo).numerator);
    return;
}

//Used to display the fraction
void displayFractions(Fraction *_fracOne, Fraction *_fracTwo)
{
    cout << " >- Fraction One: " << (*_fracOne).numerator << "/" << (*_fracOne).denominator << " Fraction Two: " << (*_fracTwo).numerator << "/" << (*_fracTwo).denominator << endl;
    return;
}

//Used to reset the fraction
void resetFractions(Fraction *_fracOne, Fraction *_fracTwo)
{
    (*_fracOne).numerator = 1+ rand() % 10;
    (*_fracOne).denominator = 1 + rand() % 10;
    (*_fracTwo).numerator = 1 + rand() % 10;
    (*_fracTwo).denominator = 1 + rand() % 10;
    return;
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
