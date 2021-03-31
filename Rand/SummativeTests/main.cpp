#include <iostream>
#include "test.h"

using namespace std;

int main()
{
    test a;
    test *b;
    test **c;

    b = &a;
    c = &b;

    cout << "Hello world!" << endl;
    return 0;
}
