#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    if (N == 1 || N == 2 || N == 3 || N == 6)
    {
        fout << -1;
        return 0;
    }

    if (N == 4)
    {
        fout << 2 << "\n" << 1 << "\n" << 0 << "\n" << 1;
        return 0;
    }

    if (N == 5)
    {
        fout << 1 << "\n" << 2 << "\n" << 0 << "\n" << 0 << "\n" << 2;
        return 0;
    }

    vector<int> a(N + 1);
    a[1] = 2; a[2] = 1; a[N - 4] = 1; a[N] = N - 4;

    for (int i = 1; i < a.size(); ++i)
        fout << a[i] << endl;

    return 0;
}
