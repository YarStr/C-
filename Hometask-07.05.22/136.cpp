#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    int** mas = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        mas[i] = new int[N];
        for (int j = 0; j < N; ++j)
            fin >> mas[i][j];
    }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j && mas[i][k] != -1 && mas[k][j] != -1)
                {
                    if (mas[i][j] == -1)
                        mas[i][j] = mas[i][k] + mas[k][j];
                    else
                        mas[i][j] = min(mas[i][j], mas[i][k] + mas[k][j]);
                }
                    
    int answ = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (answ < mas[i][j])
                answ = mas[i][j];
    
    fout << answ;

    return 0;
}
