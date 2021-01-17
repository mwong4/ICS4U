/*
>- Author: Max Wong
>- Date: Jan 17, 2020
>- Purpose: Practice for CCC Competition
>- Time on stage: 1 hour?
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

struct Sorting {
  bool operator() (int i,int j) { return (i<j);}
} sortObj;

int main()
{
    vector <float> villages;
    int vSize;
    float input;
    float smallest = 1000000000;
    float test;
    float output;

    //get all input
    cin >> vSize;
    for(int i = 0; i < vSize; i++)
    {
        cin >> input;
        villages.push_back(input);
    }

    //Sort
    std:sort(villages.begin(), villages.end(), sortObj);

    //Calculat smallest
    for(int i = 1; i < vSize-1; i++)
    {
        test = (villages[i]-villages[i-1])/2 + (villages[i+1]-villages[i])/2;
        if(test <= smallest)
        {
            smallest = test;
        }
    }

    cout << std::setprecision(1) << std::fixed << smallest;

    return 0;
}
