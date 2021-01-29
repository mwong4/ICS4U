/*
>- Author: Max Wong
>- Date: Jan 28, 2020
>- Purpose: Practice for CCC Competition
>- Time on stage: 45 min

Problems
-Dont know an accurate way of calculating max length
-Dont know a way to calculate height combos

Solution: Try using sort and vector manipulation

*/

#include <iostream>
#include <vector>

using namespace std;

int oneCalc(int _size)
{
    int total = 0;

    while(_size > 0)
    {
        total += _size;
        _size --;
    }
    return total;
}

int main()
{
    int nVal;
    int input;
    int sum = 0;
    int outputLength = 0;
    int outputHeights = 0;
    vector <int> planks;
    int factorSize = 0;
    vector <int> factors;

    //Input
    cin >> nVal;
    for(int i = 0; i < nVal; i++)
    {
        cin >> input;
        sum += input;
        planks.push_back(input);
    }

    //Calculate length
    for(int i = 0; i < nVal; i++)
    {
        if(sum % planks[i] == 0)
        {
            outputLength ++;
            if(planks[i] != 1)
            {
                factors.push_back(planks[i]);
                factorSize ++;
            }
        }
    }

    //Calculate different heigh...
    if(outputLength == 0 || outputLength == 1)
    {
        outputLength = 1;

        outputHeights = oneCalc(nVal - 1);
    }
    else
    {
        for(int i = 0; i < factorSize; i++)
        {

        }
    }

    cout << outputLength << " " << outputHeights << endl;


    return 0;
}
