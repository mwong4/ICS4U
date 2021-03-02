/*
Author: Max Wong
Date Created: Feb 26, 2020
Date Updated: Feb 26, 2020
Purpose: Main file for pets assignment
Type: Main
*/

#include <iostream>
#include "Owner.h" //Include owner class
#include "Pet.h" //Include pet class

using namespace std;

int main()
{
    //Create and instantiate owners and pets
    Owner *owners[3] = {new Owner("Emily", nullptr), new Owner("Jetta", nullptr), new Owner("Horace", nullptr)};
    Pet *myPet = new Pet("Clifford", "The Killer Dog", 42, owners, 3);

    //Set pets to all owners
    for(int i = 0; i < 3; i++)
    {
        (*owners[i]).setPet(myPet);
    }

    (*myPet).displayPet(); //Call method in pets to display itself

    return 0;
}
