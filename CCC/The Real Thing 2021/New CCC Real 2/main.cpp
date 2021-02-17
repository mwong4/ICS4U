/*
Author: Max Wong
Date Created: Feb 17, 2020

New Question 2

testCases
3 3 2 R 1 C 1
= 4
4 5 7 R 3 C 1 C 2 R 2 R 2 C 1 R 4
=10
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int mVal;
    int nVal;
    int kVal;

    string inputS;
    int inputI;
    vector<string> inputOne;
    vector<int> inputTwo;
    bool isRepeat;
    int newSize = 0;

    int rVals = 0;
    int cVals = 0;
    int total = 0;

    //Get input and remove duplicates
    cin >> mVal >> nVal >> kVal;
    for(int i = 0; i < kVal; i++)
    {
        isRepeat = false;
        cin >> inputS >> inputI;
        for(int j = 0; j < newSize && !isRepeat; j++)
        {
            if(inputS == inputOne[j] && inputI == inputTwo[j])
            {
                isRepeat = false;
                newSize --;

                if(inputS == "R") rVals --;
                else cVals --;

                inputOne.erase(inputOne.begin()+j);
                inputTwo.erase(inputTwo.begin()+j);
            }
        }

        if(!isRepeat)
        {
            inputOne.push_back(inputS);
            inputTwo.push_back(inputI);

            if(inputS == "R") rVals ++;
            else cVals ++;
        }
        newSize ++;
    }

    //Calculate total
    total = (cVals*nVal) + (rVals*mVal)-(2*cVals*rVals);

    //cout << (cVals*nVal) << " + " << (rVals*mVal) << " - " << (2*cVals*rVals) << " = " << total << endl;
    cout << total << endl;

    return 0;
}
