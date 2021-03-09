/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 9, 2020
Purpose: Header for Linked List class
Type: Header

////TODO////
A remove function that removes a node from the list. This function may or may not return the value stored in that node.
A remove function that removes the nth node from the list.
A remove function that removes the first occurrence of a specified value from the list.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h" //Include node library

using namespace std;

class LinkedList
{
    public:
        LinkedList();
        LinkedList(Node*, Node*, const int); //Custom constructor
        virtual ~LinkedList();

        //All general functions
        void display() const; //display all the contents of the list
        bool search(Node*) const; //Returns if node is in list
        int index(int) const; //Returns value of nth position
        int findIndex(int) const; //Finds the nth position of the first occurance of a given value
        void insert(Node*, Node*); //Inserts a node after a given node
        void insert(int, int); //Inserts a value after the first occurance of a certain value
        int remove(Node*); //Removes specific node and returns value
        int removeSpot(int); //Removes the specific nth spot
        int removeOccurance(int); //Removes the first occurance of a value
        void clear(); //Resets whole list


        //geters/seters
        Node* getFront() const;
        Node* getBack() const;
        int getCount() const;
        void setFront(Node*);
        void setBack(Node*);
        void setCount(int);

    protected:

    private:
        Node* ptr_front;
        Node* ptr_back;
        int count;
};

#endif // LINKEDLIST_H
