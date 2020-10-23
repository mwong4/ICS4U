#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    for(int i = 0; i < 100; i++)
    {
        cout << rand() % 2;
    }
    return 0;
}
