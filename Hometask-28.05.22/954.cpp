#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int height;
    fin >> height;

    vector<int> k (height + 1, 0);
    k[0] = 1;
    int MOD = 1000000;

    for (int h = 1; h <= height; ++h)
    {
        if (h >= 10)
            k[h] += k[h - 10];

        if (h >= 11)
            k[h] += k[h - 11];

        if (h >= 12)
            k[h] += k[h - 12];

        k[h] %= MOD;
    }

    fout << k[height] * 2 % MOD;

    return 0;
}
