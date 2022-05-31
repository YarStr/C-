#include <fstream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, S;
    fin >> N >> S;

    vector<vector<bool>> isFriend(1 + N, vector<bool>(1 + N));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            int v;
            fin >> v;
            isFriend[i][j] = (v == 1);
        }

    vector<bool> visited(1 + N, false);
    int ans = 0;
    function<void(int)>visit = [&](int cur)
    {
        if (visited[cur])
            return;
        visited[cur] = true;
        ans++;
        for (int v = 1; v <= N; ++v)
            if (isFriend[cur][v])
                visit(v);
    };

    visit(S);
    fout << ans - 1;

    return 0;
}
