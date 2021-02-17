/*
Author: Max Wong
Date Created: Feb 17, 2020

Question 3
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int friendSize;
    int input;
    vector<int> pVals;
    vector<int> wVals;
    vector<int> dVals;
    int mid = 0;

    //input
    cin >> friendSize;
    for(int i = 0; i < friendSize; i++)
    {
        cin >> input;
        pVals.push_back(input);
        mid += input;
        cin >> input;
        wVals.push_back(input);
        cin >> input;
        dVals.push_back(input);
    }

    //Calculate good spot
    mid /= friendSize;

    //Calculate time factor


    cout << "Hello world!" << endl;
    return 0;
}
