/*
Author: Max Wong
Date Created: Feb 7, 2020
Time Take: 23 min (15/15)

Cases
4 3 0 4 0
=0
10 1 3 5 4 0 0 7 0 0 6
=7

Note: pop_back doesnt work if there is only 1 element
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int kVal;
    int input;
    int inpSize = 1;
    vector <int> inputs;
    int total = 0;

    inputs.push_back(100);

    //get input
    cin >> kVal;
    for(int i = 0; i < kVal; i++)
    {
        cin >> input;
        if(input == 0) //Check for 0's while getting input
        {
            inputs.pop_back(); //pop twice
            inpSize --;
        }
        else
        {
            inputs.push_back(input);
            inpSize ++;
        }
    }

    //Total up
    for(int i = 1; i < inpSize; i++)
    {
        total += inputs[i];
    }

    cout << total << endl;
    return 0;
}
