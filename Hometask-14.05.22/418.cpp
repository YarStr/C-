#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int curr = 0;
    int mx = 0;

    string N;
    getline(fin, N);
    fin.close();

    vector<int> vec;
    vec.push_back(0);

    for (char i : N) {
        if (i == '<')
        {
            if (vec[curr] > 0)
                vec[curr]--;

            else if (curr > 0)
                vec.erase(vec.begin() + curr--);
        }

        else if (i == '^')
        {
            if (curr > 0)
                curr--;
        }

        else if (i == '|')
        {
            if (curr + 1 < vec.size())
                ++curr;
        }

        else if (i == '\\')
        {
            vec.push_back(0);
            ++curr;
        }

        else
        {
            vec[curr]++;
        }

        mx = max(mx, vec[curr]);
    }

    cout << mx;
    fout.close();

    return 0;
}
