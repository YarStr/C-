#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
  
    int N;
    fin >> N;
  
    long long Max = pow(3, n / 3);
    if (N % 3 == 1)
        Max = Max * 4 / 3;
    if (N % 3 == 2)
        Max = Max * 2;
 
    fout << Max;
}
