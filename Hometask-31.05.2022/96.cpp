#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, x, y;
    fin >> n >> m >> y >> x;

    int k = 1;
    int pos1 = 1;
    int pos2 = 1;

    if (n == 1 && n == m)
    {
        fout << 1;
        return 0;
    }

    vector<vector<int>> vec(n, vector<int>(m));
    while (true)
    {
        while (pos2 < m)
        {
            ++pos2;
            ++k;

            if (pos1 == y && pos2 == x)
            {
                fout << k;
                return 0;
            }
        }

        while (pos1 < n)
        {
            ++pos1;
            ++k;

            if (pos1 == y && pos2 == x)
            {
                fout << k;
                return 0;
            }
        }

        while (pos2 != 1)
        {
            --pos2;
            ++k;

            if (pos1 == y && pos2 == x)
            {
                fout << k;
                return 0;
            }
        }
        --n;
        --m;

        for (int i = 1; i < n; ++i)
        {
            --pos1;
            ++k;

            if (pos1 == y && pos2 == x)
            {
                fout << k;
                return 0;
            }
        }
    }
}
