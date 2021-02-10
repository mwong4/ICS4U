/*
Author: Max Wong
Date Created:Feb 10, 2020
Date Updated:Feb 10, 2020
Purpose: Find smallest and second smallest recursively

Source
Error Trapping from ICS3U projects by Max Wong
Srand based on time from Cplusplus.com: http://www.cplusplus.com/reference/cstdlib/srand/
*/

#include <iostream>
#include <limits>        //For error trapping
#include <windows.h>     //For system commands
#include <stdlib.h>      //For srand
#include <time.h>        //For time
#include <stdio.h>       //For Null
#include <tgmath.h>      //For floor

using namespace std;

//Smallest and 2nd smallest functions
int smallest(int[], int, int); //Recursively finds the smallest value

//General functions
void menu(string, string[], int, int*); //Function used to output options to user and get input
void inputInt(int, int, int*); //Function used to get the players response as an integer (with error trapping)
void resetArray(int[], int); //For resetting the array

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int smallest(int _array[], int _size)
{
    if(_size == 0)
    {
        return _array[0];
    }
    else if(_array[_size-1] > smallest(_array[], _size-1))
    {
        return smallest(_array[], _size-1);
    }
    else
    {
        return _array[_size-1];
    }
}

//Function used to output options to user and get input
void menu(string _title, string _options[], int _size, int* _value)
{
    cout << "///// " << _title << " /////" << endl; //Print title and all of the options
    for(int i = 0; i < _size; i++)
    {
        cout << " >- [" << i+1 << "] " << _options[i] << endl;
    }
    cout << " >- [" << _size+1 << "] Quit" << endl;

    inputInt(_size+1, 1, _value); //Call function to get user input

    if(*_value == _size+1) //If user chooses quit, default to 0
    {
        *_value = 0;
    }
    return;
}

//Error trapping funcion that only accepts integers
void inputInt (int _maxLimit, int _minLimit, int* _value)
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
    *_value = playerInput;//Save value, return input
    return;
}

//For resetting the array
void resetArray(int _array[], int _size)
{
    for(int i = 0; i < _size; i++) //Go through every element, randomize value
    {
        _array[i] = rand() % 15;
    }
    return;
}

//For printing the array
void resetArray(int _array[], int _size)
{
    cout << " >- "
    for(int i = 0; i < _size; i++) //Go through every element, randomize value
    {
        cout << _array[i] << " ";
    }
    cout << endl;
    return;
}
