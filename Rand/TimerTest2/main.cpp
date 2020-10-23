#include <iostream>
#include <windows.h> //For key detection
#include <time.h> //For clock
#include <tgmath.h>  //For rounding

using namespace std;

const int LIMIT = 7000; //The amount of time before timer runs out

int main()
{
    time_t timer = clock(); //Retains a time
    int interTime = 0; //To prevent repeating a print of time while between miliseconds

    cout << "<<start>>" << endl;
    cout << "[" << LIMIT/1000 << "]" << endl;//Print initial time

    while(clock() - timer < LIMIT) //Run through the timer phase untill timer runs out
    {
        if((clock() - timer) % 1000 == 0 && interTime != clock()) //if time has not been shown yet and rests on a second interval, print out
        {
            interTime = clock(); //This is to make sure that between miliseconds counted the number is not repeated
            cout << "[" << round((LIMIT - (clock() - timer))/1000) << "]" << endl;
        }

        if(GetKeyState(VK_UP) & 0x8000) //Check for input , if yes reset timer
        {
            cout << "<<reset>> + " << endl;
            cout << "[" << LIMIT/1000 << "]" << endl;//Print initial time
            timer = clock(); //Reset timer
            Sleep(200);
        }
    }

    cout << "<<sold>>" << endl;

    return 0;
}
