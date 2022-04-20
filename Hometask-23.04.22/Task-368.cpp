#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream fin("input.txt");
    int N;
    fin >> N;

    int** field = new int* [N];

	for (int i = 0; i < N; ++i)
	{
		field[i] = new int[N];
		fin.get();
		for (int j = 0; j < N; ++j)
			field[i][j] = fin.get() - 48;
	}

	fin.close();

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (j > 0 && i > 0)
				field[i][j] += min(field[i - 1][j], field[i][j - 1]);

			else if (i == 0 && j > 0)
				field[i][j] += field[i][j - 1];

			else if (i > 0 && j == 0)
				field[i][j] += field[i - 1][j];

	char** answ = new char* [N];
	for (int i = 0; i < N; ++i)
	{
		answ[i] = new char[N];
		for (int j = 0; j < N; ++j)
			answ[i][j] = '.';
	}

	int x, y; 
	x = y = N - 1;
	answ[N - 1][N - 1] = '#';
	while (!(x == 0 && y == 0))
	{
		if (x == 0) --y;

		else if (y == 0) --x;

		else if (field[x - 1][y] < field[x][y - 1]) --x;
		
		else --y;

		answ[x][y] = '#';
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << answ[i][j];
		cout << endl;
	}

    return 0;
}
