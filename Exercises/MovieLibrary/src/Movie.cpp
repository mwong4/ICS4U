/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: Source code for movies
Type: Source
*/

#include "Movie.h"
#include "Actor.h"

Movie::Movie()
{
    //ctor
    title = "empty";
    releaseDate = "unknown";
    for(int i = 0; i < 3; i++) //Setting all to null
    {
        actors[i] = nullptr;
    }
}

//Custom constructor
Movie::Movie(string _title, string _releaseDate, Actor *_actorOne, Actor *_actorTwo, Actor *_actorThree)
{
    //Set title, release date and actors
    title = _title;
    releaseDate = _releaseDate;
    actors[0] = _actorOne;
    actors[1] = _actorTwo;
    actors[2] = _actorThree;
    return;
}

Movie::~Movie()
{
    //dtor
}

//For displaying information on a movie
void Movie::displayMovie()
{
    int counter = 0; //Counter for going through array of actors

    cout << "-" << title << ", released " << releaseDate << ", Featuring: "; //Print out all information
    while(actors[counter] != nullptr) //If actor spot is not empty, print it out
    {
        cout << (*actors[counter]).getName() << ", ";
        counter++;
    }
    cout << endl;
    return;
}

//For setting a certain actor
void Movie::setActor(Actor* _actor, int _index)
{
    actors[_index-1] = _actor;
    return;
}
