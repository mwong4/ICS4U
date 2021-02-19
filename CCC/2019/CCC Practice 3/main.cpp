/*
>- Author: Max Wong
>- Date: Jan 14, 2020
>- Purpose: Practice for CCC Competition
*/

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h> //For converting string to array
#include <stdlib.h>

using namespace std;

bool checkLine(int _one, int _two, int _three)
{
    if(_one - _two == _two - _three)
    {
        return true;
    }
    return false;
}

int countLine(string _one, string _two, string _three)
{
    int xCount = 0;
    if(_one == "X")
    {
        xCount ++;
    }
    if(_two == "X")
    {
        xCount ++;
    }
    if(_three == "X")
    {
        xCount ++;
    }
    return xCount;
}

int main()
{
    /*
    00 01 02 03 04
    10 11 12 13 14
    20 21 22 23 24
    30 31 32 33 34
    40 41 42 43 44
    */
    string group[3][3];

    int xCount = 0;

    //input
    cin >> group[0][0];
    if(group[0][0] == "X") xCount ++;
    cin >> group[0][1];
    if(group[0][1] == "X") xCount ++;
    cin >> group[0][2];
    if(group[0][2] == "X") xCount ++;
    cin >> group[1][0];
    if(group[1][0] == "X") xCount ++;
    cin >> group[1][1];
    if(group[1][1] == "X") xCount ++;
    cin >> group[1][2];
    if(group[1][2] == "X") xCount ++;
    cin >> group[2][0];
    if(group[2][0] == "X") xCount ++;
    cin >> group[2][1];
    if(group[2][1] == "X") xCount ++;
    cin >> group[2][2];
    if(group[2][2] == "X") xCount ++;

    if(xCount == 9)
    {
        //For 9x
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                group[i][j] = "1";
            }
        }
    }


    while(xCount > 0)
    {
        if(xCount > 0)
        {
            for(int i = 0; i < 3; i++)
            {
                //For 1x button
                if(countLine(group[0][i], group[1][i], group[2][i]) == 1)
                {
                    if(group[0][i] == "X")
                    {
                        group[0][i] = std::stoi((group[1][i]).c_str()) - std::stoi((group[2][i]).c_str()) + std::stoi((group[1][i]).c_str());
                        xCount --;
                    }
                    if(group[1][i] == "X")
                    {
                        group[1][i] = (std::stoi((group[2][i]).c_str()) - std::stoi((group[0][i]).c_str()))/2 + std::stoi((group[0][i]).c_str());
                        xCount --;
                    }
                    if(group[2][i] == "X")
                    {
                        group[2][i] = std::stoi((group[1][i]).c_str()) - std::stoi((group[0][i]).c_str()) + std::stoi((group[1][i]).c_str());
                        xCount --;
                    }
                }
                if(countLine(group[i][0], group[i][1], group[i][2]) == 1)
                {
                    if(group[i][0] == "X")
                    {
                        group[i][0] = to_string(std::stoi((group[i][1]).c_str()) - std::stoi((group[i][2]).c_str()) + std::stoi((group[i][1]).c_str()));
                        xCount --;
                    }
                    if(group[i][1] == "X")
                    {
                        group[i][1] = to_string((std::stoi((group[i][2]).c_str()) - std::stoi((group[i][0]).c_str()))/2 + std::stoi((group[i][0]).c_str()));
                        xCount --;
                    }
                    if(group[i][2] == "X")
                    {
                        group[i][2] = to_string(std::stoi((group[i][1]).c_str()) - std::stoi((group[i][0]).c_str()) + std::stoi((group[i][1]).c_str()));
                        xCount --;
                    }
                }
            }
        }

        if(xCount > 1)
        {
            //For 2x spots
            for(int i = 0; i < 3; i++)
            {
                if(countLine(group[0][i], group[1][i], group[2][i]) == 2)
                {
                    if(group[0][i] == "X" && group[1][i] == "X")
                    {
                        xCount -= 2;
                    }
                    if(group[1][i] == "X" && group[2][i] == "X")
                    {
                        xCount -= 2;
                    }
                    if(group[0][i] == "X" && group[2][i] == "X")
                    {
                        xCount -= 2;
                    }
                }
                if(countLine(group[i][0], group[i][1], group[i][2]) == 2)
                {
                    if(group[i][0] == "X" && group[i][1] == "X")
                    {
                        xCount -= 2;
                    }
                    if(group[i][1] == "X" && group[i][2] == "X")
                    {
                        xCount -= 2;
                    }
                    if(group[i][0] == "X" && group[i][2] == "X")
                    {
                        xCount -= 2;
                    }
                }
            }
        }
    }

    //output
    cout << group[0][0] << " " << group[0][1] << " " << group[0][2] << endl;
    cout << group[1][0] << " " << group[1][1] << " " << group[1][2] << endl;
    cout << group[2][0] << " " << group[2][1] << " " << group[2][2] << endl;
    return 0;
}


