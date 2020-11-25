/*
>- Author: Max Wong
>- Date: November 11, 2020
>- Updated: Nov 25 , 2020
>- Purpose: To write a cyoa editor -> to advance coding knowledge with more general case infrastructureo

To Do
prototype creating txt files

add page
display page hierarchy

*/

//declaring used libraries
#include <iostream>
#include <vector>        //For vectors
#include <limits>        //For error trapping
#include <fstream>       //For txt file
#include <stdlib.h>      //For type conversion
#include <windows.h>     //For windows stuff

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
void readFile(int, vector<Page>*, int*); //This is for reading form a file
void displayPage(Page); //For displaying an individual page
void displayAllPages(vector<Page>, int); //To display all pages

int main()
{
    vector<Page> pages; //This contains the data for all the pages
    int pageSize = 0; //This stores the # of pages

    readFile(1, &pages, &pageSize); //Call function to read page data

    cout << "Read File" << endl;

    cout << pages[0].options[0].text << endl;

    //displayPage(pages[1]);
    displayAllPages(pages, pageSize); //call function to display all pages

    system("PAUSE");

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
void readFile(int _file, vector<Page>* _pages, int* _size)
{
    cout << "reading file" << endl;
    ifstream pageFile_("pageData.txt"); //This is used to store file raw data
    ifstream playerFile_("playerData.txt"); //This is used to store file raw data

    string line; //String line used to seperate the text file into lines
    Page tempPage; //temporary page to input into vector
    Option tempOption; //temporary option to put inot vector
    int lineRow = -4; //This integer keeps count of the row number for the saving in array
    int optionsMax = 0; //This tracks how many options need to be read
    int optionsCount = 0; //This tracks the # of options currently read
    int pageCount = 0; //Tracks how many pages have been read
    bool atStart = true; //Checks if at start or not

    if(pageFile_.is_open() && _file == 1) //If instricted to save the file
    {
        //reset vector
        *_size = 0;
        (*_pages).clear();

        while(getline(pageFile_,line)) //This function uses the builtin function: getline
        {
            if(!atStart) //for each page
            {
                if(lineRow < 0)
                {
                    if(lineRow == -3)
                    {
                        tempPage.title = line; //save title temporarily
                        //cout << "Title: " << tempPage.title << endl;
                    }
                    if(lineRow == -2)
                    {
                        tempPage.text = line; //save text for page temp
                        //cout << "Text: " << tempPage.text << endl;
                    }
                    if(lineRow == -1)
                    {
                        tempPage.optionCount = atoi(line.c_str()); //get # of options
                        optionsMax = atoi(line.c_str()); //update cap for options
                        //cout << "Max: " << optionsMax << endl;
                    }
                }
                else if(lineRow % 3 == 0)
                {
                    tempOption.text = line; //for each option, save text
                    //cout << "Options Text: " << tempOption.text << endl;
                }
                else if(lineRow % 3 == 1)
                {
                    tempOption.link = line; //for each option, save link
                    //cout << "Options Link: " << tempOption.link << endl;
                }
                else if(lineRow % 3 == 2)
                {
                    tempOption.rand = line; //fill this with null for now
                    //cout << "Options Rand: " << tempOption.rand << endl;
                    tempPage.options.push_back(tempOption); //push back option to options vector in page
                    optionsCount ++;

                    if(optionsCount == optionsMax) //if gone through all options
                    {
                        pageCount ++; //tick up page count
                        (*_pages).push_back(tempPage); //push back page to main vector tracking pages
                        //cout << "push page" << endl;

                        lineRow = -4; //reset fir new page read
                        optionsCount = 0;
                        optionsMax = 0;
                        tempPage.options.clear();
                    }
                    else //otherwise, repeat
                    {
                        lineRow = -1;
                    }
                }
            }
            else //pre-read of page stuff
            {
                *_size = atoi(line.c_str()); //update how many pages there are
                atStart = false;
            }

            lineRow ++; //each cycle, move forwards with line #
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

//For displaying an individual page
void displayPage(Page _page)
{
    cout << "//////////" << _page.title << "//////////" << endl << endl; //Display page data
    cout << _page.text << endl << endl;

    //cout << _page.optionCount << endl;

    for(int i = 0; i < _page.optionCount; i++) //Go through vector and display all otions data
    {
        cout << "[" << i << "] " << _page.options[i].text << " -> " << _page.options[i].link << " || " << _page.options[i].rand << endl;
    }
    cout << endl;

    return;
}

//To display all pages
void displayAllPages(vector<Page> _pages, int _count)
{
    for(int i = 0; i < _count; i++) //go through vector and display each page
    {
        displayPage(_pages[i]);
    }

    return;
}
