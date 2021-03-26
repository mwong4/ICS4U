#ifndef SPACE_H
#define SPACE_H
#include "Interactable.h" //Include parent class


class Space : public Interactable
{
    public:
        Space();
        Space(int, int); //Custom constructor
        virtual ~Space();

        bool checkSolid(); //Returns if solid or not

    protected:

    private:
};

#endif // SPACE_H
