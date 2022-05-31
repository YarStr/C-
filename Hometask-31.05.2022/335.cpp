#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> digitsInNumber(int number, int k)
{
    vector<int> arr(k);
    for (int i = k - 1; i >= 0 && number > 0; --i, number /= 10)
    {
        arr[i] = number % 10;
    }
    return arr;
}

bool isPrime(int number)
{
    for (int i = 2; i <= sqrt(number); ++i)
        if (number % i == 0)
            return false;
    return true;
}

bool isTripleSimple(vector<int> arr)
{
    bool isTriple = false;
    for (int i = 0; i < arr.size() - 2; ++i)
    {
        string sNumber = "";
        sNumber += to_string(arr[i]);
        sNumber += to_string(arr[i + 1]);
        sNumber += to_string(arr[i + 2]);

        int tempNumber = stoi(sNumber);
        if (tempNumber >= 100 && isPrime(tempNumber))
            isTriple = true;
        else
            return false;
    }
    return isTriple;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    int k = 0;
    for (int numb = pow(10, N - 1); numb < pow(10, N); ++numb)
    {
        vector<int> arr = digitsInNumber(numb, N);
        if (isTripleSimple(arr))
            ++k;
    }

    fout << k;

    return 0;
}
