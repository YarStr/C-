#include <limits>
#include <iostream>
using namespace std;

int main()
{
    int N = 10;
    int* mas = new int[N];

    int maxSum = -pow(10, 9),
        sum = 0,
        prefSum = pow(10, 9);
    
    int a, b, prefB;

    for (int i = 0; i < N; ++i)
    {
        sum += mas[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            a = 0;
            b = i;
        }

        int sum1 = sum - prefSum;
        if (sum1 > maxSum)
        {
            maxSum = sum1;
            a = prefB;
            b = i;
        }

        if (sum < prefSum)
        {
            prefSum = sum;
            prefB = i;
        }

    }
   
    cout << maxSum - 1;
}
