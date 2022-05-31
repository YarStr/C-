#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string a, b;
    fin >> a >> b;

    int minLen = (int)a.size() + (int)b.size();

    for (int bPos = -(int)b.size(); bPos <= (int)a.size(); ++bPos)
    {
        int first = min(bPos, 0);
        int last = max(bPos + (int)b.size() - 1, (int)a.size() - 1);
        bool isOK = true;

        for (int i = first; i <= last; ++i)
        {
            int aTemp;

            if (0 <= i && i < (int)a.size())
                aTemp = a[i] - '0';
            else
                aTemp = 1;

            int bTemp;
            if (bPos <= i && i < bPos + (int)b.size())
                bTemp = b[i - bPos] - '0';
            else
                bTemp = 1;

            if (aTemp + bTemp > 3)
            {
                isOK = false;
                break;
            }
        }

        if (isOK)
        {
            int len = last - first + 1;
            if (len < minLen)
                minLen = len;
        }
    }

    fout << minLen;

    return 0;
}
