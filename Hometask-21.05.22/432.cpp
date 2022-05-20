#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

const char check = '#';
const char uncheck = '.';
vector<string> mas;
int N, M;

struct point
{
    int x, y;

    point() {}

    point(int X, int Y)
    {
        x = X;
        y = Y;
    }

};

int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, -1, 0, 1 };

bool correct(int x, int y)
{
    if (x < 0 || y < 0)
        return false;
    if (x >= N || y >= M)
        return false;

    return true;
}

void dfs(int fx, int fy)
{
    stack<point> s;
    s.push(point(fx, fy));

    while (!s.empty())
    {
        point cur = s.top();
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];

            if (correct(x, y) && mas[x][y] == check)
            {
                mas[x][y] = uncheck;
                s.push(point(x, y));
            }
        }
    }
}

void solve(ofstream& fout)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mas[i][j] == check)
            {
                dfs(i, j);
                k++;
            }
        }
    }

    fout << k;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> N >> M;
    mas.resize(N);

    for (int i = 0; i < N; i++)
        fin >> mas[i];
    solve(fout);

    return 0;
}
