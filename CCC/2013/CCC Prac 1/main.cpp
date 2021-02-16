/*
Author: Max Wong
Date Created: Feb 15, 2020
Time Take: 50min (15/15)
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    float input;
    vector<int> digits;
    int digitSize = 0;
    float output;
    bool isUnique = false;
    bool isTop = true;

    //Input
    cin >> input;

    //Calculations
    do
    {
        input += 1;
        output = input;

        digits.clear();
        isTop = true;
        digitSize = 0;
        //Break apart number
        for(float i = 10000; i >= 1; i = i / 10)
        {
            if(floor(output/i) == 0 && isTop);
            else
            {
                isTop = false;
                digits.push_back(floor(output/i));
                digitSize ++;
                output -= floor(output/i)*i;
            }
        }

        //Check to see if correct
        isUnique = true;
        for(int i = 0; i < digitSize; i++)
        {
            for(int j = i+1; j < digitSize; j++)
            {
                if(digits[i] == digits[j])
                {
                    isUnique = false;
                    i = 10;
                    j = 10;
                }
            }
        }
    }
    while(!isUnique);

    //Output answer
    cout << input << endl;


    return 0;
}
