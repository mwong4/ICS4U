/*
Author: Max Wong
Date Created: Feb 1 , 2020
Time Taken: 16 min (15/15)

Note: Study sort
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int question;
    int nVal;
    vector<int> dLand;
    vector<int> pLand;

    int tempInt;
    int output = 0;

    //get input
    cin >> question >> nVal;
    for(int i = 0; i < nVal; i++)
    {
        cin >> tempInt;
        dLand.push_back(tempInt);
    }
    for(int i = 0; i < nVal; i++)
    {
        cin >> tempInt;
        pLand.push_back(tempInt);
    }

    //Sort vectors
    std::sort (dLand.begin(), dLand.begin()+nVal);
    std::sort (pLand.begin(), pLand.begin()+nVal);

    //Calculate answer
    if(question == 1) //For min
    {
        for(int i = 0; i < nVal; i++)
        {
            if(dLand[i] >= pLand[i])
            {
                output += dLand[i];
            }
            else
            {
                output += pLand[i];
            }
        }
    }
    else //For max
    {
        for(int i = 0; i < nVal; i++)
        {
            if(dLand[i] >= pLand[nVal-i-1])
            {
                output += dLand[i];
            }
            else
            {
                output += pLand[nVal-i-1];
            }
        }
    }

    //Output
    cout << output << endl;
    return 0;
}
