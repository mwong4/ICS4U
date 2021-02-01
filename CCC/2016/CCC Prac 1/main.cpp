/*
Author: Max Wong
Date: Jan 31, 2020
Time Taken: 38 min (10/15)

Note: Memorize comverting string to chars
*/

#include <iostream>
#include <vector>

using namespace std;

struct Letter
{
    char letter;
    int letterCount;
};

int isPresent(vector<Letter> _letters, int _size, char _character)
{
    for(int i = 0; i < _size; i++)
    {
        if(_character == _letters[i].letter)

        {
            return i;
        }
    }
    return 1000;
}

int main()
{
    string wordOne;
    string wordTwo;

    Letter tempLetter;
    vector<Letter> lettersOne;
    int sizeOne = 0;
    vector<Letter> lettersTwo;
    int sizeTwo = 0;

    bool isAnagram = true;
    int difference = 0;

    //Get input
    cin >> wordOne >> wordTwo;

    //breakdown first letter
    for(int i = (wordOne.size() - 1); i >= 0; i --)
    {
        if(isPresent(lettersOne, sizeOne, wordOne.at(i)) == 1000)
        {
            //add new letter
            tempLetter.letter = wordOne.at(i);
            tempLetter.letterCount = 1;
            lettersOne.push_back(tempLetter);
            sizeOne++;
        }
        else
        {
            //add to existing letter
            lettersOne[isPresent(lettersOne, sizeOne, wordOne.at(i))].letterCount ++;
        }
    }

    //Breakdown second letter
    for(int i = (wordTwo.size() - 1); i >= 0; i --)
    {
        if(isPresent(lettersTwo, sizeTwo, wordTwo.at(i)) == 1000)
        {
            //add new letter
            tempLetter.letter = wordTwo.at(i);
            tempLetter.letterCount = 1;
            lettersTwo.push_back(tempLetter);
            sizeTwo++;
        }
        else
        {
            //add to existing letter
            lettersTwo[isPresent(lettersTwo, sizeTwo, wordTwo.at(i))].letterCount ++;
        }
    }

    //Determine difference
    for(int i = 0; i < sizeOne; i++)
    {
        if(isPresent(lettersTwo, sizeTwo, lettersOne[i].letter) == 1000)
        {
            difference ++;
        }
        else
        {
            if(lettersOne[i].letterCount - lettersTwo[isPresent(lettersTwo, sizeTwo, lettersOne[i].letter)].letterCount < 0)
            {
                isAnagram = false;
            }
            else
            {
                difference += lettersOne[i].letterCount - lettersTwo[isPresent(lettersTwo, sizeTwo, lettersOne[i].letter)].letterCount;
            }
        }
    }

    if(difference != lettersTwo[isPresent(lettersTwo, sizeTwo, '*')].letterCount)
    {
        isAnagram = false;
    }

    //Output
    if(isAnagram)
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}
