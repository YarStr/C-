#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    size_t nAB, nBC, nAC;
    int n;
    fin >> n >> nAB >> nBC >> nAC;

    vector <size_t> vec(6, 0);
    size_t temp = min(min(nAB, nBC), nAC) / 2;

    for (int i = 0; i < 6; i += 2)
        vec[i] = temp;

    nAB -= temp * 2;
    nBC -= temp * 2;
    nAC -= temp * 2;
    n -= temp * 3;
    n -= nAB + nBC + nAC;

    vec[1] = nAB;
    vec[3] = nBC;
    vec[5] = nAC;

    if (nAB == 0 && nBC == 0 && nAC == 0 && n == 0)
    {
        fout << "YES" << endl;

        for (auto c : vec)
            fout << c << " ";

        return 0;
    }

    fout << "NO";

    return 0;
}
