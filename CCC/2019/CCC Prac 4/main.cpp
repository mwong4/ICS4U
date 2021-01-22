#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int unitSize;
    int groupSize;
    int input;

    int frontScore = 0;
    int backScore = 0;
    int biggest=0;

    int counter = 0;

    vector<int> units;

    cin >> unitSize >> groupSize;

    for(int i = 0; i < unitSize; i++)
    {
        cin >> input;
        units.push_back(input);
    }

    //Front calculation
    for(int i = 0; i < unitSize; i++)
    {
        if(units[i] > biggest)
        {
            biggest = units[i];
        }

        if(i % groupSize == 2 && i != 0)
        {
            //Reset
            frontScore += biggest;
            biggest = 0;
        }
    }
    if(unitSize % groupSize != 0) frontScore += biggest;

    //Back calculation
    if(unitSize % groupSize != 0)
    {
        biggest = 0;
        for(int i = unitSize - 1; i >= 0 ; i--)
        {
            if(units[i] > biggest)
            {
                biggest = units[i];
            }
            counter ++;

            if(counter == 3 && i != unitSize)
            {
                //Reset
                backScore += biggest;
                biggest = 0;
                counter = 0;
            }
        }
        backScore += biggest;

        if(frontScore > backScore)
        {
            cout << frontScore << endl;
        }
        else
        {
            cout << backScore << endl;
        }
    }
    else
    {
        cout << frontScore << endl;
    }

    //cout << "f:" << frontScore << " b: " << backScore << endl;
    return 0;
}
