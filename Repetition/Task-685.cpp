#include <iostream>
#include <fstream>

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

    int prices[3]{};
    int buckets[3]{};

    for (int i = 0; i < 3; ++i)
        fin >> prices[i];
    for (int i = 0; i < 3; ++i)
        fin >> buckets[i];

    fin.close();

    
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        int idxPrices = idxOfMax(prices);
        int idxBuckets = idxOfMax(buckets);     
        sum += prices[idxPrices] * buckets[idxBuckets];

        prices[idxPrices] = 0;
        buckets[idxBuckets] = 0;
    }

    ofstream fout("output.txt");
    fout << sum;
    fout.close();

    return 0;
}
