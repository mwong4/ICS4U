/*
Author: Max Wong
Date Created: Mar 10, 2021
Date Edited: Mar 10, 2021
Purpose: To learn templating

Sources:
https://www.youtube.com/watch?v=I-hZkUa9mIs
https://www.cplusplus.com/doc/oldtutorial/templates/
*/

#include <iostream>
#include "Test.h"

using namespace std;

//template <typename Variable> void display(Variable);

int main()
{
    /*
    display<float>(4);
    display<string>("hello");
    display<int>(4);
    display(4);
    */

    Test <string>myTest();

    cout << "Hello world!" << endl;
    return 0;
}

/*
template<typename Variable>
void display(Variable value)
{
    cout << value << endl;
    return;
}
*/



