#include <iostream>

using namespace std;

//Link structure
struct Link
{
     int content;
     Link *previous;
     Link *next;
};

void initialize(Link*, int, Link*, Link*); //For initializing the link
void display(Link*); //For display the data within the link

int main()
{
    Link links[3]; //Initializing the 3 links

    //Initializing all the links
    initialize(&links[0], 0, nullptr, &links[1]);
    initialize(&links[1], 1, &links[0], &links[2]);
    initialize(&links[2], 2, &links[1], nullptr);

    for(int i = 0; i < 3; i++)
    {
        display(&links[i]);
    }

    return 0;
}

//For initializing the link
void initialize(Link* _link, int _content, Link* _prev, Link* _next)
{
    (*_link).content = _content;
    (*_link).previous = _prev;
    (*_link).next = _next;
    return;
}

//For display the data within the link
void display(Link* _link)
{
    cout << "Content: " << (*_link).content;
    if((*_link).previous != nullptr)
    {
        cout << " Previous: " << _link -> previous -> content;
    }
    if((*_link).next != nullptr)
    {
        cout << " Next: " <<  _link -> next -> content;
    }
    cout << endl;
    return;
}
