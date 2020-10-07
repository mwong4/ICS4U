/*
Author: Max Wong
Date Created: October 1, 2020
Purpose: Just testing this in adaptation for my own systems

Following this tutorial for adaptation: https://stackoverflow.com/questions/28944972/how-to-use-a-timer-in-c-to-force-input-within-a-given-time/28947000
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;
condition_variable cv;

int value;

void read_value() {
    cin >> value;
    cv.notify_one();
}

int main()
{
    int timed = 0;

    cout << "Please enter the input: ";
    thread th(read_value);

    mutex mtx;
    unique_lock<mutex> lck(mtx);
    while (cv.wait_for(lck, chrono::seconds(1)) == cv_status::timeout)
    {
        timed ++;
        cout << "\nTime-Out: " << timed << " second:";
        cout << "\nPlease enter the input:";
    }
    cout << "You entered: " << value << '\n';

    th.join();

    return 0;
}
