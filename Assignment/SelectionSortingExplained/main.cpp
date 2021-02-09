/*
Author: Max Wong
Date Created:Feb 9, 2020
Date Updated:Feb 9, 2020
Purpose: Show selecion sorting

Source
Error Trapping from ICS3U projects by Max Wong
Color idea from Stack Overflow Forum: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
*/
#include <iostream>
#include <limits>        //For error trapping
#include <windows.h>       //For system commands

using namespace std;

//Sorting function
void selectionSort(int[], int); //For selection sorting

//General functions
void menu(string, string[], int, int*); //Function used to output options to user and get input
void inputInt(int, int, int*); //Function used to get the players response as an integer (with error trapping)
void printArray(int[], int); //For printing out the array
void resetArray(int[], int); //For resetting the array

int main()
{
    string options[1] = {"Run sort"}; //list of options for menu
    int input; //Input from user

    int elements[9]; //Array being sorted
    const int arraySize = 9; //Length of the array

    do
    {
        resetArray(elements, arraySize); //Call function to randomize array
        printArray(elements, arraySize); //Call function to print out array
        cout << endl;

        menu("Selection Sort", options, 1, &input); //Call menu function

        if(input == 1)
        {
            selectionSort(elements, arraySize); //Call function to do the selection sort
        }

        system("PAUSE"); //Wait for user input before clearing console
        system("CLS");

    }while(input != 0);

    return 0;
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
void resetArray(int _array[], int _size)
{
    for(int i = 0; i < _size; i++) //Go through every element, randomize value
    {
        _array[i] = rand() % 100;
    }
    return;
}

