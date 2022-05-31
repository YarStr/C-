#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, k;
    int a[150][150];
    int b[150][150];

    fin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            fin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            b[i][j] = b[i - 1][j] + b[i][j - 1] + a[i][j] - b[i - 1][j - 1];

    for (int i = 1; i <= k; ++i)
    {
        int x, y, x1, y1;
        fin >> x >> y >> x1 >> y1;

        if (x > x1)
            swap(x, x1);

        if (y > y1)
            swap(y, y1);

        fout << b[x1][y1] + b[x - 1][y - 1] - b[x - 1][y1] - b[x1][y - 1];
    }
}
