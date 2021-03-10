/*
Author: Max Wong
Date Created: Mar 10, 2021
Date Edited: Mar 10, 2021
Purpose: To learn templating


*/

#include <iostream>

using namespace std;

template <typename Value>
Value input(Value& val)
{
    return val;
}

void display();

int main()
{
    display();

    cout << "Hello world!" << endl;
    return 0;
}

void display()
{
    int test1 = 1;
    string test2 = "woah";
    char test3 = 'c';

    cout << "hi" << endl;
    val(test1);
    return;
}
