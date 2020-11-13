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

#include <iostream>
#include <vector>

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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
