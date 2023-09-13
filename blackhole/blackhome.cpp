#include <iostream>
#include <windows.h>
using namespace std;
char objects[6][5] = {
    {'-', '#', '#', '-', '#'},
    {'#', '-', '-', '#', '-'},
    {'-', '#', '-', '-', '-'},
    {'#', '-', '#', '-', '#'},
    {'#', '-', '-', '-', '-'},
    {' ', ' ', ' ', ' ', ' '}};
bool gravity = false;
bool isBlackHole = true;
int counter = 1;
void displayWorld();
void timeTick(int);
void timeTickBlacHole(int);
void setGravityStatus(bool);
main()
{
    while (true)
    {
        displayWorld();
        Sleep(250);
        setGravityStatus(true);
        if (isBlackHole == true)
        {
            timeTickBlacHole(counter);
        }
        else
        {
            timeTick(counter);
        }
        displayWorld();
    }
}
void displayWorld()
{
    system("cls");
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << objects[row][col];
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void setGravityStatus(bool value)
{
    gravity = value;
}
void timeTickBlacHole(int times)
{
    int count = 0;
    if (gravity)
    {
        while (count < times)
        {
            for (int row = 3; row >= 0; row--)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (objects[row][col] == '#')
                    {
                        if (objects[row + 1][col] == '-')
                        {
                            objects[row + 1][col] = '#';
                            objects[row][col] = '-';
                        }
                    }
                }
            }
            for (int row = 4; row > 3; row--)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (objects[row][col] == '#')
                    {
                        if (objects[0][col] == '-')
                        {
                            objects[0][col] = '#';
                            objects[row][col] = '-';
                        }
                    }
                }
            }
            count = count + 1;
        }
    }
}
void timeTick(int times)
{
    int count = 0;
    if (gravity)
    {
        while (count < times)
        {
            for (int row = 3; row >= 0; row--)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (objects[row][col] == '#')
                    {
                        if (objects[row + 1][col] == '-')
                        {
                            objects[row + 1][col] = '#';
                            objects[row][col] = '-';
                        }
                    }
                }
            }
            count = count + 1;
        }
    }
}