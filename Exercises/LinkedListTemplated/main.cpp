/*
Author: Max Wong
Date Created: Mar 11, 2020
Date Updated: Mar 11, 2020
Purpose: To implement a Linked List using templates
Type: Main

////TODO////
-Templating
*/

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main()
{
    Node <int>newNode();

    newNode.getContent<int>();
    //newNode.display();

    cout << "End Program" << endl;
    return 0;
}
