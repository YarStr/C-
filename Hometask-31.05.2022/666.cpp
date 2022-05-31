#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int pos;
    fin >> pos;

    for (int step = 26; step >= 1; --step)
    {
        int half = (1 << (step - 1)) - 1;
        if (pos == 1)
        {
            fout << (char)('a' + step - 1);
            return 0;
        }
        else if (pos <= 1 + half)
            pos--;
        else
            pos -= 1 + half;
    }

    throw 1;
}
