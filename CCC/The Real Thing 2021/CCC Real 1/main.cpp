/*
Author: Max Wong
Date Created: Feb 17, 2020

Question 1
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nVal;
    int input;
    vector<int> heights;
    vector<int> widths;
    float output = 0;

    //get input
    cin >> nVal;
    for(int i = 0; i < nVal+1; i++)
    {
        cin >> input;
        heights.push_back(input);
    }
    for(int i = 0; i < nVal; i++)
    {
        cin >> input;
        widths.push_back(input);
    }

    //Calcultions
    for(int i = 0; i < nVal; i++)
    {
        if(heights[i] > heights[i+1])
        {
            output += ((((heights[i] - heights[i+1])*widths[i])*1.0)/2) + (heights[i+1]*widths[i]);
        }
        else if(heights[i] < heights[i+1])
        {
            output += ((((heights[i+1] - heights[i])*widths[i])*1.0)/2) + (heights[i]*widths[i]);
        }
        else
        {
            output += heights[i]*widths[i];
        }
    }

    cout << output << endl;
    return 0;
}
