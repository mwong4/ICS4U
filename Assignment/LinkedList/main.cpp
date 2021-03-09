/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 9, 2020
Purpose: To implement a basic double Linked List
Type: Main
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList myList;
    myList.insertAt(4, 0);
    myList.insertAt(2, 0);
    myList.insertAt(1, 0);
    myList.insertAt(3, 1);
    myList.insertOn(5, 5);
    myList.insertOn(6, 4);

    myList.display();

    cout << "End Program" << endl;
    return 0;
}
