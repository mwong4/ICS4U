#include <iostream>
#include "test.h"

#include <windows.h>

using namespace std;

void print(int);

int main()
{

    HANDLE hstdin;
    DWORD mode;

    hstdin = GetStdHandle( STD_INPUT_HANDLE );
    GetConsoleMode( hstdin, &mode );
    SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT );

    cout << "Press any key..." << flush;
    int ch = cin.get();

    cout << ch << endl;

    SetConsoleMode(hstdin, mode);

    /*
    for(int i = 0; i < 225; i++)
    {
        print(i);
    }
    */

    cout << "Hello world!" << endl;
    return 0;
}

void print(int _input)
{
    char temp = _input;
    cout << _input << ". " << temp << endl;
}
