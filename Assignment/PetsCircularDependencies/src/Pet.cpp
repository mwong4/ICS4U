/*
Author: Max Wong
Date Created: Feb 26, 2020
Date Updated: Feb 26, 2020
Purpose: Source file for pet class
Type: Source
*/

#include "Pet.h"
#include "Owner.h" //Include owners class

Pet::Pet()
{
    //ctor
    name = "Unknown"; //Set misc values
    type = "Unknown";
    age = 0;

    for(int i = 0; i < 10; i++) //Set all pointers by default to null
    {
        owners[i] = nullptr;
    }
}

//Cusom constructor
Pet::Pet(string _name, string _type, int _age, Owner *_ownerOne, Owner *_ownerTwo, Owner *_ownerThree)
{
    name = _name; //Set misc values
    type = _type;
    age = _age;

    for(int i = 0; i < 3; i++) //Set all owners and empty spots to nullptr
    {
        owners[i] = nullptr;
    }
    owners[0] = _ownerOne;
    owners[1] = _ownerTwo;
    owners[2] = _ownerThree;

    return;
}

Pet::~Pet()
{
    //dtor
}

//For displaying pet data
void Pet::displayPet()
{
    int counter = 0; //Counter for going through array of owners

    cout << name << " - " << type << ", " << age << " Months Old" << endl; //Print out general information
    while(owners[counter] != nullptr) //Print out all owners found
    {
        (*owners[counter]).displayOwner(); //Call method in owners to display itself
        counter++; //Increase counter
    }

    if(counter == 0) //If there are no owners
    {
        cout << "Sorry, no owners found" << endl;
    }

    return;
}

//getters and setters
string Pet::getName()
{
    return name;
}
