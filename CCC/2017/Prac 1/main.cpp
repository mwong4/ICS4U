/*
>- Author: Max Wong
>- Date: Jan 27, 2020
>- Purpose: Practice for CCC Competition
>- Time on stage: 14 min
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nVal;
    vector <int> sOne;
    vector <int> sTwo;

    int totalOne = 0;
    int totalTwo = 0;
    int maxI = 0;

    int input;

    //Input
    cin >> nVal;
    for(int i = 0; i < nVal; i++)
    {
        cin >> input;
        sOne.push_back(input);
    }
    for(int i = 0; i < nVal; i++)
    {
        cin >> input;
        sTwo.push_back(input);
    }

    //Calculations
    for(int i = 0; i < nVal; i++)
    {
        totalOne += sOne[i];
        totalTwo += sTwo[i];

        if(totalOne == totalTwo)
        {
            maxI = i+1;
        }
    }

    cout << maxI << endl;
    return 0;
}
