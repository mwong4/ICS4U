/*
>- Author: Max Wong
>- Date: Jan 27, 2020
>- Purpose: Practice for CCC Competition
>- Time on stage: 38 min

>- Reference: C++.com for vector sort
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int nVal;
    vector <int> input;
    int inputInt;

    int mid;
    int counter = 0;

    //Input
    cin >> nVal;
    if(nVal % 2 == 1)
    {
        mid = floor(nVal/2);
    }
    else
    {
        mid = floor(nVal/2) - 1;
    }
    for(int i = 0; i < nVal; i++)
    {
        cin >> inputInt;
        input.push_back(inputInt);
    }

    //Calculation
    std::sort (input.begin(), input.begin()+nVal);
    for(int i = 0; i < nVal; i+= 2)
    {
        cout << input[mid-counter] << " ";
        if(i+1 != nVal)
        {
            cout << input[mid+counter+1] << " ";
        }
        counter ++;
    }

    return 0;
}
