/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 9, 2020
Purpose: Header for Linked List class
Type: Header
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
        bool search(const Node*) const; //Returns if node is in list
        int index(int) const; //Returns value of nth position
        int findIndex(int) const; //Finds the nth position of the first occurance of a given value
        void insertFront(Node*); //Inserts node to front of list
        void insert(Node*, Node*); //Inserts a node after a given node
        void insertOn(const int, const int); //Inserts a value after the first occurance of a certain value
        void insertAt(const int, const int); //Inserts a value at the nth index
        int remove(Node*); //Removes specific node and returns value
        int removeSpot(int); //Removes the specific nth spot
        int removeOccurance(int); //Removes the first occurance of a value
        void clear(); //Resets whole list
        Node* findNode (int) const; //Returns node pointer at nth term


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
