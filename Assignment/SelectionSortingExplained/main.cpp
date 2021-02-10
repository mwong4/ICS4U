/*
Author: Max Wong
Date Created:Feb 9, 2020
Date Updated:Feb 10, 2020
Purpose: Show selecion sorting

Source
Error Trapping from ICS3U projects by Max Wong
Color idea from Stack Overflow Forum: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
Srand based on time from Cplusplus.com: http://www.cplusplus.com/reference/cstdlib/srand/

*/
#include <iostream>
#include <limits>        //For error trapping
#include <windows.h>     //For system commands
#include <stdlib.h>      //For srand
#include <time.h>        //For time
#include <stdio.h>       //For Null

using namespace std;

//Sorting function
void selectionSort(int[], int); //For selection sorting

//General functions
void menu(string, string[], int, int*); //Function used to output options to user and get input
void inputInt(int, int, int*); //Function used to get the players response as an integer (with error trapping)
void printArray(int[], int, string, int, int, int, int, int); //For printing out the array
void resetArray(int[], int); //For resetting the array
void printLegend(); //Used for printing the color legend

int main()
{
    srand(time(NULL)); //Srand based on time

    string options[1] = {"Run sort"}; //list of options for menu
    int input; //Input from user

    int elements[8]; //Array being sorted
    const int arraySize = 8; //Length of the array

    do
    {
        resetArray(elements, arraySize); //Call function to randomize array
        printArray(elements, arraySize, " ", 0, 0, 0, 0, 0); //Call function to print out array
        cout << endl;

        menu("Selection Sort", options, 1, &input); //Call menu function

        if(input == 1)
        {
            printLegend(); //Call function to print legend
            cout << endl;
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
            printArray(_elements, _size, "//Comparing", i-1, smallestPos, j, 0, 0); //Call function to display array
            if(_elements[j] < smallest) //If a smaller value is found, save
            {
                smallest = _elements[j]; //Save smallest value and smallest position
                smallestPos = j;

                printArray(_elements, _size, "//Found new smallest", i-1, smallestPos, j, 0, 0); //Call function to display array
            }
        }

        tempInt = smallest; //swap values
        _elements[smallestPos] = _elements[i];
        _elements[i] = tempInt;

        printArray(_elements, _size, "//Swap", i, smallestPos, 0, i, smallestPos); //Call function to display array
    }
    return;
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

//For printing out the array (green for correct, blue for current smallest, yellow for currently being checked, red 1 & 2 for being swapped)
void printArray(int _elements[], int _elementsSize, string _message, int _green, int _blue, int _yellow, int _redOne, int _redTwo)
{
    HANDLE  hConsole; //For color, 1=blue, 2=green, 6=yellow, 4=red, 15=white
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(_message == " ") //NOT showing explanation mode
    {
        cout << " >- Elements: ";
    }
    else //Showing explanation mode
    {
        if(_message != "//Swap") //If not swapping
        {
            cout << " >- Pass [" << _green+2 << "]:"; //_green+2 is the current pass number
        }
        else //Otherwise, when swapping
        {
            cout << " >- Pass [" << _green+1 << "]:"; //_green+1 is the current pass number
        }
    }

    for(int i = 0; i < _elementsSize; i++) //Go through each element in the array
    {
        if(_message == " ") //if message does not need any explanation, print normally
        {
             cout << _elements[i] << " ";
        }
        else //Otherwise add all of the explanation color coding
        {
            if(i == _blue && _message != "//Swap") //if i equals to blue marker, color blue
            {
                SetConsoleTextAttribute(hConsole, 1);
            }
            else if(i <= _green && _message != "//Swap") //if before or equal to green marker, color green
            {
                SetConsoleTextAttribute(hConsole, 2);
            }
            else if(i == _yellow && _message != "//Swap") //if i equals to yellow marker, color yellow
            {
                SetConsoleTextAttribute(hConsole, 6);
            }
            else if((i == _redOne || i == _redTwo) && _message == "//Swap") //if i equals to any red marker, color red
            {
                SetConsoleTextAttribute(hConsole, 4);
            }
            cout << _elements[i] << " ";
            SetConsoleTextAttribute(hConsole, 15); //otherwise, reset to white
        }
    }
    cout << "              " << _message << endl; //Print message
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

//Used for printing the color legend
void printLegend()
{
    HANDLE  hConsole; //For color, 1=blue, 2=green, 6=yellow, 4=red, 15=white
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl << ">- [LEGEND]: ";
    SetConsoleTextAttribute(hConsole, 2); //Set colour to green
    cout << "Already Sorted, ";
    SetConsoleTextAttribute(hConsole, 1); //Set colour to blue
    cout << "Current Smallest, ";
    SetConsoleTextAttribute(hConsole, 6); //Set colour to yellow
    cout << "Being Compared to Smallest, ";
    SetConsoleTextAttribute(hConsole, 4); //Set colour to red
    cout << "Being Swapped, ";
    SetConsoleTextAttribute(hConsole, 15); //Set colour to white

    return;
}
