#ifndef MAP_H
#define MAP_H
#include "Interactable.h" //include interchangable class

using namespace std;


class Map
{
    public:
        Map();
        Map(int, int, *Interactable[]); //Custom constructor
        virtual ~Map();

        //General Functions
        void printMap() const; //For printing out map
        void getInteractable(const int, const int) const; //To get the interactable on a certain spot

    protected:

    private:
        int width; //represents width of array
        int height; //represents height of array
        Interactable map[100]; //double array containing whole map

};

#endif // MAP_H
