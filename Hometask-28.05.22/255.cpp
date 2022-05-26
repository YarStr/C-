#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N;
	int i = 1;
	fin >> N;

	for (int j = 2; i <= sqrt(N); ++j)
	{
		if (N % j == 0)
		{
			for (; i <= sqrt(N); ++i)
				if (N % i == 0)
					break;

			fout << N / i << ' ' << N - (N / i);
			return 0;
		}
	}

	fout << 1 << ' ' << N - 1;
	return 0;
}
