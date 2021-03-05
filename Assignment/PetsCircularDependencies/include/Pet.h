/*
Author: Max Wong
Date Created: Feb 26, 2020
Date Updated: Feb 26, 2020
Purpose: Header file for pet class
Type: Header
*/

#ifndef PET_H
#define PET_H
#include <iostream> //For strings

using namespace std;

class Owner; //Empty class owner

class Pet
{
    public:
        Pet();
        Pet(string, string, int, Owner*, Owner*, Owner*); //Cusom constructor
        virtual ~Pet();

        //General Methods
        void displayPet(); //For displaying pet data

        //getters and setters
        string getName();

    protected:

    private:
        string name; //Name of pet
        string type; //Type of animal
        int age; //Pet age
        Owner *owners[3]; //All owners
};

#endif // PET_H
