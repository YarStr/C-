#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long long N;
    float M;
    fin >> N >> M;

    float speed = M;
    long long** mas = new long long* [N];

    float Time = 0;
    for (int i = 0; i < N; ++i)
    {
        mas[i] = new long long[3];
        fin >> mas[i][0] >> mas[i][1] >> mas[i][2];
    }

    for (int i = 0; i < N; ++i) {
        Time += mas[i][0] / M;
        if (mas[i][1] < M)
            Time += mas[i][2];
    }

    for (int i = 0; i < N; ++i) {
        float tempTime = 0;
        float tempSpeed = mas[i][1];

        for (int j = 0; j < N; ++j)
        {
            tempTime += mas[j][0] / tempSpeed;
            if (mas[j][1] < tempSpeed)
                tempTime += mas[j][2];
        }

        if (tempTime < Time)
        {
            Time = tempTime;
            speed = tempSpeed;
        }
    }

    fout << speed;

    return 0;
}
