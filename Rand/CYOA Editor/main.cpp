/*
>- Author: Max Wong
>- Date: November 11, 2020
>- Updated: Nov 26, 2020
>- Purpose: To write a cyoa editor -> to advance coding knowledge with more general case infrastructureo

To Do

edit page
add are you sure section to edit page

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
void writeFile(int, vector<Page>*, int*); //This is for writing to a file
void wipeFile(int); //This is for wiping a file
void readFile(int, vector<Page>*, int*); //This is for reading form a file
void displayPage(Page); //For displaying an individual page
void displayAllPages(vector<Page>, int); //To display all pages
void addPage(vector<Page>*, int*); //This function is used to add a new page entry
void modPage(vector<Page>*, int*, int); //This function is used to modify a specific page
void deletePage(vector<Page>*, int*, int); //This function is used to delete a specific page

int main()
{
    vector<Page> pages; //This contains the data for all the pages
    int pageSize = 0; //This stores the # of pages

    readFile(1, &pages, &pageSize); //Call function to read page data
    cout << "Read File [main]" << endl;

    displayAllPages(pages, pageSize); //call function to display all pages

    addPage(&pages, &pageSize);
    cout << "Added Page [main]" << endl;

    readFile(1, &pages, &pageSize); //Call function to read page data
    cout << "Read File [main]" << endl;

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

    cout << "<Got Answer>" << endl;
    return;
}

//This is for writing to a file
void writeFile(int _file, vector<Page>* _pages, int* _pageCount)
{
    ofstream myfile; //file to store raw data
    if(_file == 1)
    {
        myfile.open("pageData.txt"); //Open files
        myfile << *_pageCount << endl;
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

    cout << "<Wrote to File>" << endl;
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

    cout << "<Wiped File>" << endl;
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

    cout << "<Read File>" << endl;
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

    cout << "<Displayed All Pages>" << endl;
    return;
}

//This function is used to add a new page entry
void addPage(vector<Page>* _pages, int* _pageCount)
{
    int intInput; //This is the integer input from the player
    string strInput; //This is the string input from the player
    Page tempPage; //This is to temporarily store a page data
    Option tempOption; //This is to temporarily store option data

    cout << "    [Add Page Editor]" << endl;
    cout << " >- Enter Page Title" << endl;
    getline(cin, strInput);
    tempPage.title = strInput; //Get title input

    cout << " >- Enter Page Text" << endl;
    getline(cin, strInput);
    tempPage.text = strInput; //get text input

    cout << " >- How many options would you like? (enter 1-10)" << endl;
    getAnswer(1, 10, &intInput); //get # of pages input
    tempPage.optionCount = intInput;
    cin.ignore(); //Clears up cin to be able to use getline (unreliable)

    //For each option, get all inputs
    for(int i = 1; i <= intInput; i++)
    {
        cout << "   [OPTION " << i << "]" << endl;
        cout << " >- Enter Option Text" << endl;
        getline(cin, strInput);
        tempOption.text = strInput; //Get text input

        cout << " >- Enter Option Link" << endl;
        getline(cin, strInput);
        tempOption.link = strInput; //Get link input

        cout << " >- Enter Option Rand" << endl;
        getline(cin, strInput);
        tempOption.rand = strInput; //Get rand input

        tempPage.options.push_back(tempOption); //Push option into the page options vector
    }

    //Push temp page into page vector and update data
    (*_pages).push_back(tempPage);
    *_pageCount += 1;

    //Update directory data
    wipeFile(1);
    writeFile(1, _pages, _pageCount);

    cout << "<Added Page>" << endl;
    return;
}

//This function is used to modify a specific page
void modPage(vector<Page>* _pages, int* _pageCount, int _pos)
{
    int inputInt = 0; //For player int input
    string inputStr = ""; //For player string input
    Option tempOption; //This is a temporary option
    int savedPos = 0; //This retains what option the user wants to edit

    displayPage((*_pages)[_pos]); //Display specific page

    getAnswer(1, 4 + (*_pages)[_pos].optionCount, &inputInt); //call input function
    cin.ignore(); //Clears up cin to be able to use getline (unreliable)

    //add option to modify certain elements
    cout << " >- Specify which element you want to edit" << endl;
    cout << " [1] Edit Title" << endl;
    cout << " [2] Edit Text" << endl;
    cout << " [3] Add Option" << endl;
    for(int i = 0; i < (*_pages)[_pos].optionCount; i++)
    {
        cout << " [" << 3 + i << "] Edit Option " << 3 + i << endl;
    }
    cout << " [" << 4 + (*_pages)[_pos].optionCount, &inputInt) << "] To Exit" << endl;

    //Process input from player
    if(inputInt == 1) //If requrest edit title
    {
        cout << " >- Input New Titile" << endl;
        getline(cin, inputStr); //get input
        (*_pages)[_pos].title = inputStr; //assign to variable

    }
    else if(inputInt == 2) //If request edit text
    {
        cout << " >- Input New Text" << endl;
        getline(cin, inputStr); //get input
        (*_pages)[_pos].text = inputStr; //assign to variable
    }
    else if(inputInt == 3) //If request to add option
    {
        cout << " >- Enter Option Text" << endl;
        getline(cin, inputStr);
        tempOption.text = inputStr; //Get text input

        cout << " >- Enter Option Link" << endl;
        getline(cin, inputStr);
        tempOption.link = inputStr; //Get link input

        cout << " >- Enter Option Rand" << endl;
        getline(cin, inputStr);
        tempOption.rand = inputStr; //Get rand input

        (*_pages)[_pos].options.push_back(tempOption); //Push option into the page options vector
    }
    else if(inputInt != 4 + (*_pages)[_pos].optionCount, &inputInt))
    {
        savedPos = inputInt;//Save chosen option to edit

        cout << endl << " >- Specify which element you want to edit" << endl;
        cout << " [1] Edit Option Text" << endl;
        cout << " [2] Edit Option Link" << endl;
        cout << " [3] Edit Option Rand" << endl;
        if((*_pages)[_pos].optionCount > 1) cout << " [4] Delete Option" << endl; //if there is more than 1 option, allow option to delete

        getAnswer(1, 4, &inputInt); //call input function

        if(inputInt == 1)
        {
            getline(cin, inputStr);
            (*_pages)[_pos].options[savedPos - 4].text = inputStr; //Get text input
        }
        if(inputInt == 2)
        {
            getline(cin, inputStr);
            (*_pages)[_pos].options[savedPos - 4].link = inputStr; //Get link input
        }
        if(inputInt == 3)
        {
            getline(cin, inputStr);
            (*_pages)[_pos].options[savedPos - 4].rand = inputStr; //Get rand input
        }
        if(inputInt == 4 && (*_pages)[_pos].optionCount > 1)
        {
            (*_pages)[_pos].optionCount -= 1; //Edit data
            (*_pages)[_pos].options.erase(myvector.begin() savedPos - 4); //delete page
        }
    }
    //Update directory data
    wipeFile(1);
    writeFile(1, _pages, _pageCount);
    return;
}

//This function is used to delete a specific page
void deletePage(vector<Page>* _pages, int* _pageCount, int _pos)
{
    (*_pages).erase((*_pages).begin(), _pos); //delete certain spot in the vector

    //Update directory data
    wipeFile(1);
    writeFile(1, _pages, _pageCount);
    return;
}
