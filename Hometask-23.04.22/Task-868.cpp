#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int n, m;
    fin >> n >> m;

    int** matr = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matr[i] = new int[m];
        for (int j = 0; j < m; ++j)
            fin >> matr[i][j];
    }

    for (int i = 0; i < m - 1; ++i)
        for (int j = 0; j < n; ++j) 
            if (matr[j][i] < matr[j][i + 1])
                for (int j = 0; j < n; j++)
                    swap(matr[j][i], matr[j][i + 1]);

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            if (matr[i][j] < matr[i + 1][j])
                for (int j = 0; j < m; j++)
                    swap(matr[i][j], matr[i + 1][j]);

    cout << matr[n - 1][m - 1];
}
