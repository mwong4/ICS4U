#ifndef WALL_H
#define WALL_H
#include "Interactable.h"


class Wall : public Interactable
{
    public:
        Wall();
        Wall(int, int); //Custom constructor
        virtual ~Wall();

        bool checkSolid(); //Returns if solid or not

    protected:

    private:
};

#endif // WALL_H
