#include <iostream>
using namespace std;

int main()
{
    for (int i = 10; i <= 99; ++i)
    {
        if ((i % 4 == 0) && (i % 6 != 0))
            cout << i << endl;
    }
}
