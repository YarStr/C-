#include <fstream>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int mX, mY, n;
    double r;
    fin >> mX >> mY >> r >> n;

    vector <Point> p;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        fin >> x >> y;
        x -= mX;
        y -= mY;
        if (sqrt(x * x + y * y) <= r)
            p.push_back(Point{ x,y });
    }

    int answ = 0;
    for (Point p1 : p)
    {
        int on = 0;
        int left = 0;
        int right = 0;

        for (Point p2 : p)
        {
            int cp = p1.x * p2.y - p2.x * p1.y;
            if (cp < 0)
                ++left;
            else if (cp > 0)
                ++right;
            else
                ++on;
        }

        answ = max(max(answ, on + left), on + right);
    }

    fout << answ;

    return 0;
}
