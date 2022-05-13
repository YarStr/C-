#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    int** mas = new int* [N+1];
    mas[0] = new int[N+1] {0};

    for (int i = 1; i <= N; ++i)
    {
        mas[i] = new int[N+1];
        for (int j = 1; j <= N; ++j)
            fin >> mas[i][j];
    }

    fin.close();

    int** mx = new int* [N+1];
    mx[0] = new int[N+1] {0};

    for (int i = 1; i <= N; ++i)
    {
        mx[i] = new int[N+1]{INT_MIN};
        for (int j = 0; j <= N; ++j)
        {
            mx[i][j] = mx[i - 1][j];
            for (int k = 1; k <= j; ++k)
            {
                mx[i][j] = max(mx[i][j], mas[k][i] + mx[i - 1][j - k]);
            }
        }
    }

    fout << mx[N][N];
    fout.close();

    return 0;
}
