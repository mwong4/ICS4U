/*
Author: Max Wong
Date Created: Mar 24, 2020
Date Updated: Mar 24, 2020
Purpose: Header file for course class
Type: Header
*/

#ifndef COURSE_H
#define COURSE_H
#include <iostream>

#include "Teacher.h" //Include student and teacher classes
#include "Student.h"

using namespace std;

class Course
{
    public:
        Course();
        Course(string, string, Student*[], Teacher*); //custom constructor
        virtual ~Course();

        //main methods
        void assignTeacher(const Teacher*); //For assigning teacher
        void assignStudent(const Student*); //For assgining student
        void removeTeacher(const Teacher*); //For removing teacher
        void removeStudent(const Student*); //For removing student
        const void display(bool); //To display class

    protected:

    private:
        string courseCode;
        string courseName;
        Student* studentList[30]; //array of all students as pointers
        Teacher* instructor;
};

#endif // COURSE_H
