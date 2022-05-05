#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
    while (a && b)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;
    
    int a = N / 2;
    int b = N - a;

    while (gcd(a, b) != 1)
    {
        --a;
        ++b;
    }
 
    fout << a << " " << b << endl;

    return 0;
}
