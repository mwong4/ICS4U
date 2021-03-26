#ifndef INTERACTABLE_H
#define INTERACTABLE_H


class Interactable
{
    public:
        Interactable();
        Interactable(int); //Custom constructor
        virtual ~Interactable();

        //getters/setters
        char getSymbol() const;

    protected:

    private:
        char symbol; //symbol representing object
};

#endif // INTERACTABLE_H
