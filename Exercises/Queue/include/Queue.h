/*
Author: Max Wong
Date Created: Mar 8, 2020
Date Updated: Mar 8, 2020
Purpose: Queue class header file
Type: Header
*/

#ifndef QUEUE_H
#define QUEUE_H
#include "Container.h" //For container class

using namespace std;

class Queue
{
    public:
        Queue();
        Queue(Container*, Container*); //Custom constructor
        virtual ~Queue();

        void push(int); //For pushing value to back
        int pop(); //For extracting and destroying value on front
        int peek(); //For reading value at front
        void displayQueue(); //For displaying whole queue
        void clear(); //For destroying whole queue

        //geters/seters
        Container *getFront();
        Container *getBack();
        void setFront(Container*);
        void setBack(Container*);

    protected:

    private:
        Container *ptr_front;
        Container *ptr_back;
};

#endif // QUEUE_H
