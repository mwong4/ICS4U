/*
Author: Max Wong
Date Created: Feb 17, 2020

Question 2

board[y][x];

testCases
3 3 2 R 1 C 1
= 4
4 5 7 R 3 C 1 C 2 R 2 R 2 C 1 R 4
=10
*/

#include <iostream>

using namespace std;

int main()
{
    int mVal;
    int nVal;
    int kVal;
    string inputS;
    int inputI;
    int total = 0;
    bool tempBool;

    //Get input, define array
    cin >> mVal >> nVal >> kVal;
    int board [mVal][nVal] = {};

    //Do calculations
    for(int i = 0; i < kVal; i++)
    {
        cin >> inputS >> inputI;
        if(inputS == "R")
        {
            for(int j = 0; j < nVal; j++)
            {
                if(board[inputI-1][j])
                {
                    board[inputI-1][j] = false;
                    total--;
                }
                else
                {
                    board[inputI-1][j] = true;
                    total++;
                }
            }
        }
        else
        {
            for(int j = 0; j < mVal; j++)
            {
                if(board[j][inputI-1])
                {
                    board[j][inputI-1] = false;
                    total--;
                }
                else
                {
                    board[j][inputI-1] = true;
                    total++;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}
