#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> myDictionary;

    myDictionary["Red"] = 1;
    myDictionary["Blue"] = 2;
    myDictionary["Green"] = 3;


    cout << "Red " << myDictionary["Red"] << endl;
    return 0;
}
