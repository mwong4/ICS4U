#include <iostream>

using namespace std;

struct Hi
{
    int *ptrInt;
};

int main()
{
    int value = 5;
    Hi myHi;

    Hi *ptrHi = &myHi;

    (*ptrHi).ptrInt = &value;

    cout << *((*ptrHi).ptrInt) << endl;

    cout << "Hello world!" << endl;
    return 0;
}
