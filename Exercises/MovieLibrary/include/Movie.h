/*
Author: Max Wong
Date Created: Feb 25, 2020
Date Updated: Feb 25, 2020
Purpose: Header for movies
Type: Header
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;

class Actor; //Declare empty Actor class

class Movie
{
    public:
        Movie();
        Movie(string, string, Actor*, Actor*, Actor*); //Custom constructor
        virtual ~Movie();

        void displayMovie(); //For displaying information on a movie
        void setActor(Actor*, int); //For setting a certain actor

    protected:

    private:
        string title; //Store movie name
        string releaseDate; //Date released
        Actor *actors[3]; //Stores all actors included in the movie
};

#endif // MOVIE_H
