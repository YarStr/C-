#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k;
    fin >> k;

    int answ = 2 + k % 5 + 7 * (k / 5);

    if (k > 36)
        answ++;

    if (k > 44)
        answ++;

    if (answ == 56 || answ == 63 || answ == 70 || answ == 71)
        answ += 2;

    fout << answ;

    return 0;
}
