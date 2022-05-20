#include <fstream>
#include <vector>

using namespace std;

int F(const size_t& K, const size_t& P) {
    if (K < 2)
        return 0;

    vector<size_t> num(K + 1);
    num[2] = 1;

    for (int i = 2; i < K; i++)
    {
        num[i + 1] = (num[i + 1] + num[i]) % P;
        if (2 * i <= K)
            num[2 * i] = num[i];
    }

    return num[K];
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    size_t K, P;
    fin >> K >> P;
    fout << F(K, P);

    return 0;
}
