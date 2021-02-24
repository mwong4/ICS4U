#include <iostream>
using namespace std;

struct Book;

struct Person
{
    Book *totalBooks[4];
    string name;
};

struct Book
{
    Person *author;
    string title;
    string numOfPages;
};

void initPerson(Person*, string);
void initBook(Person*, int, string, string);

int main()
{
    Person *person1 = {new Person};
    Person *person2 = {new Person};
    //Person *person1, *person2;
    Person *author = {new Person};
    Book *totalBooks[4] = {new Book, new Book, new Book, new Book};

    //Book *totalBooks[1] = {new Book};


    initPerson(person1, "Stephen King");
    initBook(person1, 0, "It", "1138 Pages");


    initPerson(person2, "H. P. Lovecraft");


    cout << "-" << person1->name << endl;
    cout << person1->totalBooks[0] << endl;
    cout << endl;

    cout << "-" << person2->name << endl;

    return 0;
}

void initPerson(Person *_person, string _name)
{
    _person->name = _name;

}

void initBook(Person *_person, int i, string _title, string _numOfPages)
{
    _person->totalBooks[i]->title = _title;
    _person->totalBooks[i]->numOfPages = _numOfPages;

}
