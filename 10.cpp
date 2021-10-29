#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    for (int i = 1; i <= 50; ++i)
    {
        if ((i % 5 == 0) || (i % 7 == 0))
            num += i;
    }
    cout << num << endl;
}
