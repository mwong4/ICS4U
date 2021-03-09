/*
Author: Max Wong
Date Created: Mar 8, 2020
Date Updated: Mar 8, 2020
Purpose: To implement queue
Type: Main
*/

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue myQueue; //Initializing queue

    //Popping from an empty queue
    cout << myQueue.pop() << endl;
    myQueue.displayQueue();

    //Peeking from an empty queue
    cout << myQueue.peek() << endl;
    myQueue.displayQueue();

    //Pushing to an empty queue
    myQueue.push(1);
    myQueue.displayQueue();

    //Popping from a queue containing exactly one element
    cout << myQueue.pop() << endl;
    myQueue.displayQueue();

    //Pushing to a queue containing exactly one element
    myQueue.push(4);
    myQueue.push(5);
    myQueue.displayQueue();

    //Pushing to a queue containing multiple elements
    myQueue.push(6);
    myQueue.push(7);
    myQueue.displayQueue();

    //Popping from a queue containing multiple elements
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;
    myQueue.displayQueue();

    //peeking from a queue containing multiple elements
    cout << myQueue.peek() << endl;
    myQueue.displayQueue();

    //popping from an empty queue that was previously non-empty
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;
    myQueue.displayQueue();

    //peeking from an empty queue that was previously non-empty
    myQueue.push(8);
    cout << myQueue.pop() << endl;
    cout << myQueue.peek() << endl;
    myQueue.displayQueue();

    //pushing to an empty queue that was previously non-empty
    myQueue.push(9);
    cout << myQueue.pop() << endl;
    myQueue.push(10);
    myQueue.displayQueue();

    cout << "end program" << endl;

    return 0;
}
