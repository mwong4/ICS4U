#ifndef WIRE_H
#define WIRE_H

#include "Electronic.h" //include electronic class

using namespace std;

class Wire : public Electronic
{
    public:
        Wire();
        Wire(int, int, bool, Electronic*, int); //Custom constructor
        virtual ~Wire();

        bool checkSolid(); //Returns solidity status
        void toggle(); //Toggles power and other stuff

    protected:

    private:
};

#endif // WIRE_H
