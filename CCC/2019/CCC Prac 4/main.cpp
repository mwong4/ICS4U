#include <iostream>
#include <vector>
#include<tgmath.h>

using namespace std;

int main()
{
    int unitSize;
    int groupSize;
    int input;

    int largestScore = 0;
    int tempScore;
    int biggest;

    int counter = 0;

    vector<int> units;

    cin >> unitSize >> groupSize;

    for(int i = 0; i < unitSize; i++)
    {
        cin >> input;
        units.push_back(input);
    }

    for(int j = 0; j < ceil((unitSize*1.0)/groupSize); j++)
    {
        tempScore = 0;
        biggest = 0;

        //Score Calculation
        for(int i = 0; i < unitSize; i++)
        {
            if(units[i] > biggest)
            {
                biggest = units[i];
            }
            counter++;

            if((counter == groupSize && i != 0) || i + 1 == (unitSize % groupSize) + (groupSize*j))
            {
                //Reset
                tempScore += biggest;
                biggest = 0;
                counter = 0;
            }
        }

        if(tempScore > largestScore)
        {
            largestScore = tempScore;
        }
    }

    cout << largestScore;

    //cout << "f:" << frontScore << " b: " << backScore << endl;
    return 0;
}
