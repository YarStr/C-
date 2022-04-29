#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int k;
	cin >> k;

	vector<int> nums;
	for (int i = 0; i < k; ++i)
		cin >> nums[i];

	int max = 0;
	for (int i = 0; i < k - 1; ++i) {
		int n = nums[i];
		int sum = 1;
		int count = 0;
		for (int m = i + 1; m < k; ++m)
		{
			if (n < nums[m] && count != 1) 
			{
				count = 1;
				n = nums[m];
				sum++;
			}
			else if (n > nums[m] && count != -1)
			{
				count = -1;
				n = nums[m];
				sum++;
			}
			else
			{
				if (sum > max)
				{
					max = sum;
					sum = 1;
				}
			}
		}

		if (sum > max) 
			max = sum;
		
	}
	cout << max << endl;
}
