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

int menu(string, string[], int); //Function used to output options to user and get input
int inputInt(int, int); //Function used to get the players response as an integer (with error trapping)

int main()
{
    string options[3] = {"test 1", "test 2", "test 3"};
    int input;

    input = menu("Test Menu", options, 3);
    cout << "chose: " << input << endl;

    return 0;
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
