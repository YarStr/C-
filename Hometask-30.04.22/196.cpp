#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");

    int N;
    fin >> N;

    int numb = 0;
    int** mas = new int* [N];

    for (int i = 0; i < N; ++i)
        mas[i] = new int[N];

    int stop;
    if (N % 2 == 0)
        stop = N / 2;
    else
        stop = N / 2 + 1;

    for (int i = 0; i < stop; i++)
    {
        for (int j = i; j < N - i; j++)
            mas[i][j] = ++numb;

        for (int j = i + 1; j < N - i; j++)
            mas[j][N - i - 1] = ++numb;

        for (int j = i + 1; j < N - i; j++)
            mas[N - i - 1][N - j - 1] = ++numb;

        for (int j = i + 1; j < N - i - 1; j++)
            mas[N - j - 1][i] = ++numb;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mas[i][j] << " ";
        cout << endl;
    }

    return 0;
}
