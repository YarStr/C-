#include <iostream>
#include <vector>
#include<string>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> vec;
	
	int num = 2;
	int count = 0;
	int temp;
	for (int i = 1; i <= N; ++i)
		vec.push_back(i);

	while (vec.size() > 1) {
		temp = 1;
		for (int i = 1; i <= vec.size(); ++i) {
			if (temp % 2 == 0 && vec[i - 1] == M)
			{
				cout << num << endl;
				count = 1;
				break;
			}

			else if (temp % 2 == 0)
			{
				vec.erase(vec.begin() + (i - 1));
				++num;
				++i;
			}
			++temp;
		}

		if (count == 1)
		{
			break;
		}
	}

	if (vec.size() == 1)
	{
		cout << N << endl;
	}
}
