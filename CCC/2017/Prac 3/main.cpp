/*
>- Author: Max Wong
>- Date: Jan 28, 2020
>- Purpose: Practice for CCC Competition
>- Time on stage: 1hr 15min

Problems
-Dont know an accurate way of calculating max length
-Dont know a way to calculate height combos

Solution: Try using sort and vector manipulation

*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Output
{
    int maxLength = 0;
    int maxCombinations = 0;
};

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

Output multiCalc(vector<int> _planks, Output _output, int _limit)
{
    vector <int> combinations;
    int length;
    int counter;

    for(int i = 0; i < _limit)

    return _output;
}


int main()
{
    int nVal;
    vector <int> planks;
    int input;

    int cap;
    Output output;

    //Input
    cin >> nVal;
    for(int i = 0; i < nVal; i++)
    {
        cin >> input;
        planks.push_back(input);
    }


    //Calculate cap
    cap = ceil(nVal/2.0);
    while(nVal % cap != 0 && cap > 1)
    {
        cap --;
    }

    //Combination calculations
    for(int i = 2; i <= cap; i++)
    {
        if(nVal % i == 0)
        {
            //Call function
            for(int i = 2; i < cap; i++)
            {
                output = multiCalc(planks, output, i);
            }
        }

        if(i == cap)
        {
            output.maxLength = 1;
            output.maxCombinations = oneCalc(nVal);
        }
    }

    cout << output.maxLength << " " << output.maxCombinations << endl;


    return 0;
}
