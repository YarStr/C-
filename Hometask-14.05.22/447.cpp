#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    long long answ = 1;
    for (int i = 2; i <= N; ++i)
    {
        answ = answ * i;
        while (answ % 10 == 0)
            answ /= 10;
        answ %= 1000000;
    }

    fout << answ % 10 << endl;
    
    return 0;
}
