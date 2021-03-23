/*
Author: Max Wong
Date Created: Mar 22, 2020
Date Updated: Mar 22, 2020
Purpose: To learn the basic concepts of polymorphism
Type: Main
*/

#include <iostream>
#include "Residential.h"
#include "Commercial.h"
#include "Building.h"

using namespace std;

int main()
{
    Residential house("42 Craig Henry Rd.", 1000, 3, 2); //Initializing buildings
    Commercial store("133 Greenbank Rd.", 20000, 1, true);

    Building *target = &house;//Initializing building pointer
    (*target).display(); //Display

    target = &store; //Retarget pointer
    (*target).display(); //Display

    cout << "End Program" << endl;
    return 0;
}
