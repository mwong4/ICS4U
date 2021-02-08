/*
Author: Max Wong
Date Created:Feb 8, 2020
Date Updated:Feb 8, 2020
Purpose: Standard functions for all projects

Source
From ICS3U projects by Max Wong
*/
#include <iostream>
#include <limits>        //For error trapping

using namespace std;

void menu(string, string[], int, int*); //Function used to output options to user and get input
void inputInt(int, int, int*); //Function used to get the players response as an integer (with error trapping)

int main()
{
    string options[] = {"test 1", "test 2", "test 3"};
    int opSize = 3;
    int input;

    menu("Test Menu", options, opSize, &input);
    cout << "chose: " << input << endl;

    return 0;
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
