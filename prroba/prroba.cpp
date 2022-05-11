#include <iostream>
#include <Windows.h>
#include <clocale>
using namespace std;

void show_desk(int** d, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 7;
    int d[7][7] = { {0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 1, 0, 0},
                    {0, 1, 1, 0, 0, 1, 0},
                    {0, 0, 0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0} };
    int s, maxs = 0;
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++)
            if (d[i][j] == 1) s++;
        if (maxs < s) maxs = s;
    }
    
    cout << maxs << endl;

    int** av = new int* [n];
    for (int i = 0; i < n; i++)
        av[i] = new int[maxs];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < maxs; j++)
            av[i][j] = 0;

    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++)
            if (d[i][j] == 1) {
                av[i][s] = j + 1;
                s++;
            }
    }

    cout << "Векторы смежности: " << endl;
    show_desk(av, n, maxs);
}