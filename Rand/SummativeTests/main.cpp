#include <iostream>
#include "test.h"

using namespace std;

void print(int);

int main()
{
    for(int i = 0; i < 225; i++)
    {
        print(i);
    }

    cout << "Hello world!" << endl;
    return 0;
}

void print(int _input)
{
    char temp = _input;
    cout << _input << ". " << temp << endl;
}
