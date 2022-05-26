#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    int b = N / 3;

    N = N % 3;
    if (N == 1)
    {
        --b;
        N += 3;
    }

    int a = N / 2;

    if (a > 0)
        fout << 2 << ' ' << a << ' ';

    if (b > 0)
        fout << 3 << ' ' << b;

    return 0;
}
