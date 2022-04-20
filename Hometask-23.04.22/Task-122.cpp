#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    int N;
    fin >> N;

    int* values = new int[N];
    int* lens = new int[N]();

    for (int i = 0; i < N; ++i)
        fin >> values[i];

    fin.close();
   
    int maxLen = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
            if (values[i] > values[j] && lens[j] > lens[i])
                lens[i] = lens[j];
        ++lens[i];
        maxLen = max(maxLen, lens[i]);
    }
    
    cout << maxLen << endl;

    delete[] values;
    delete[] lens;
    return 0;
}
