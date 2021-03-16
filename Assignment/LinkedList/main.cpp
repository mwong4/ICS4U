/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 16, 2020
Purpose: To implement a basic double Linked List
Type: Main

////TODO////
Add to an empty list
Add to the front of a list containing one Node
Add to the back of a list containing one Node
Add to the front of a list containing multiple Nodes
Add to the back of a list containing multiple Nodes
Add to the interior of a list containing multiple Nodes
Remove from an empty list
Remove from the front of a list containing one Node
Remove from the end of a list containing one Node
Remove the front of a list containing multiple Nodes
Remove the back of a list containing multiple Nodes
Remove from the interior of list containing multiple Nodes
*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList myList; //initialize my list

    //Add to an empty list
    cout << endl << "//Add to an empty list" << endl;
    myList.insertAt(2, 0);
    myList.display();


    //Add to the front of a list containing one Node
    cout << endl << "//Add to the front of a list containing one Node" << endl;
    myList.insertAt(1, 0);
    myList.display();


    //Add to the back of a list containing one Node
    cout << endl << "//Add to the back of a list containing one Node" << endl;
    myList.removeSpot(0);
    myList.insertAt(3, 1);
    myList.display();


    //Add to the front of a list containing multiple Nodes
    cout << endl << "//Add to the front of a list containing multiple Nodes" << endl;
    myList.insertAt(1, 0);
    myList.insertAt(0, 0);
    myList.display();


    //Add to the back of a list containing multiple Nodes
    cout << endl << "//Add to the back of a list containing multiple Nodes" << endl;
    myList.insertAt(6, 100);
    myList.insertAt(7, 100);
    myList.display();


    //Add to the interior of a list containing multiple Nodes
    cout << endl << "//Add to the interior of a list containing multiple Nodes" << endl;
    myList.insertAt(4, 3);
    myList.insertAt(5, 4);
    myList.display();


    //Remove from an empty list
    cout << endl << "//Remove from an empty list" << endl;
    myList.clear();
    myList.removeSpot(0);
    myList.display();


    //Remove from the front of a list containing one Node
    cout << endl << "//Remove from the front of a list containing one Node" << endl;
    myList.insertAt(1, 0);
    myList.display();
    myList.removeSpot(0);
    myList.display();


    //Remove from the end of a list containing one Node
    cout << endl << "//Remove from the end of a list containing one Node" << endl;
    myList.insertAt(1, 0);
    myList.display();
    myList.removeSpot(100);
    myList.display();


    //Remove the front of a list containing multiple Nodes
    cout << endl << "//Remove the front of a list containing multiple Nodes" << endl;
    myList.insertAt(5, 0);
    myList.insertAt(4, 0);
    myList.insertAt(3, 0);
    myList.insertAt(3, 0);
    myList.insertAt(2, 0);
    myList.insertAt(1, 0);
    myList.display();
    myList.removeSpot(0);
    myList.display();


    //Remove the back of a list containing multiple Nodes
    cout << endl << "//Remove the back of a list containing multiple Nodes" << endl;
    myList.display();
    myList.removeSpot(100);
    myList.display();


    //Remove from the interior of list containing multiple Nodes
    cout << endl << "//Remove from the interior of list containing multiple Nodes" << endl;
    myList.display();
    myList.removeSpot(1);
    myList.display();


    cout << "//End Program" << endl;
    return 0;
}
