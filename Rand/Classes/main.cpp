/*
Example main for classes
Date Created: Feb 24, 2021
*/

#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student student1("Patrick", 17);

    cout << student1.getName() << " " << student1.getAge() << endl;

    cout << "Hello world!" << endl;
    return 0;
}
