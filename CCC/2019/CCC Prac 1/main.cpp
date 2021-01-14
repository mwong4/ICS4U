/*
>- Author: Max Wong
>- Date: Jan 12, 2020
>- Purpose: Practice for CCC Competition
*/

#include <iostream>

using namespace std;

/*
0 1
2 3
*/

void vertFlip(int _pos[])
{
    int storeVal;
    //Swap top
    storeVal = _pos[1];
    _pos[1] = _pos[0];
    _pos[0] = storeVal;
    //Swap bottom
    storeVal = _pos[3];
    _pos[3] = _pos[2];
    _pos[2] = storeVal;
    return;
}

void horiFlip(int _pos[])
{
    int storeVal;
    //Swap left
    storeVal = _pos[2];
    _pos[2] = _pos[0];
    _pos[0] = storeVal;
    //Swap right
    storeVal = _pos[3];
    _pos[3] = _pos[1];
    _pos[1] = storeVal;
    return;
}

int main()
{
    string input;

    string tempString;
    int hFlip = 0;
    int vFlip = 0;
    int pos[4] = {1, 2, 3, 4};

    input = "";
    cin >> input;

    //Break up input
    for(int i = (input.size() - 1); i >= 0; i --)
    {
        //get character at the back
        tempString = input.at(i);

        if(tempString == "H")
        {
            hFlip ++;
        }
        else if(tempString == "V")
        {
            vFlip ++;
        }
    }

    if(hFlip % 2 == 1)
    {
        horiFlip(pos);
    }

    if(vFlip % 2 == 1)
    {
        vertFlip(pos);
    }

    //output
    cout << pos[0] << " " << pos[1] << endl;
    cout << pos[2] << " " << pos[3] << endl;

    return 0;
}
