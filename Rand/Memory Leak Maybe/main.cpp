/*
Author: Max Wong
Date Created: Mar 23, 2020
Date Updated: Mar 25, 2020
Purpose: memory leak?
Type: Main
*/

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack myStack;

    myStack.push('u');
    myStack.push('u');
    myStack.push('d');
    myStack.push('d');

    myStack.pop();
    myStack.pop();
    myStack.display();

    cout << "End Program" << endl;
    return 0;
}
