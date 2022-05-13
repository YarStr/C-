#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
 
using namespace std;
 
bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0)
            return false;
    return true;
}
 
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
 
    int k;
    fin >> k;
 
    int num = 2;
    int ord = 0;
    int count = 1;
 
    while (ord != k)
    {
        ++num;
        if (isPrime(num) == true)
        {
            ++count;
            if (isPrime(count))
                ++ord;
        }
    }
 
    fout << num;
 
    return 0;
}
