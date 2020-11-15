/*
>- Author: Max Wong
>- Date: November 11, 2020
>- Updated: Nov 13, 2020
>- Purpose: To write a cyoa editor -> to advance coding knowledge with more general case infrastructureo

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
#include <fstream>       //For txt file

using namespace std;

struct Option //This stores an option on a page
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
    vector<Option> options; //Keep a vector of options
};

void getAnswer(int, int, int*); //(min, max, input) //Function used to get the players response as an integer (with error trapping)
void writeFile(int, vector<Page>*); //This is for writing to a file
void wipeFile(int); //This is for wiping a file
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
void writeFile(int _file, vector<Page>* _pages, int* _pageCount)
{
    ofstream myfile; //file to store raw data
    if(_file == 1)
    {
        myfile.open("pageData.txt"); //Open files
    }
    else if(_file == 2)
    {
        myfile.open("playerData.txt");
    }

    if(_file == 1) //if writing page data
    {
        for(int i = 0; i < *_pageCount; i++)
        {
            //write data that is from page
            myfile << (*_pages)[i].title << endl;
            myfile << (*_pages)[i].text << endl;
            myfile << (*_pages)[i].optionCount << endl;

            //write all options data
            for(int j = 0; j < (*_pages)[i].optionCount; j++)
            {
                myfile << (*_pages)[i].options[j].text << endl;
                myfile << (*_pages)[i].options[j].link << endl;
                myfile << (*_pages)[i].options[j].rand << endl;
            }
        }
    }
    else if(_file == 2) //if writing player data
    {
        cout << "skipped" << endl;
    }

    myfile.close(); //Close file
    return;
}

//Wipe file
void wipeFile(int _file)
{
    std::ofstream file;
    if(_file == 1)
    {
        file.open("pageData.txt", std::ofstream::out | std::ofstream::trunc);
    }
    else if(_file == 2)
    {
        file.open("playerData.txt", std::ofstream::out | std::ofstream::trunc);
    }
    file.close();
    return;
}

//This is for reading form a file
void readFile(int _file, vector<Page>* _pages)
{
    string line; //String line used to seperate the text file into lines
    if(_file == 1) ifstream pageFile_("pageData.txt"); //This is used to store file raw data
    else ifstream playerFile_("playerData.txt"); //This is used to store file raw data
    Page tempPage; //temporary page to input into vector
    Option tempOption //temporary option to put inot vector

    int lineRow = -3; //This integer keeps count of the row number for the saving in array

    if(pageFile_.is_open() && _file == 1) //If instricted to save the file
    {
        lineRow = 0;
        while(getline(pageFile_,line)) //This function uses the builtin function: getline
        {
            if(lineRow < 0)
            {
                if(lineRow == -3) //Run at very start
                {
                    *_balance = atoi(line.c_str()); //update balance
                }
                if(lineRow == -2)
                {
                    *_date = atoi(line.c_str()); //update date
                }
                if(lineRow == -1)
                {
                    *_cap = atoi(line.c_str()); //update cap
                }
            }
            else if(lineRow % 6 == 0)
            {
                tempStock.name = line;
            }
            else if(lineRow % 6 == 1)
            {
                tempStock.cost = atoi(line.c_str());
            }
            else if(lineRow % 6 == 2)
            {
                tempStock.dividend = atoi(line.c_str());
            }
            else if(lineRow % 6 == 3)
            {
                tempStock.status = line;
            }
            else if(lineRow % 6 == 4)
            {
                tempStock.timeOwned = atoi(line.c_str());
            }
            else if(lineRow % 6 == 5)
            {
                tempStock.triedSelling = false; //by default set to false
                tempStock.extraInfo = line;
                (*_stocks).push_back(tempStock);
                *_size += 1;
            }
            lineRow += 1;
        }
        pageFile_.close(); //Close file
    }
    else if(playerFile_.is_open() && _file == 2) //If instricted to save the file
    {
        cout << "skipped" << endl;
        playerFile_.close(); //Close file
    }

    return;
}
