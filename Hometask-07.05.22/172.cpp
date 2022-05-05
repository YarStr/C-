#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string N; long K;
    fin >> N >> K;
    
    int i = 0;
    string answ = "";

    while (i < size(N))
    {
        answ += N[i++];
        long temp = stoi(answ);
        if (temp >= K)
        {
            temp = temp % K;
            answ = to_string(temp);
        }
    }
    fout << stoi(answ);
 
    return 0;
}
