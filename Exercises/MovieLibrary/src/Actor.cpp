/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: Source code for actor class
Type: Source
*/

#include "Actor.h"

Actor::Actor()
{
    //ctor
    name = "unknown";
    for(int i = 0; i < 3; i++) //Setting all to null
    {
        movies[i] = nullptr;
    }
}

//Custom constructor
Actor::Actor(string _name, Movie *_movieOne, Movie *_movieTwo, Movie *_movieThree)
{
    name = _name;
    movies[0] = _movieOne;
    movies[1] = _movieTwo;
    movies[2] = _movieThree;
    return;
}

Actor::~Actor()
{
    //dtor
}

//For dislaying all information on actor
void Actor::displayActor()
{
    int counter = 0; //Counter for going through array of actors

    cout << ">- Actor: " << name << endl;
    while(movies[counter] != nullptr) //If actor spot is not empty, print it out
    {
        (*movies[counter]).displayMovie();
        counter ++;
    }
    return;
}

//Custom getter for name
string Actor::getName()
{
    return name;
}
