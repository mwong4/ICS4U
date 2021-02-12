/*
Author: Max Wong
Date Created:Feb 12, 2020
Date Updated:Feb 12, 2020
Purpose: Doing merge sort

Source
From ICS3U projects by Max Wong
Srand based on time from Cplusplus.com: http://www.cplusplus.com/reference/cstdlib/srand/\
Stack Overflow page for inspiration on how to find nearest power of 2: https://stackoverflow.com/questions/466204/rounding-up-to-next-power-of-2#:~:text=next%20%3D%20pow(2%2C%20ceil,the%20nearest%20whole%20number%20power.
*/
#include <iostream>
#include <limits>        //For error trapping
#include <windows.h>     //For system commands
#include <stdlib.h>      //For srand
#include <time.h>        //For time
#include <stdio.h>       //For Null
#include <math.h>        //For log()

using namespace std;

void mergeSort(int[], int, int); //Function that sorts using merge sort

//General functions
int menu(string, string[], int); //Function used to output options to user and get input
int inputInt(int, int); //Function used to get the players response as an integer (with error trapping)
void resetArray(int[], int); //For resetting the array
void printArray(int[], int); //For printing the array

int main()
{
    string options[1] = {"Sort"}; //List of options for menu
    int input; //user input
    int elements[8]; //This is the array being sorted

    resetArray(elements, 8);
    printArray(elements, 8);

    input = menu("Merge Sort", options, 1);

    if(input == 1)
    {
        mergeSort(elements, 0, 8);
    }

    printArray(elements, 8);

    return 0;
}

//Function that sorts using merge sort
void mergeSort(int _array[], int _min, int _max)
{
    int aSize = _max - _min;
    int mid = pow(2, floor(log(aSize)/log(2))); //Calculate closest power of 2 (floor)
    int tempInt; //Used for swapping
    int markerLeft = _min; //used when merging back to current position on left half
    int markerRight = mid; //used when merging back to current position on right half
    int tempArray[aSize]; //In place of a link list

    if(aSize == 1) //If reaching a boolean comparison
    {
        //compare, return
        if(_array[_max-1] < _array[_min])
        {
            tempInt = _array[_max-1]; //Swap
            _array[_max-1] = _array[_min];
            _array[_min-1] = tempInt;

            return;
        }
    }
    else if(_max == _min) //If single digit, not pair, return single as smallest
    {
        return;
    }
    else
    {
        //Do the splitting, call function twice for oth halves
        mergeSort(_array, _min, mid);
        mergeSort(_array, mid, _max);
    }

    //DO the merge back
    for(int i = 0; i < aSize; i++)
    {
        if(markerLeft == mid) //If left half has reached cap, fill in with right half
        {
            tempArray[i] = _array[markerRight]; //Insert into temporary array
            markerRight ++; //Increase marker
        }
        else if(markerRight == _max)  //If right half has reached cap, fill in with left half
        {
            tempArray[i] = _array[markerLeft]; //Insert into temporary array
            markerLeft ++; //Increase marker
        }
        else if(_array[markerLeft] > _array[markerRight]) //Oterhwise if marker on right is smallest
        {
            tempArray[i] = markerRight; //Insert right marker
            markerRight++; //Increase marker
        }
        else
        {
            tempArray[i] = markerLeft; //Otherwise, insert left marker
            markerLeft ++; //Increase marker
        }
    }

    for(int i = 0; i < aSize; i++) //Go through the temp array and copy it all back to the main array
    {
        _array[i] = tempArray[i];
    }

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

//For resetting the array
void resetArray(int _array[], int _size)
{
    for(int i = 0; i < _size; i++) //Go through every element, randomize value
    {
        _array[i] = rand() % 10;
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
