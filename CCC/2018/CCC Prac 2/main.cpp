/*
>- Author: Max Wong
>- Date: Jan 17, 2020
>- Purpose: Practice for CCC Competition
>- Time on stage: 1 hour 5 min
*/

#include <iostream>
#include <vector>

using namespace std;

    /*
    00 01 02 03 04
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34
    40 41 42 43 44
    */

int main()
{
    int dSize;
    cin >> dSize;
    int input;

    vector < vector <int> > data;

    //Input
    for(int i = 0; i < dSize; i++)
    {
        data.push_back(vector <int>());
        for(int j = 0; j < dSize; j++)
        {
            cin >> input;
            data[i].push_back(input);
        }
    }

    //Determine orientation
    if(data[0][1] >= data[0][0] && data[1][0] >= data[0][0])
    {
        //perfect
        for(int i = 0; i < dSize; i++)
        {
            for(int j = 0; j < dSize; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(data[0][dSize-2] >= data[0][dSize-1] && data[1][dSize-1] >= data[0][dSize-1])
    {
        //90 clockwise
        for(int i = dSize - 1; i >= 0; i--)
        {
            for(int j = 0; j < dSize; j++)
            {
                cout << data[j][i] << " ";
            }
            cout << endl;
        }
    }
    else if(data[dSize-1][dSize-2] >= data[dSize-1][dSize-1] && data[dSize-2][dSize-1] >= data[dSize-1][dSize-1])
    {
        //180 clockwise
        for(int i = dSize - 1; i >= 0; i--)
        {
            for(int j = dSize - 1; j >= 0; j--)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        //270 clockwise
        for(int i = 0; i < dSize; i++)
        {
            for(int j = dSize - 1; j >= 0; j--)
            {
                cout << data[j][i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
