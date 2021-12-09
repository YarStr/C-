#include <iostream>
using namespace std;
/*Rec1. Возвести число в натуральную степень P за Θ(logP). Рекурсивный и нерекурсивный варианты*/

//нерекурсивный метод
int pow(int x, int p) {
    int x1 = 1;
    int ans = x;
    if (p == 0) {
        return 1;
    }
    if (p % 2 != 0) {
        p--;
        x1 = x;
    }
    for (int i = 1; i < p/2; ++i) {
        ans = x;
    }
    return ansans*x1;
}
//рекурсивный метод
int rec_pow(int x, int p) {
    int deg;
    if (p == 0) {
        return 1;
    }
    if (p % 2 != 0) {
        return x * rec_pow(x, p - 1);
    }
    deg = rec_pow(x, p / 2);
    return deg*deg;
}

int main()
{
    int p;
    cin >> p;
    int x = 2;
    cout << pow(x, p) << endl;
    cout << rec_pow(x, p) << endl;
}
