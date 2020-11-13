/*
>- Author: Max Wong
>- Date: November 11, 2020
>- Updated: Nov 13, 2020
>- Purpose: To write a cyoa editor -> to advance coding knowledge with more general case infrastructure

To Do
prototype creating txt files

data save/load
add page
display page hierarchy

*/

//declaring used libraries
#include <iostream>
#include <vector>        //For vectors
#include <limits>        //For error trapping

using namespace std;

struct Options //This stores an option on a page
{
    string text; //This is the text displayed for the option
    string link; //This will be used in to link to the next page
    string rand; //temporary spot for adding an operation later on
};

struct Page //This stores the page information for each option
{
    string title; //This is the title of the page
    string text; //This is tht text displayed for the page
    int optionCount; //This int represents the # of options
    vector<Options> options; //Keep a vector of options
};

void getAnswer(int, int, int*); //(min, max, input) //Function used to get the players response as an integer (with error trapping)
void writeFile(int, vector<Page>*); //This is for writing to a file
void readFile(int, vector<Page>*); //This is for reading form a file

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

//Error trapping funcion that only accepts integers
void getAnswer (int _minLimit, int _maxLimit, int* _value)
{
    int playerInput; //This variable is used to get the player's input
    bool findingInput; //This bool determines if the loop continues running
    do
    {
        findingInput = false; //By default, the loop will end
        cout << "    >- Your input: "; //Get player input
        cin >> playerInput;
        if(cin.fail())//Check to see if player entered a "bad" input type
        {
            cin.clear(); //Clear all flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore incorrect symbols
            cout << " >- Please enter  valid input" << endl;
            findingInput = true; //If the input is invalid, then the loop will loop
        }
        else if(playerInput > _maxLimit || playerInput < _minLimit ) //Otherwise, print an error message
        {
            cout << "  >- Please enter a number between " << _minLimit << " and " << _maxLimit << endl;
            findingInput = true; //If the input is invalid, then the loop will loop
        }
    }
    while(findingInput);
    *_value = playerInput;//Otherwise input is good, return input
    return;
}

//This is for writing to a file
void writeFile(int _file, vector<Page>* _pages)
{
    return;
}

//This is for reading form a file
void readFile(int _file, vector<Page>* _pages)
{
    return;
}
