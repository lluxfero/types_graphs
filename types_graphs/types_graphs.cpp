#include <iostream>
#include <Windows.h>
#include <clocale>
using namespace std;

int err_n() {
    int m, ival = 1;
    cin >> m;
    while (ival == 1) {
        if (cin.fail() || m < 1) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
            cin >> m;
        }
        else
            ival = 0;
    }
    return m;
}

int err_d() {
    int m, ival = 1;
    cin >> m;
    while (ival == 1) {
        if (cin.fail() || m < 0 || m > 1) {

            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
            cin >> m;
        }
        else
            ival = 0;
    }
    return m;
}

void show_desk(int** d, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void adjacency_vectors(int** d, int n) {
    int s, maxs = 0;
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++)
            if (d[i][j] == 1) s++;
        if (maxs < s) maxs = s;
    }

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

    show_desk(av, n, maxs);
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество вершин дерева: ";
    n = err_n();

    int** desk = new int* [n];
    for (int i = 0; i < n; i++)
        desk[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            desk[i][j] = 0;

    cout << "Введите матрицу смежности: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            desk[i][j] = err_d();
    cout << endl;

    cout << "Векторы смежности: " << endl;;
    adjacency_vectors(desk, n);

}