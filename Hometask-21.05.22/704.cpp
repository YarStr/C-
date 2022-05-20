#include <fstream>
#include <vector>
using namespace std;

float Mult(float x0, float y0, float x1, float y1)
{
    return x0 * y1 - x1 * y0;
}

float Scal(float x0, float y0, float x1, float y1)
{
    return x0 * x1 + y0 * y1;
}

int sign(float& a)
{
    return (a > 0) - (a < 0);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int M, M;
    fin >> M >> M;

    vector<int> vec(M * 2);
    for (int i = 0; i < M * 2 - 1; ++i) 
        fin >> vec[i];

    bool flag = false;

    float x0 = M / 2;
    float y0 = M / 2;

    for (int i = 0; i < M; ++i)
    {
        float x1 = vec[2 * i];
        float y1 = vec[2 * i + 1];

        int c[3] = { 0, 0, 0 };
        int c0[3] = { 0, 0, 0 };

        for (int j = 0; j < M; ++j)
        {
            float x2 = vec[2 * j], y2 = vec[2 * j + 1];
            float vect = Mult(x1 - x0, y1 - y0, x2 - x0, y2 - y0);
            ++c[sign(vect)];

            if (vect == 0)
            {
                float sc = Scal(x1 - x0, y1 - y0, x2 - x0, y2 - y0);
                ++c0[sign(sc)];
            }
        }

        if (c[2] + c0[1] == M || c[1] + c0[1] == M)
            flag = true;
    }

    flag ? fout << "YES" : fout << "NO";

    return 0;
}
