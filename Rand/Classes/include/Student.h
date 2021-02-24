/*
Example header file from class
Date Created: Feb 24, 2021
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;


class Student
{
    public:
        Student();    //constructor
        Student(string, int);
        virtual ~Student();

        void attendClass();
        void doHomework();

        string getName();
        void setName(string);

        int getAge();
        void setAge(int);

    protected:

    private:
        int age;
        string name;
};

#endif // STUDENT_H
