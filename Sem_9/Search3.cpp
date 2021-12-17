#include <iostream>
using namespace std;

int main()
{
    const int n = 3;
    int lens[n] = { 8, 3, 3 };

    int k;
    cin >> k;

    int sum_lens = 0;
    for (int i = 0; i < n; ++i) {
        sum_lens += lens[i];
    }
    
    if (k > sum_lens){
        cout << 0 << endl;
        return 0;
    }
    
    int Max = sum_lens / k;
    int Min = 1;

    int range[255] = {};

    for (int i = 0; i < Max - Min + 1; ++i) {
        range[i] = Min + i;
    }

    int right = Max - Min;
    int left = 0;

    int check_k = 0;
    while (left < right)
    {
        int middle = (right + left) / 2;

        check_k = 0;

        for (int i = 0; i < n; ++i) {
            check_k += lens[i] / range[middle];
        }

        if (k > check_k)
            right = middle - 1;

        if (k == check_k)
            left = middle;

        if (k < check_k)
            left = middle + 1;
    }

    cout << range[right] << endl;
    return 0;
}
