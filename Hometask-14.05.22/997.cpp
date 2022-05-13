#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check(char c)
{
    string spaces(".,:;-'\"!?\n \t");
    return spaces.find(c) != string::npos;
}

string input(istream& ist) {
    string str;

    while (true)
    {
        if (ist.eof() || ist.bad())
            break;

        auto symbol = ist.peek();
        if (false == check(symbol))
            break;

        ist.get();
    }

    while (true)
    {
        if (ist.eof() || ist.bad())
            break;

        auto symbol = ist.peek();
        if (check(symbol))
            break;

        str.push_back(ist.get());
    }

    return str;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    map <string, int> dict;

    for (int i = 0; i < n; ++i)
        dict.insert(make_pair(input(fin), 0));

    while (true) 
    {
        string str = input(fin);
        if (str.empty())
            break;

        auto temp = dict.find(str);
        if (temp == dict.end())
        {
            fout << "Some words from the text are unknown.";
            return 0;
        }

        dict[str]++;
    }

    for (auto pair : dict) 
        if (pair.second == 0) 
        {
            fout << "The usage of the vocabulary is not perfect.";
            return 0;
        }
 

    fout << "Everything is going to be OK.";
}
