/*
Author: Max Wong
Date Created: Feb 14, 2020
Time Take: 33min (0/15)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //Variables
    int kVal;
    int mVal;
    int input;
    vector<int> rVals;

    int counter = 0;

    vector<int> friends;

    //Input
    cin >> kVal >> mVal;
    for(int i = 0; i < mVal; i++)
    {
        cin >> input;
        rVals.push_back(input);
    }

    for(int i = 0; i < kVal; i++)
    {
        friends.push_back(i+1);
    }

    //Calculations
    for(int i = 0; i < mVal; i++)
    {
        for(int j = 1; j < kVal+1; j++)
        {
            if(j % rVals[i] == 0)
            {
                friends[j-1] = 0;
            }
        }

        //Eliminate 0's
        counter = 0;
        while(counter < kVal)
        {
            cout << "here" << endl;
            if(friends[counter] == 0)
            {
                friends.erase(friends.begin()+counter);
                kVal --;
            }
            else
            {
                counter ++;
            }
        }
    }


    for(int i = 0; i < kVal; i++)
    {
        cout << friends[i] << endl;
    }

    return 0;
}
