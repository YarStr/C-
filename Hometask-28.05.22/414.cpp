#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;

    int a, b;
    fin >> a;
    fin >> b;

    vector <int> vec;
    vector <int> vec1;
    vector <int> vec2;
    vec.push_back(1);
    vec.push_back(1);

    int k;
    for (int i = 1; i < N; ++i)
    {
        fin >> k;
        vec.push_back(k);
    }

    int x = a;
    vec1.push_back(x);
    int y = b;
    vec2.push_back(y);

    while (x != 1)
    {
        x = vec[x];
        vec1.push_back(x);
    }

    while (y != 1)
    {
        y = vec[y];
        vec2.push_back(y);
    }

    x = a;
    y = b;

    while (x != y)
    {
        if (vec2.size() > vec1.size())
            vec2.erase(vec2.begin());

        else
            vec1.erase(vec1.begin());

        x = vec1[0];
        y = vec2[0];
    }

    fout << x << endl;

    return 0;
}
