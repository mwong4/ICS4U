/*
Author: Max Wong
Date: Feb 6, 2020
Time Taken:
45 min (3/15)
1hr 25 min (6/15)

Testcases
8 2 5 2 0 1 0 2 2 3 4 3 6 1 1 5 7 3
= 3
8 5 0 6 4 3 7 0 1 0 2 2 3 4 3 6 1 1 5 7 3
= 7
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
    int pResSize = 0;
    vector <int> connectionLeft;
    vector <int> connectionRight;
    int path[2];
    bool start = true;
    int smallestSize;
    int smallestTarget;
    int totalDistance = 0;
    int current;

    //Get input
    cin >> nVal >> mVal;
    for(int i = 0; i < mVal; i++)
    {
        cin >> input;
        pRes.push_back(input);
        pResSize ++;
    }
    std:sort (pRes.begin(), pRes.begin() + pResSize); //Sort
    for(int j = 0; j < nVal-1; j++)
    {
        cin >> input;
        connectionLeft.push_back(input);
        cin >> input;
        connectionRight.push_back(input);
    }

    while(pResSize > 0)
    {
        smallestSize = 100;
        smallestTarget = 100;

        if(start) //At start
        {
            start = false;
            resetPath(path, pRes[pResSize - 1]);
            current = pRes[pResSize - 1];
            pRes.erase(pRes.begin()+pResSize-1);
            pResSize --;
        }
        for(int i = 0; i < pResSize; i++)
        {
            //Calculation - call function here
            findTarget(pRes[i], current, path, connectionLeft, connectionRight, nVal, current);
            //cout << "size: " << path[1]-1 << endl;
            if(path[1] - 1 < smallestSize)
            {
                smallestSize = path[1] - 1;
                smallestTarget = i;
            }
            resetPath(path, current);
        }
        //cout << "smallest: " << smallestSize << endl;
        totalDistance += smallestSize;
        pResSize --;
        current = pRes[smallestTarget];
        pRes.erase(pRes.begin()+smallestTarget);
    }
    cout << totalDistance << endl;
    return 0;
}
