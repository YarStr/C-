#include <iostream>
#include <fstream>

using namespace std;

int fact(int x)
{
    if (x == 0)
        return 1;
    return x * fact(x - 1);
}

int C(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    int answ = 0;
    for (int k = m; k <= n; ++k)
        answ += C(n, k);

    fout << answ;

    return 0;
}
