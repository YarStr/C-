#include <iostream>
using namespace std;

int main()
{
    for (int i = 35; i < 88; ++i) {
        int x = i%7;
        if ((x == 1) || (x == 2) || (x == 5)) {
            cout << i << endl;
        }
    }
}
