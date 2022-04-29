#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;
	for (int i = 0; i <= size(S) - size(T); ++i)
	{
		int count = 0;
		for (int j = 0; j < size(T); ++j)
		{
			if (S[i + j] == T[j])
				count++;
			else
				break;
		}
		if (count == size(T))
			cout << i << endl;
	}
}
