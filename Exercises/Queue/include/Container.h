/*
Author: Max Wong
Date Created: Mar 8, 2020
Date Updated: Mar 8, 2020
Purpose: Container class header file
Type: Header
*/

#ifndef CONTAINER_H
#define CONTAINER_H

using namespace std;

class Container
{
    public:
        Container();
        Container(int, Container*); //custom constructor
        virtual ~Container();

        void display(); //Display function for container

        //geters/seters
        int getContent();
        Container* getNext();
        void setContent(int);
        void setNext(Container*);


    protected:

    private:
        int content;
        Container *ptr_next;
};

#endif // CONTAINER_H
