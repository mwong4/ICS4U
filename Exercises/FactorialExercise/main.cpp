/*
Author: Max Wong
Date Created:Feb 10, 2020
Date Updated:Feb 10, 2020
Purpose: Do factorial recursively

Source
Error Trapping from ICS3U projects by Max Wong
*/

#include <iostream>
#include <limits>        //For error trapping

using namespace std;

int factorial(int); //Function for factorial
void inputInt(int, int, int*); //Function used to get the players response as an integer (with error trapping)

int main()
{
    int input; //Input from user

    cout << " >- Enter an integer between 0 and 9999, inclusively" << endl;
    inputInt(9999, 0, &input); //Call function to get input

    cout << endl << " >- " << input << "! = " << factorial(input) << endl; //Call function to perform factorial
    return 0;
}

//Function for factorial
int factorial(int _size)
{
    if(_size == 0 || _size == 1) //If case is 0 or 1, return 1
    {
        return 1;
    }
    else //Otherwise call factorial function, but with _size-1
    {
        return _size*factorial(_size-1);
    }
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
