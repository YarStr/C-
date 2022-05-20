#include <fstream>
#include <algorithm>

using namespace std;

bool EucAlg(long long a, long long b, long long c, long long d)
{
    if (a == c && b == d)
        return true;

    while (b != 0) {
        if (b > a)
        {
            swap(a, b);
            if (a == c && b == d)
                return true;
        }

        if (b > 0)
        {
            long long nSub = a / b;
            long long oldA = a;
            a -= nSub * b;
            long long newA = a;
            if (b == d && newA <= c && c <= oldA && (oldA - c) % b == 0)
                return true;
        }
    }

    return false;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k;
    long long a, b, c, d;
    fin >> k;

    for (int i = 0; i < k; ++i)
    {
        fin >> a >> b >> c >> d;
        if (EucAlg(a, b, c, d))
            fout << "YES" << endl;
        else
            fout << "NO" << endl;
    }
  
    return 0;
}
