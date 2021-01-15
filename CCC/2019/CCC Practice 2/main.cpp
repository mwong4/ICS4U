/*
>- Author: Max Wong
>- Date: Jan 13, 2020
>- Purpose: Practice for CCC Competition
*/

#include <iostream>
#include <tgmath.h>

using namespace std;

//Function that determines if the number is prime or not
bool determineIfPrime(int inputNumber)
{
    int limit = ceil(sqrt(inputNumber)) + 1;

    //Run through all numbers up to and excluding 1 and the input number
    for(int i = 2; i < limit; i++)
    {
        //If the division is clean (no remainder), number is not prime
        if(inputNumber % i == 0)
        {
            //In the case the number is not prime, return false
            return false;
        }
    }
    //Otherwise, the number passes the test and is prime
    return true;
}

int closestPrime(int _num)
{
    bool tempBool = determineIfPrime(_num);
    //cout << "closestPrime" << endl;
    while(!tempBool)
    {
        _num -= 1;
        tempBool = determineIfPrime(_num);
    }

    return _num;
}

int main()
{
    int runSize = 0;
    int counter = 0;
    int input;
    int output1 = 0;
    int output2 = 0;
    int retain;

    cin >> runSize;
    counter = runSize;

    while(counter > 0)
    {
        cin >> input;

        //process data
        retain = input;

        do
        {

            output1 = closestPrime(retain);
            retain = output1;
            output2 = input*2 - output1;

            retain  --;
        }
        while(!determineIfPrime(output2));


        cout << output1 << " " << output2 << endl;

        counter --;
        retain = 0;
    }
    return 0;
}
