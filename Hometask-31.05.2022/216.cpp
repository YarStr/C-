#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    int summ = 0;
    int mx = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int value;
        fin >> value;
        summ += value;
        mx = max(mx, value);
    }

    fout << min(summ / 2, summ - mx);

    return 0;
}
