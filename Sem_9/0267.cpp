#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n, x, y, min1, max1;
    double k, v1, v2;
  
    cin >> n >> x >> y;
  
    min1 = min(x, y);
    max1 = max(x, y);
  
    v1 = 1. / min1;
    v2 = 1. / max1;
  
    if (n > 1) {
        k = min1 + (n - 1) / (v1 + v2) + 1;
        cout << (int)k << endl;
    }
    else {
        cout << min1 << endl;
    }
}
