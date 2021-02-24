/*
Author: Max Wong
Date Created:Feb 23, 2021
Date Updated:Feb 23, 2021
Purpose: To track all books and their associated authors

Source
From ICS3U projects by Max Wong
*/
#include <iostream>

using namespace std;

struct Book;

//Struct containing person data
struct Person
{
    Book *booksWritten[4]; //Saves pointers of all books written, hard limitted to 4
    string name; //Saves name of person in string
};

//Struct containing book data
struct Book
{
    Person *author; //Saves author person as pointer
    string title; //Saves title in string
    string numOfPages; //Also saves size of book in a string
};

//Functions
void initialize(Book*, Person*, string, string); //For initializing books
void initialize(Person*, Book*, Book*, Book*, Book*, string); //For initializing people
void display(Person*); //For displaying author information
ostream& operator << (ostream&, Book*); //Overload function for displaying book

int main()
{
    //Make pointers to books and authors
    Person *authors[2] = {new Person, new Person};
    Book *books[4] = {new Book, new Book, new Book, new Book};

    //Call all initializations
    initialize(books[0], authors[0], "The Martian", "400p"); //Call fuctions to initialize books
    initialize(books[1], authors[0], "Artemis", "350p");
    initialize(books[2], authors[1], "Never Gonna Give You Up", "Never Gonna Let You Down");
    initialize(books[3], authors[0], "The Egg", "2p");
    initialize(authors[0], books[0], books[1], books[3], nullptr, "Andy Weir"); //Call functions to initialize authors
    initialize(authors[1], books[2], nullptr, nullptr, nullptr, "Max Wong");

    //Print out author information
    for(int i = 0; i < 2; i++)
    {
        display(authors[i]); //Call function for each author to display information
    }
    return 0;
}

//For initializing books
void initialize(Book* _book, Person* _person, string _name, string _pages)
{
    (*_book).author = _person; //Save author pointer
    (*_book).title = _name; //Save book title
    (*_book).numOfPages = _pages; //Save book size
    return;
}

//For initializing people
void initialize(Person* _person, Book *_bookOne, Book *_bookTwo, Book *_bookThree, Book *_bookFour, string _name)
{
    (*_person).name  = _name; //Save name
    (*_person).booksWritten[0] = _bookOne; //Go through array and save books
    (*_person).booksWritten[1] = _bookTwo;
    (*_person).booksWritten[2] = _bookThree;
    (*_person).booksWritten[3] = _bookFour;
     return;
}

//For displaying author information
void display(Person* _person)
{
    cout << _person -> name << endl; //Print out author

    for(int i = 0; i < 4; i++) //Go through all books
    {
        if((*_person).booksWritten[i] != nullptr) //If spot is not null, print out all information
        {
            cout << "-" << _person -> booksWritten[i] << endl;
        }
    }
    return;
}

//Used to display the fraction
ostream& operator << (ostream& _stream, Book *_book)
{
    _stream << (*_book).title << ", " << (*(*_book).author).name << ", " <<(*_book).numOfPages;
    return _stream;
}
