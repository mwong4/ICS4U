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
    Owner *ownerOne = new Owner("Emily", nullptr);
    Owner *ownerTwo = new Owner("Jetta", nullptr);
    Owner *ownerThree = new Owner("Horace", nullptr);

    Pet *myPet = new Pet("Clifford", "The Killer Dog", 42, ownerOne, ownerTwo, ownerThree);

    //Set pets to all owners
    (*ownerOne).setPet(myPet);
    (*ownerTwo).setPet(myPet);
    (*ownerThree).setPet(myPet);

    (*myPet).displayPet(); //Call method in pets to display itself

    return 0;
}
