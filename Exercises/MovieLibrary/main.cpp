#include <iostream>
#include "Movie.h"
#include "Actor.h"

using namespace std;

int main()
{
    //Create data
    Movie *movies[3] = {new Movie("The Martian", "2015", nullptr, nullptr, nullptr), new Movie("The Bourne Identity", "2002", nullptr, nullptr, nullptr), new Movie("Tenet", "2020", nullptr, nullptr, nullptr)};
    Actor *actors[3] = {new Actor("Matt Damon", movies[0], movies[1], nullptr), new Actor("Michael Pena", movies[0], nullptr, nullptr), new Actor("Juhan Ulfsak", movies[2], nullptr, nullptr)};

    //Initilize movies more
    (*movies[0]).setActor(actors[0], 1);
    (*movies[0]).setActor(actors[1], 2);
    (*movies[1]).setActor(actors[0], 1);
    (*movies[2]).setActor(actors[2], 1);

    //Initialize data
    for(int i = 0; i < 3; i++)
    {
        (*actors[i]).displayActor();
    }

    return 0;
}
