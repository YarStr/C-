#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void print(ofstream& fout, const vector <long long>& vec)
{
    for (auto c : vec)
        fout << c << " ";
    fout << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char c;
    long long n, t = 1, r = 0;

    fin >> c >> n;

    vector <long long> L, R;
    while (n > 0)
    {
        r = n % 3;
        if (r == 2)
        {
            L.push_back(t);
            n += 3;
        }

        else if (r == 1)
            R.push_back(t);

        t *= 3;
        n /= 3;
    }

    if (c == 'L')
    {
        fout << "L:";
        print(fout, L);

        fout << "R:";
        print(fout, R);
    }

    else
    {
        fout << "L:";
        print(fout, R);

        fout << "R:";
        print(fout, L);
    }

    return 0;
}
