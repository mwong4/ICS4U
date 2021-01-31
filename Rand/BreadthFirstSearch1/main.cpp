/*
Author: Max Wong
Date Created: Jan 30, 2020
Date Updated: Jan 30, 2020
Purpose: To build a simple version of Breadth First Search


0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

grid[y][x]
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    const int gridSize = 5; //Size of the map and operations
    int grid[gridSize+2][gridSize+2]; //The actual map

    int currentX = 1; //Current coordinates
    int currentY = 1;
    int savedDirection = 0; //0 = null, 1 up, 2 down, 3 right, 4 left

    //stats
    int stepsTaken = 0;
    int turnsTaken = 0;

    //Set exterior walls
    for(int i = 0; i < gridSize + 2; i++)
    {
        grid[i][0] = 1000;
        grid[i][gridSize+1] = 1000;
    }
    for(int i = 0; i < gridSize + 2; i++)
    {
        grid[0][i] = 1000;
        grid[gridSize+1][i] = 1000;
    }

    //Get input
    cout << "Input 5x5 grid, -1 for end, 1000 for baricade" << endl;
    for(int i = 1; i < gridSize+1; i++)
    {
        for(int j = 1; j < gridSize+1; j++)
        {
            cin >> grid[i][j];
        }
    }


    while(grid[currentX][currentY] != -1)
    {
        //recommend not turning
        if(savedDirection == 1 || savedDirection == 2)
        {
            grid[currentY][currentX - 1] ++;
            grid[currentY][currentX + 1] ++;
        }
        else if(savedDirection == 3 || savedDirection == 4)
        {
            grid[currentY - 1][currentX] ++;
            grid[currentY + 1][currentX] ++;
        }

        //Decide on path
        if(


    }


    //Output grid
    for(int i = 0; i < gridSize+2; i++)
    {
        for(int j = 0; j < gridSize+2; j++)
        {
            if(grid[i][j] >= 1000)
            {
                cout << "X ";
            }
            else
            {
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
