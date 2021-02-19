/*
Author: Max Wong
Date Created: Feb 7, 2020
Time Take: 33+20min (2/15)

Cases
4 3 M S S L L 3 S 3 L 1
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int jVal;
    int aVal;
    vector <int> jerseys;
    int jerseysSize;
    vector <int> sizes;
    vector <int> number;
    int athleteSize;

    int intInput;
    char charInput;

    int output = 0;

    sizes.push_back(100);
    number.push_back(100);

    //get input
    cin >> jVal >> aVal;
    athleteSize = aVal;
    for(int i = 0; i < jVal; i++)
    {
        cin >> charInput;
        if(charInput == 'S') jerseys.push_back(1);
        else if(charInput == 'M') jerseys.push_back(2);
        else if(charInput == 'L') jerseys.push_back(3);
        //Room for optimization here
    }
    for(int j = 0; j < aVal; j++)
    {
        cin >> charInput;
        if(charInput == 'S') sizes.push_back(1);
        else if(charInput == 'M') sizes.push_back(2);
        else if(charInput == 'L') sizes.push_back(3);
        cin >> intInput;
        number.push_back(intInput);
    }

    //Process answer
    while(athleteSize > 0)
    {
        intInput = number[athleteSize];
        if(jerseys[intInput] >= sizes[athleteSize])
        {
            output ++;
            for(int i = athleteSize+1; i > 0; i--)
            {
                if(number[i] == intInput)
                {
                    number.erase(number.begin()+i);
                    sizes.erase(sizes.begin()+i);
                    athleteSize --;
                }
            }
        }
        else
        {
            number.pop_back();
            sizes.pop_back();
            athleteSize --;
        }
    }

    cout << output << endl;
    return 0;
}
