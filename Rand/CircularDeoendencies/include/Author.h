#ifndef AUTHOR_H
#define AUTHOR_H
#include <iostream>

using namespace std;

class Book;

class Author
{
    public:
        Author();
        virtual ~Author();

        string name;
        Book *book;

    protected:

    private:
};

#endif // AUTHOR_H
