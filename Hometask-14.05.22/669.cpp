#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int M;
    vector<int> vec(10, 0);

    fin >> M;
    fin.close();

    int temp;
    temp = M;

    for (int i = 9; i > 1; --i)
    {
        vec[i] = 0;
        while (temp % i == 0)
        {
            temp /= i;
            ++vec[i];
        }
    }

    if (temp != 1)
    {
        fout << -1 << " " << -1;
        return 0;
    }

    for (int i = 2; i <= 9; ++i)
    {
        while (vec[i])
        {
            --vec[i];
            fout << i;
        }
    }
    fout << " ";

    temp = M;

    for (int i = 2; i <= 7; ++i)
    {
        while (temp % i == 0)
        {
            temp /= i;
            ++vec[i];
        }
    }

    for (int i = 7; i > 1; --i)
    {
        while (vec[i])
        {
            fout << i;
            --vec[i];
        }
    }

    fout.close();

    return 0;
}
