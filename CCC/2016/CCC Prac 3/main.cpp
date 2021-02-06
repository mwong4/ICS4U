/*
Author: Max Wong
Date: Feb 6, 2020
Time Taken:
45 min (3/15)

Testcase
8 2 5 2 0 1 0 2 2 3 4 3 6 1 1 5 7 3
= 3
*/

#include <iostream>
#include <vector>

using namespace std;

//Calculation - Recursive function
void findTarget(int _target, int _current, int _path[], vector <int> _left, vector <int> _right, int _nVal, int _prev)
{
    if(_path[1] != 0 || _current == _target) //If already found, return chain
    {
        _path[1] ++;
        return;
    }
    else
    {
        for(int i = 0; i < _nVal-1; i++)
        {
            if(_left[i] == _current && _right[i] != _prev)
            {
                findTarget(_target, _right[i], _path, _left, _right, _nVal, _current);
            }

            if(_path[1] != 0) //If already found, return chain
            {
                _path[1] ++;
                return;
            }

            if(_right[i] == _current && _left[i] != _prev)
            {
                findTarget(_target, _left[i], _path, _left, _right, _nVal, _current);
            }

            if(_path[1] != 0) //If already found, return chain
            {
                _path[1] ++;
                return;
            }
        }
    }
    return;
}

//Reset recursive func output
void resetPath(int _path[], int _home)
{
    _path[0] = _home;
    _path[1] = 0;
    return;
}

int main()
{
    int nVal;
    int mVal;
    int input;
    vector <int> pRes;
    vector <int> connectionLeft;
    vector <int> connectionRight;
    int path[2];

    //Get input
    cin >> nVal >> mVal;
    for(int i = 0; i < mVal; i++)
    {
        cin >> input;
        pRes.push_back(input);
    }
    for(int j = 0; j < nVal-1; j++)
    {
        cin >> input;
        connectionLeft.push_back(input);
        cin >> input;
        connectionRight.push_back(input);
    }
    resetPath(path, pRes[0]);

    //Calculation - call function here
    findTarget(pRes[1], pRes[0], path, connectionLeft, connectionRight, nVal, pRes[0]);

    cout << path[1]-1 << endl;
    return 0;
}
