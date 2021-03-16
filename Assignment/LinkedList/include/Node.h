/*
Author: Max Wong
Date Created: Mar 9, 2020
Date Updated: Mar 10, 2020
Purpose: Header for Node class
Type: Header
*/

#ifndef NODE_H
#define NODE_H

using namespace std;


class Node
{
    public:
        Node();
        Node(Node*, Node*, const int); //Custom constructor
        virtual ~Node();

        void display() const; //Displays the content of the node

        //geters/seters
        Node* getNext() const;
        Node* getPrevious() const;
        int getContent() const;
        void setNext(Node*);
        void setPrevious(Node*);
        void setContent(int);

    protected:

    private:
        Node* ptr_next;
        Node* ptr_previous;
        int content;
};

#endif // NODE_H
