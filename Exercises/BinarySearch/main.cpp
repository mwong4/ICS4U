/*
Author: Max Wong
Date Created:Feb 11, 2020
Date Updated:Feb 11, 2020
Purpose: Perform binary search recursively

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

bool binarySearch(int[], int, int, int); //Function that performs binary search recursively

//General functions
int menu(string, string[], int); //Function used to output options to user and get input
int inputInt(int, int); //Function used to get the players response as an integer (with error trapping)
void resetArray(int[], int); //For resetting the array
void printArray(int[], int); //For printing the array

int main()
{
    srand(time(NULL)); //Randomize srand based on time

    string options[1] = {"Search"}; //List of options
    int input; //For getting player input

    int elements[8]; //This is the array where the binary search is being performed

    do
    {
        resetArray(elements, 8); //Randomize array values
        printArray(elements, 8); //Print array

        input = menu("Binary Search", options, 1);

        if(input != 0)
        {
            cout << " >- Please enter integer between 0 and 99 inclusively" << endl;
            input = inputInt(99, 0); //Get user input on element being searched

            if(binarySearch(elements, 0, 8, input)) //Call function to perform binary search and print out result
            {
                cout << " >- [TRUE] " << input << " is present" << endl;
            }
            else
            {
                cout << " >- [FALSE] cannot find " << input << endl;
            }

            system("PAUSE"); //get any input before clearing console
            system("CLS");

            input = 1; //Reset input so loop will continue
        }
    }while(input != 0);

    return 0;
}

//Function that performs binary search recursively
bool binarySearch(int _array[], int _min, int _max, int _target)
{
    int mid = _min + (floor((_max-_min)/2)); //Calculate midpoint (default to bottom one)

    if(mid == _min) //if reached single element, determine if element is target
    {
        if(_array[mid] == _target) //If yes, return true, else return false
        {
            return true;
        }
        return false;
    }
    else if(_target > _array[mid]) //If target is in top half
    {
        return binarySearch(_array, mid, _max, _target); //Call function to repeat process in top half
    }
    else if(_target < _array[mid]) //Else if target is in bottom half
    {
        return binarySearch(_array, _min, mid, _target); //Call function to repeat process in bottom half
    }
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

//For resetting the array
void resetArray(int _array[], int _size)
{
    int counter = 0; //Counts up values
    for(int i = 0; i < _size; i++) //Go through every element, randomize value
    {
        counter += rand() % 5; //Increases counter randomly
        _array[i] = counter;
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
