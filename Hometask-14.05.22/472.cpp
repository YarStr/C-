#include <fstream>
#include <set>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int N, M;
    fin >> N >> M;
    
    multiset<int> mSet;
    for (int i = 0; i < N; ++i)
    {
        int temp;
        fin >> temp;
        mSet.insert(temp);
    }
    
    while (M > 0)
    {
        int temp = *mSet.begin() + 1;
        mSet.erase(mSet.begin());
        --M;
        mSet.insert(temp);
    }
    
    fout << *mSet.begin() << endl;

    return 0;
}
