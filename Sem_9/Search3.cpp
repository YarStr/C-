#include <iostream>
using namespace std;

int main()
{
    const int n = 3;
    int lens[n] = { 3, 8, 3 };

    //Сортировка массива длин по убыванию
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (lens[j] < lens[j + 1]) {
                swap(lens[j], lens[j + 1]);
            }
        }
    }

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
    
    int Max1 = sum_lens / k;
    int min = max(lens[n - 1] / k, 1);

    int range[255] = {};

    for (int i = 0; i < Max1 - min + 1; ++i) {
        range[i] = min + i;
    }

    Max1 = Max1 - min;
    min = 0;

    int check_k = 0;
    while (min < Max1)
    {
        int middle = (Max1 + min) / 2;

        check_k = 0;

        for (int i = 0; i < n; ++i) {
            check_k += lens[i] / range[middle];
        }

        if (k > check_k)
            Max1 = middle;

        if (k == check_k)
            min = middle;

        if (k < check_k)
            min = middle + 1;

        if (k == check_k && Max1-min==1)
            Max1 = middle;

        cout << check_k << endl;
    }

    cout << range[Max1] << endl;
    return 0;
}
