/*
Author: Max Wong
Date Created: Mar 20, 2021
Date Updated: Mar 20, 2021
Purpose: Header file for Lines Class
Type: Header
*/


#ifndef LINES_H
#define LINES_H
#include <iostream>

using namespace std;

class Lines
{
    public:
        Lines();
        Lines(float, int); //Custom constructor
        virtual ~Lines();



    protected:

    private:
        float slope;
        int intercept;
};

#endif // LINES_H
