/*
Author: Max Wong
Date Created:Feb 11, 2020
Date Updated:Feb 11, 2020
Purpose: To find the specific element in Pascal's traingle

Source
From ICS3U projects by Max Wong
*/

#include <iostream>
#include <limits>        //For error trapping

using namespace std;

int inputInt(int, int); //Function used to get the players response as an integer (with error trapping)
int pascalTriangle(int, int); //Function that recursivley finds the element of a specific row and position in Pascal's triangle

int main()
{
    int row; //User input for row
    int position; //User input for position

    cout << " >- Enter row (between 0 and 9999 inclusively): " << endl;
    row = inputInt(9999, 0);
    cout << " >- Enter position (between 0 and 9999 inclusively): " << endl;
    position = inputInt(9999, 0);

    cout << " >- Element in Pascal's traingle is: " << pascalTriangle(row, position) << endl;

    return 0;
}

//Function that recursivley finds the element of a specific row and position in Pascal's triangle
int pascalTriangle(int _row, int _pos)
{
    if(_pos == 0 || (_row == _pos)) //if on the outer sides, return 1
    {
        return 1;
    }
    else
    {
        return pascalTriangle(_row-1, _pos-1) + pascalTriangle(_row-1, _pos);
    }
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
