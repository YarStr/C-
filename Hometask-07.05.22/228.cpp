#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    float usd, eur, dUsd, dEur, sum;
    sum = 100;
    fin >> dUsd >> dEur;

    for (int i = 0; i < N - 1; ++i) {
        fin >> usd >> eur;
        if (dUsd < usd || dEur < eur)
            sum = max(((sum - dUsd * (sum / dUsd)) + (sum / dUsd) * (usd)),
                      ((sum - dEur * (sum / dEur)) + (sum / dEur) * (eur)));

        dUsd = usd;
        dEur = eur;
    }
  
    fout << fixed << setprecision(2) << sum << endl;
  
    return 0;
}
