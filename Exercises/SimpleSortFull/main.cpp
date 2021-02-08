/*
Author: Max Wong
Date Created:Feb 8, 2020
Date Updated:Feb 8, 2020
Purpose: fully implemented sorting for all 3 basic systems

Source
Error Trapping from ICS3U projects by Max Wong
*/

#include <iostream>
#include <limits>        //For error trapping
#include <windows.h>       //For system commands

using namespace std;

//Sorting functions
void bubbleSort(int[], int); //For bubble sorting
void insertionSort(int[], int); //For insertion sorting
void selectionSort(int[], int); //For selection sorting

//General functions
void menu(string, string[], int, int*); //Function used to output options to user and get input
void inputInt(int, int, int*); //Function used to get the players response as an integer (with error trapping)
void printArray(int[], int); //For printing out the array
void resetArray(int[]); //For resetting the array

int main()
{
    //Test case
    int elementsSize = 9; //For the array size
    int elements[9]; //The array storing the test case

    //For menu
    int input; //The value that the user inputs
    string options[3] = {"Bubble Sort", "Insertion Sort", "Selection Sort"};

    do
    {
        resetArray(elements); //Call function to reset array

        //Print out to user the test case
        cout << " >- Size: " << elementsSize << endl;
        printArray(elements, elementsSize); //Call function to print out array
        cout << endl;

        menu("Basic Sort Methods", options, 3, &input); //Call menu to get input

        if(input != 0) //If quit is not chosen
        {
            //Call sort function for the method chosen by user
            cout << endl << ">- Sorting now..." << endl << endl;
            if(input == 1)
            {
                bubbleSort(elements, elementsSize);
            }
            else if(input == 2)
            {
                insertionSort(elements, elementsSize);
            }
            else if(input == 3)
            {
                selectionSort(elements, elementsSize);
            }

            cout << endl;
            printArray(elements, elementsSize); //Call function to print out array
        }
        system("PAUSE"); //Wait for input before wiping screen
        system("CLS");

    }while(input != 0); //Repeats if user does not choose "quit"

    return 0;
}

//For bubble sorting
void bubbleSort(int _elements[], int _size)
{
    int latestSwap = _size; //Tracks most recent swap location
    int limit = latestSwap; //To know how far the comparisons should go
    bool swapped = true; //Boolean to know when there is a full pass without a swap
    int tempInt; //temporary integer for swapping

    while(swapped) //manaeges # of passes
    {
        swapped = false;
        for(int i = 1; i < limit; i++) //Manages comparisons in pass
        {
            if(_elements[i] < _elements[i-1]) //If comparison shows improper order, swap
            {
                swapped = true; //Update trackers for the loops
                latestSwap = i+1;
                //swap values
                tempInt = _elements[i-1];
                _elements[i-1] = _elements[i];
                _elements[i] = tempInt;
            }
        }
        limit = latestSwap; //Update limit
    }
    return;
}

//For insertion sorting
void insertionSort(int _elements[], int _size)
{
    int counter; //For keeping track of element when inserting
    int tempInt; //For swapping

    for(int i = 1; i < _size; i++)
    {
        counter = 1; //Reset counter
        while(_elements[i-counter+1] < _elements[i-counter]) //If element to the left of "target" is larger, swap
        {
            //swap values
            tempInt = _elements[i-counter];
            _elements[i-counter] = _elements[i-counter+1];
            _elements[i-counter+1] = tempInt;

            counter ++; //Update counter
        }
    }
    return;
}

//For selection sorting
void selectionSort(int _elements[], int _size)
{
    int smallest; //Tracks the smallest value found
    int smallestPos; //Tracks the smallest value location
    int tempInt; //temporary integer for swapping

    for(int i = 0; i < _size-1; i++) //Controls passes
    {
        smallest = _elements[i]; //Reset smallest values
        smallestPos = i;
        for(int j = i; j < _size; j++) //Go through and find smallest
        {
            if(_elements[j] < smallest) //If a smaller value is found, save
            {
                smallest = _elements[j]; //Save smallest and smallest position
                smallestPos = j;
            }
        }
        //swap values
        tempInt = smallest;
        _elements[smallestPos] = _elements[i];
        _elements[i] = tempInt;
    }

    return;
}

//Function used to output options to user and get input
void menu(string _title, string _options[], int _size, int* _value)
{
    cout << "///// " << _title << " /////" << endl;
    for(int i = 0; i < _size; i++)
    {
        cout << " >- [" << i+1 << "] " << _options[i] << endl;
    }
    cout << " >- [" << _size+1 << "] Quit" << endl;

    inputInt(_size+1, 1, _value);

    //If user chooses quit, default to 0
    if(*_value == _size+1)
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

//For printing out the array
void printArray(int _elements[], int _elementsSize)
{
    cout << " >- Elements: ";
    for(int i = 0; i < _elementsSize; i++)
    {
        cout << _elements[i] << " ";
    }
    cout << endl;
    return;
}

//For resetting the array
void resetArray(int _array[])
{
    _array[0] = 1;
    _array[1] = 3;
    _array[2] = 7;
    _array[3] = 9;
    _array[4] = 4;
    _array[5] = 8;
    _array[6] = 3;
    _array[7] = 1;
    _array[8] = 6;
    return;
}
