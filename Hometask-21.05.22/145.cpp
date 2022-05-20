#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A; int B;
    cin >> A >> B;

    int c = 0;
    long long t = 0;
    bool flag = 0;

    while (c < A.length())
    {
        while (t < B && c < A.length())
        {
            t = t * 10 + A[c] - '0';
            if (t < B && flag) cout << 0;
            ++c;
        }

        if (t < B and !flag)
        {
            cout << 0;
            return 0;
        }

        flag = 1;

        if (t >= B)
            cout << t / B;

        t %= B;
    }

    return 0;
}
