/*
Author: Max Wong
Date Created: Mar 10, 2021
Date Edited: Mar 10, 2021
Purpose: Header file for test class
Type: Header
*/

#ifndef TEST_H
#define TEST_H

using namespace std;

template <class conType>
class Test
{
    public:
        Test();
        virtual ~Test();

        void displayContent();

    protected:

    private:
        conType content;
};

#endif // TEST_H
