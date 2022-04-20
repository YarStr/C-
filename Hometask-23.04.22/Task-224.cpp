#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ifstream fin("input.txt");
    long long N;
    fin >> N;

    vector<long long> vec(N);
    for (int i = 0; i < N; ++i)
        fin >> vec[i];

    fin.close();

    sort(vec.begin(), vec.end());
    long long m1, m2;
    m1 = vec[N - 1] * vec[N - 2] * vec[N - 3];
    m2 = vec[N - 1] * vec[0] * vec[1];

    cout << max(m1, m2);

    return 0;
}
