#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    CConsoleLogger anotherConsole;
    anotherConsole.Create("Tis is the first console");
    anotherConsole.printf("Another Console?");

    return 0;
}
