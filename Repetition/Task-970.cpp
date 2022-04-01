#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int idxOfMax(const int mas[])
{
    int Max = INT_MIN;
    int index = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (Max < mas[i])
        {
            Max = mas[i];
            index = i;
        }
    }
    return index;
}

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open())
    {
        cout << "ERROR! File input.txt doesn't exist!";
        return -1;
    }

    int input[3]{};
    fin >> input[0] >> input[1] >> input[2];
    fin.close();

    int index = idxOfMax(input);
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (i != index)
            sum += input[i];
    }

    ofstream fout("output.txt");
    if (sum == input[index])
        fout << "YES";
    else
        fout << "NO";
    fout.close();

    return 0;
}
