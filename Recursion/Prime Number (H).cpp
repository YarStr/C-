#include <iostream>
using namespace std;

int isPrimeDef(int n, int d = 2)
{
    if (n < 1) {
        return -1;
    }
    else if (n < 2) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else if (n % d == 0) {
        return 0;
    }
    else if (d * d < n) {
        return isPrimeDef(n, d + 1);
    }
    else {
        return 1;
    }
}

string isPrime()
{
    int x;
    cin >> x;
    x = isPrimeDef(x);

    if (x == 1) {
        return "YES";
    }
    else if (x == 0) {
        return "NO";
    }
    else {
        return "Error! Incorrect input";
    }
}

int main()
{
    cout << isPrime() << endl;
}
