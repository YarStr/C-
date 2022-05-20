#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n, m, k;
	fin >> n >> m >> k;

	int i, j;
	vector<vector<int>> vec(n, vector<int>(m, 0));
	for (int l = 0; l < k; ++l)
	{
		fin >> i >> j;
		vec[i][j] = -1;
	}

	int count = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 1; k < m; ++k)
		{
			if ((vec[i - 1][j] == count
				|| vec[i][j - 1] == count
				|| vec[i + 1][j] == count
				|| vec[i][j + 1] == count) && vec[i][j] == 0)vec[i][j] = count;

			else if (vec[i][j] == 0) 
				vec[i][j] = ++count;
		}

	fout << count << endl;

	return 0;
}
