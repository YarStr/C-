#include <iostream>
using namespace std;

int main()
{
    int k, L, R, X;
    int arr[255] = { 0 };
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        cin >> L >> R >> X;
        for (L; L <= R; L++) {
            arr[L] += X;
        }
    }
    
    for (int i = 0; i < 255; i++) {
        cout << arr[i];
    }
    
    return 0;
}
