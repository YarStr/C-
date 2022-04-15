#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "ERROR! File input.txt doesn't exist!" << endl;
        return -1;
    }

    long long n;
    fin >> n;
    long long pos = (n * n + 1) / 2;
    cout << (pos - 1) / 9 * 10 + (pos - 1) % 9 + 1 << endl;
    
    return 0;
}
