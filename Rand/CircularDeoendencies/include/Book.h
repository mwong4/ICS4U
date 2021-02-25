#ifndef BOOK_H
#define BOOK_H
#include "Author.h"
#include <iostream>

using namespace std;

class Book
{
    public:
        Book();
        virtual ~Book();

        string title;
        Author author;

    protected:

    private:
};

#endif // BOOK_H
