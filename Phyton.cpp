#include <iostream>

using namespace std;
bool buyar;
const int lebar = 20;
const int tinggi = 20;
int x, y, buahX, buahY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    buyar = false;
    dir = STOP;
    x = lebar / 2;
    y = tinggi / 2;
    buahX = rand() % lebar;
    buahY = rand() % tinggi;
    score = 0;
}
void Draw()
{
    system("cls");
    for (int i = 0; i < lebar+2; i++)
        cout << "#";
    cout << endl;
 
    for (int i = 0; i < tinggi; i++)
    {
        for (int j = 0; j < lebar; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == buahY && j == buahX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == lebar - 1)
                cout << "#";
        }
        cout << endl;
    }
 
    for (int i = 0; i < lebar+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            buyar = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= lebar) x = 0; else if (x < 0) x = lebar - 1;
    if (y >= tinggi) y = 0; else if (y < 0) y = tinggi - 1;
 
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            buyar = true;
 
    if (x == buahX && y == buahY)
    {
        score += 10;
        buahX = rand() % lebar;
        buahY = rand() % tinggi;
        nTail++;
    }
}
int main()
{
    Setup();
    while (!buyar)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
