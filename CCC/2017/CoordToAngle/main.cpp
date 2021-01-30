/*
Author: Max Wong
Date Created: Jan 30, 2020
Last Edit: Jan 30, 2020
Purpose: To convert coordinates to angles
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    const float pi = 3.141592653589; //Defining pi

    float xCoord1; //For the 2 coords
    float yCoord1;
    float xCoord2;
    float yCoord2;
    float angle = 0; //For the angle

    //Input
    cout << "Input origin/coordinate 1 (x,y): " << endl;
    cin >> xCoord1 >> yCoord1;
    cout << "Input coordinate 2 (x,y): " << endl;
    cin >> xCoord2 >> yCoord2;

    if(xCoord2 >= 0)
    {
        angle = ((atan(1.0*(yCoord2 - yCoord1)/xCoord2 - xCoord1))/pi)*180;
    }
    else if(yCoord2 >= 0)
    {
        angle = 180 + (atan(1.0*(yCoord2 - yCoord1)/xCoord2 - xCoord1)/pi)*180;
    }
    else
    {
        angle = 360 - ((atan(1.0*(yCoord2 - yCoord1)/xCoord2 - xCoord1))/pi)*180;
    }

    cout << "Angle: " << angle << endl;
    return 0;
}
