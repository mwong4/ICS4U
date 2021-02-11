/*
Author: Max Wong
Date Created:Feb 10, 2020
Date Updated:Feb 11, 2020
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
#include <stdio.h>       //For NULL
#include <tgmath.h>      //For floor

using namespace std;

//Smallest and 2nd smallest functions
int smallest(int[], int); //Recursively finds the smallest value
int secondSmallest(int[], int, int, int); //Recursively find the second smallest value
//General functions
int menu(string, string[], int); //Function used to output options to user and get input
int inputInt(int, int); //Function used to get the players response as an integer (with error trapping)
void resetArray(int[], int); //For resetting the array
void printArray(int[], int); //For printing the array

int main()
{
    int input = 1; //Input from user
    int elements[8]; //The array that will be used
    string options[3] = {"Smallest", "Second Smallest", "Randomize Array"}; //Options for menu

    srand(time(NULL)); //Randomize srand based on time

    resetArray(elements, 8);//Randomize array

    while(input != 0)
    {
        printArray(elements, 8);//Print array
        input = menu("Recursive Exercise 2", options, 3); //Call menu function

        if(input == 1) //If find smallest is chosen
        {
            cout << " >- Smallest: " << smallest(elements, 8) << endl; //Call function and print out
        }
        else if(input == 2) //If find second smallest is chosen
        {
            cout << " >- Second Smallest: " << secondSmallest(elements, 8, 10000, 100000) << endl;
        }
        else if(input == 3) //If randomize array is chosen
        {
            resetArray(elements, 8); //Call function to reset array
        }

        system("pause"); //Wait for user input before scrambling
        system("CLS");
    }

    return 0;
}

//Recursively finds the smallest value
int smallest(int _array[], int _size)
{
    int smallVal; //The smallest value

    if(_size == 0) //If at base case, return current value
    {
        return _array[0];
    }
    else //Otherwise take the current element and all other before it, return which one is smaller
    {
        smallVal = smallest(_array, _size-1); //Perform calculation to find smallest first

        if(smallVal > _array[_size-1]) //Current one is smaller
        {
            return _array[_size-1];
        }
        else //all others before are smaller
        {
            return smallVal;
        }
    }
}

//Recursively find the second smallest value
int secondSmallest(int _array[], int _size, int _smallest, int _secondSmallest)
{
    cout << "[" << _size << "]Smallest: " << _smallest << " Second Smallest: " << _secondSmallest << endl;
    if(_array[_size-1] < _smallest) //If smaller than smallest
    {
        _secondSmallest = _smallest; //Shuffle smallest as second smallest
        _smallest = _array[_size-1]; //Shuffle smallest as position iin array
    }
    else if(_array[_size-1] < _secondSmallest && _smallest <= _array[_size-1]) //Else if between smallest and second smallest
    {
        _secondSmallest = _array[_size-1]; //Set as new second smallest
    }

    if(_size == 0) //If end of array is reached, return second smallest up chain
    {
        return _secondSmallest;
    }

    return secondSmallest(_array, _size-1, _smallest, _secondSmallest); //Otherwise, by default call function again
}

//Function used to output options to user and get input
int menu(string _title, string _options[], int _size)
{
    int input; //Input from user

    cout << "///// " << _title << " /////" << endl;
    for(int i = 0; i < _size; i++)
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
void printArray(int _array[], int _size)
{
    cout << " >- ";
    for(int i = 0; i < _size; i++) //Go through every element, randomize value
    {
        cout << _array[i] << " ";
    }
    cout << endl;
    return;
}
