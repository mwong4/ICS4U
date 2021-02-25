#ifndef ACTOR_H
#define ACTOR_H
#include "Movie.h" //Include movie class
#include <iostream>

using namespace std;

class Actor
{
    public:
        Actor();
        Actor(string, Movie*, Movie*, Movie*); //Custom constructor
        virtual ~Actor();

        void displayActor(); //For dislaying all information on actor
        string getName(); //Custom getter for name

    protected:

    private:
        string name; //Name of person
        Movie *movies[]; //List of all movies performed in
};

#endif // ACTOR_H
