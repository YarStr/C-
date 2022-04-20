#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int N, x, y;
    fin >> N >> x >> y;

    if (x > y)
        swap(x, y);

    int R;
    R = (N - 1) * y;
    int L = 0;

    int now;
    while (L != R)
    {
        now = (L + R) / 2;
        y = now / x + now / y;
        if (y < N - 1)
            L = now + 1;
        else
            R = now;
    }

    cout << R + x;
    return 0;
}
