#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int K, M;
    cin >> K >> M;

    vector<pair<int, int>> vec;
    for (int i = 0; i < M; ++i)
    {
        int p, h;
        cin >> p >> h;
        vec.push_back(make_pair(h, p));
    }
    sort(vec.begin(), vec.end());

    for (int i = vec.size() - 1; i >= 0; --i)
    {
        if (vec[i].second == K) 
            K++;
        else if (vec[i].second + 1 == K)
            K--;
    }

    cout << K << endl;
}
