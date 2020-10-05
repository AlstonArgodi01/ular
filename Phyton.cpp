#include <iostream>
#include <conio.h>

using namespace std;
bool buyar;
const int lebar = 20;
const int tinggi = 20;
int x, y, buahX, buahY, score;
int ekorX[100], ekorY[100];
int nEkor;
enum eArah { berhenti = 0, kiri, kanan, atas, bawah};
eArah dir;


void Setel()
{
    buyar = false;
    dir = berhenti;
    x = lebar / 2;
    y = tinggi / 2;
    buahX = rand() % lebar;
    buahY = rand() % tinggi;
    score = 0;
}
void Kotak()
{
    system("cls");
    for (int i = 0; i < lebar+2; i++)
        cout << "=";
    cout << endl;
 
    for (int i = 0; i < tinggi; i++)
    {
        for (int j = 0; j < lebar; j++)
        {
            if (j == 0)
                cout << "=";
            if (i == y && j == x)
                cout << "#";
            else if (i == buahY && j == buahX)
                cout << "B";
            else
            {
                bool print = false;
                for (int k = 0; k < nEkor; k++)
                {
                    if (ekorX[k] == j && ekorY[k] == i)
                    {
                        cout << "#";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == lebar - 1)
                cout << "=";
        }
        cout << endl;
    }
 
    for (int i = 0; i < lebar+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Arah()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = kiri;
            break;
        case 'd':
            dir = kanan;
            break;
        case 'w':
            dir = atas;
            break;
        case 's':
            dir = bawah;
            break;
        case 'x':
            buyar = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = ekorX[0];
    int prevY = ekorY[0];
    int prev2X, prev2Y;
    ekorX[0] = x;
    ekorY[0] = y;
    for (int i = 1; i < nEkor; i++)
    {
        prev2X = ekorX[i];
        prev2Y = ekorY[i];
        ekorX[i] = prevX;
        ekorY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case kiri:
        x--;
        break;
    case kanan:
        x++;
        break;
    case atas:
        y--;
        break;
    case bawah:
        y++;
        break;
    default:
        break;
    }
    if (x >= lebar) x = 0; else if (x < 0) x = lebar - 1;
    if (y >= tinggi) y = 0; else if (y < 0) y = tinggi - 1;
 
    for (int i = 0; i < nEkor; i++)
        if (ekorX[i] == x && ekorY[i] == y)
            buyar = true;
 
    if (x == buahX && y == buahY)
    {
        score += 10;
        buahX = rand() % lebar;
        buahY = rand() % tinggi;
        nEkor++;
    }
}
int main()
{
  cout<<"------------peraturan permaianan--------------"; 
  cout<<"1.Gunakan  WASD sebagai arah ular";
  cout<<"2.Setiap ular terdapat buah sebaga skor permainan";
  
    Setel();
    while (!buyar)
    {
        Kotak();
        Arah();
        Logic();
    }
    return 0;
}