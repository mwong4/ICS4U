/*
Author: Max Wong
Date Created: Feb 15, 2020
Time Take: 18min (14/15)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int weightLimit;
    int carsNum;
    vector<int> cars;
    int input;
    bool canCross = true;
    int counter = -1;
    int firstFour = -1;

    //input
    cin >> weightLimit >> carsNum;
    for(int i = 0; i < carsNum; i++)
    {
        cin >> input;
        cars.push_back(input);
    }

    while(canCross)
    {
        firstFour ++;
        counter++;
        if(firstFour > 2)
        {
            if(cars[counter] + cars[counter-1] + cars[counter-2] + cars[counter-3] > weightLimit) canCross = false;
        }
        else if(firstFour == 0)
        {
            if(cars[0] > weightLimit) canCross = false;
        }
        else if(firstFour == 1)
        {
            if(cars[0] + cars[1] > weightLimit) canCross = false;
        }
        else if(firstFour == 2)
        {
            if(cars[0] + cars[1] + cars[3] > weightLimit) canCross = false;
        }
    }

    if(firstFour < 4)
    {
        cout << firstFour << endl;
    }
    else
    {
        cout << counter << endl;
    }
    return 0;
}
